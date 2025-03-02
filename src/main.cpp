#include "FreeRTOS.h"

#include <stdlib.h>
#include <driver/uart.h>
#include <i2c.h>
#include <string.h>
#include "rom/gpio.h"
#include "driver/gpio.h"
#include <esp_types.h>
#include <esp_wifi.h>
#include <cJSON.h>

#define FONTS_TERMINUS_8X14_ISO8859_1
#include "ssd1306.h"

#define MAX_CLIENTS 1

#define WAIT(millisec) vTaskDelay( millisec / portTICK_PERIOD_MS )
#define LOOP for(;;)

extern "C" {
	int app_main(void);
}


struct ConnectionInfo {
	unsigned int code, remaining_sec;
};
ConnectionInfo* list_of_connections[MAX_CLIENTS] = { nullptr };


const char* wifi_ssid = "TrashVendoWifi-01";
//const char* wifi_password = "no password needed!";


/**
 * @brief Generates 4 digit decimal number
 * @return `uint32_t result`
 */
int generate_code() {
	return esp_random() % 10000u;
}

void i2c_init() {
	i2c_config_t conf = {
		I2C_MODE_MASTER,
		GPIO_NUM_4,
		GPIO_PULLUP_ENABLE,
		GPIO_NUM_5,
		GPIO_PULLUP_ENABLE,
		400000
	};
	i2c_param_config(I2C_NUM_0, &conf);
	i2c_driver_install(I2C_NUM_0, conf.mode);
}


void handle_client_request();
void handle_uart_request();
void handle_input_trash_countdown(int = 15);
void oled_test(void*);

namespace OLED_SSD1306 {
	constexpr const uint8_t oled_width = 32;
	constexpr const uint8_t oled_height = 128;
	const ssd1306_color_t foreground = OLED_COLOR_WHITE;
	const ssd1306_color_t background = OLED_COLOR_BLACK;

	ssd1306_t oled = { I2C_NUM_0, 0x3C, SSD1306_SCREEN, oled_height, oled_width };
	uint8_t oled_frame_buffer[oled_width * oled_height / 8]; // divided by 8 because its a `uint8_t`
	const font_info_t* font_terminus_8x14 = font_builtin_fonts[font_face_t::FONT_FACE_TERMINUS_8X14_ISO8859_1];

	constexpr const uint8_t grid_col_size = 8;
	constexpr const uint8_t grid_row_size = 16;
	uint8_t cursor_grid_pos_col = 0,
		cursor_grid_pos_row = 0;

	int32_t init() {

		int32_t init_status = ssd1306_init(&oled);
		if (init_status == 0) {
			ssd1306_display_on(&oled, 1);
			ssd1306_clear_screen(&oled);
		}

		return init_status;
	}

	void update() {
		ssd1306_load_frame_buffer(&oled, oled_frame_buffer);
	}

	inline void set_grid_cursor(uint8_t c, uint8_t r) {
		cursor_grid_pos_col = c;
		cursor_grid_pos_row = r;
	}

	void draw_string(const char* str) {
		ssd1306_draw_string(&oled, oled_frame_buffer, font_terminus_8x14,
			grid_col_size * cursor_grid_pos_col, grid_row_size * cursor_grid_pos_row + 1, // + 1 because top-margin:1px
			str, foreground, background);

		update();
	}

	void draw_char(char character) {
		ssd1306_draw_char(&oled, oled_frame_buffer, font_terminus_8x14,
			grid_col_size * cursor_grid_pos_col, grid_row_size * cursor_grid_pos_row + 1,
			character, foreground, background);

		update();
	}

	void clear() {
		ssd1306_clear_screen(&oled);
		// update();
	}

} // namespace OLED_SSD1306

int app_main() {
	i2c_init();

	gpio_pad_select_gpio(GPIO_NUM_2);  // Select GPIO function
	gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);  // Set as OUTPUT

	xTaskCreate(&oled_test, "oled test", 4096, NULL, 5, NULL);

	LOOP{
		WAIT(1000);
		handle_input_trash_countdown();
	}

	return 0;
}

void oled_test(void*) {
	if (OLED_SSD1306::init() != 0) {
		WAIT(3000);
	}

	OLED_SSD1306::set_grid_cursor(0, 0);
	OLED_SSD1306::draw_string("Hello world!");
}

void handle_input_trash_countdown(int remaining_sec /* = 15 */) {
	using namespace OLED_SSD1306; // i hate this

	clear();
	set_grid_cursor(0, 0);
	draw_string("Remaining Time:");
	set_grid_cursor(0, 1);

	{
		char msg[4] = "00s";
		for (int8_t rem = remaining_sec; rem >= 0; rem--) {
			msg[0] = static_cast<char>((rem / 10) + '0');
			msg[1] = static_cast<char>((rem % 10) + '0');
			draw_string(msg);

			WAIT(1000);

			ssd1306_draw_rectangle(&oled, oled_frame_buffer, 0, 16, 128, 16, OLED_COLOR_BLACK); // clear a part of the screen
			update();
		}
	}

	clear();
}