#pragma once

#include <stdint.h>
#include "ssd1306.h"
using ssd1306_conf_t = ssd1306_t;

class SSD1306_t {
public:
	SSD1306_t(ssd1306_conf_t);
	~SSD1306_t() = default;

	ssd1306_conf_t config;

	/// `ssd1306_command()`
	int command();

	/// `ssd1306_init()`
	int init();

	/// `ssd1306_load_xbm()`
	int load_xbm();

	/// `ssd1306_load_frame_buffer()`
	int load_frame_buffer();

	/// `ssd1306_clear_screen()`
	int clear_screen();

	/// `ssd1306_display_on()`
	int display_on();

	/// `ssd1306_set_display_start_line()`
	int set_display_start_line();

	/// `ssd1306_set_display_offset()`
	int set_display_offset();

#ifdef SH1106_SUPPORT
	/// `sh1106_set_charge_pump_voltage()`
	int sh1106_set_charge_pump_voltage();
#endif

	/// `ssd1306_set_charge_pump_enabled()`
	int set_charge_pump_enabled();

	/// `ssd1306_set_mem_addr_mode()`
	int set_mem_addr_mode();

	/// `ssd1306_set_segment_remapping_enabled()`
	int set_segment_remapping_enabled();

	/// `ssd1306_set_scan_direction_fwd()`
	int set_scan_direction_fwd();

	/// `ssd1306_set_com_pin_hw_config()`
	int set_com_pin_hw_config();

	/// `ssd1306_set_contrast()`
	int set_contrast();

	/// `ssd1306_set_inversion()`
	int set_inversion();

	/// `ssd1306_set_osc_freq()`
	int set_osc_freq();

	/// `ssd1306_set_mux_ratio()`
	int set_mux_ratio();

	/// `ssd1306_set_column_addr()`
	int set_column_addr();

	/// `ssd1306_set_page_addr()`
	int set_page_addr();

	/// `ssd1306_set_precharge_period()`
	int set_precharge_period();

	/// `ssd1306_set_deseltct_lvl()`
	int set_deseltct_lvl();

	/// `ssd1306_set_whole_display_lighting()`
	int set_whole_display_lighting();

	/// `ssd1306_draw_pixel()`
	int draw_pixel();

	/// `ssd1306_draw_hline()`
	int draw_hline();

	/// `ssd1306_draw_vline()`
	int draw_vline();

	/// `ssd1306_draw_line()`
	int draw_line();

	/// `ssd1306_draw_rectangle()`
	int draw_rectangle();

	/// `ssd1306_fill_rectangle()`
	int fill_rectangle();

	/// `ssd1306_draw_circle()`
	int draw_circle();

	/// `ssd1306_fill_circle()`
	int fill_circle();

	/// `ssd1306_draw_triangle()`
	int draw_triangle();

	/// `ssd1306_fill_triangle()`
	int fill_triangle();

	/// `ssd1306_draw_char()`
	int draw_char();

	/// `ssd1306_draw_string()`
	int draw_string();

	/// `ssd1306_stop_scroll()`
	int stop_scroll();

	/// `ssd1306_start_scroll_hori()`
	int start_scroll_hori();

	/// `ssd1306_start_scroll_hori_vert()`
	int start_scroll_hori_vert();

};