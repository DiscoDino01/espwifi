#include "SSD1306_t.hpp"

SSD1306_t::SSD1306_t(ssd1306_conf_t config) {
	this->config = config;
}

int SSD1306_t::command(uint8_t cmd) {
	return ssd1306_command(&this->config, cmd);
}

int SSD1306_t::init() {
	return ssd1306_init(&this->config);
}

int SSD1306_t::load_xbm(uint8_t* xbm, uint8_t* fb) {
	return ssd1306_load_xbm(&this->config, xbm, fb);
}

int SSD1306_t::load_frame_buffer(uint8_t buf[]) {
	return ssd1306_load_frame_buffer(&this->config, buf);
}

inline
int SSD1306_t::clear_screen() {
	return ssd1306_clear_screen(&this->config);
}

int SSD1306_t::display_on(bool on) {
	return ssd1306_display_on(&this->config, on);
}

int SSD1306_t::set_display_start_line(uint8_t start) {
	return ssd1306_set_display_start_line(&this->config, start);
}

int SSD1306_t::set_display_offset(uint8_t offset) {
	return ssd1306_set_display_offset(&this->config, offset);
}

#ifdef SH1106_SUPPORT
int SSD1306_t::set_charge_pump_voltage(sh1106_voltage_t select) {
	return sh1106_set_charge_pump_voltage(&this->config, select);
}
#endif

int SSD1306_t::set_charge_pump_enabled(bool enabled) {
	return ssd1306_set_charge_pump_enabled(&this->config, enabled);
}

int SSD1306_t::set_mem_addr_mode(ssd1306_mem_addr_mode_t mode) {
	return ssd1306_set_mem_addr_mode(&this->config, mode);
}

int SSD1306_t::set_segment_remapping_enabled(bool on) {
	return ssd1306_set_segment_remapping_enabled(&this->config, on);
}

int SSD1306_t::set_scan_direction_fwd(bool fwd) {
	return ssd1306_set_scan_direction_fwd(&this->config, fwd);
}

int SSD1306_t::set_com_pin_hw_config(uint8_t config) {
	return ssd1306_set_com_pin_hw_config(&this->config, config);
}

int SSD1306_t::set_contrast(uint8_t contrast) {
	return ssd1306_set_contrast(&this->config, contrast);
}

int SSD1306_t::set_inversion(bool on) {
	return ssd1306_set_inversion(&this->config, on);
}

int SSD1306_t::set_osc_freq(uint8_t osc_freq) {
	return ssd1306_set_osc_freq(&this->config, osc_freq);
}

int SSD1306_t::set_mux_ratio(uint8_t ratio) {
	return ssd1306_set_mux_ratio(&this->config, ratio);
}

int SSD1306_t::set_column_addr(uint8_t start, uint8_t stop) {
	return ssd1306_set_column_addr(&this->config, start, stop);
}

int SSD1306_t::set_page_addr(uint8_t start, uint8_t stop) {
	return ssd1306_set_page_addr(&this->config, start, stop);
}

int SSD1306_t::set_precharge_period(uint8_t prchrg) {
	return ssd1306_set_precharge_period(&this->config, prchrg);
}

int SSD1306_t::set_deseltct_lvl(uint8_t lvl) {
	return ssd1306_set_deseltct_lvl(&this->config, lvl);
}

int SSD1306_t::set_whole_display_lighting(bool light) {
	return ssd1306_set_whole_display_lighting(&this->config, light);
}

int SSD1306_t::draw_pixel(uint8_t* fb, int8_t x, int8_t y, ssd1306_color_t color) {
	return ssd1306_draw_pixel(&this->config, fb, x, y, color);
}

int SSD1306_t::draw_hline(uint8_t* fb, int8_t x, int8_t y, uint8_t w, ssd1306_color_t color) {
	return ssd1306_draw_hline(&this->config, fb, x, y, w, color);
}

int SSD1306_t::draw_vline(uint8_t* fb, int8_t x, int8_t y, uint8_t h, ssd1306_color_t color) {
	return ssd1306_draw_vline(&this->config, fb, x, y, h, color);
}

int SSD1306_t::draw_line(uint8_t* fb, int16_t x0, int16_t y0, int16_t x1, int16_t y1, ssd1306_color_t color) {
	return ssd1306_draw_line(&this->config, fb, x0, y0, x1, y1, color);
}

int SSD1306_t::draw_rectangle(uint8_t* fb, int8_t x, int8_t y, uint8_t w, uint8_t h, ssd1306_color_t color) {
	return ssd1306_draw_rectangle(&this->config, fb, x, y, w, h, color);
}

int SSD1306_t::fill_rectangle(uint8_t* fb, int8_t x, int8_t y, uint8_t w, uint8_t h, ssd1306_color_t color) {
	return ssd1306_fill_rectangle(&this->config, fb, x, y, w, h, color);
}

int SSD1306_t::draw_circle(uint8_t* fb, int8_t x0, int8_t y0, uint8_t r, ssd1306_color_t color) {
	return ssd1306_draw_circle(&this->config, fb, x0, y0, r, color);
}

int SSD1306_t::fill_circle(uint8_t* fb, int8_t x0, int8_t y0, uint8_t r, ssd1306_color_t color) {
	return ssd1306_fill_circle(&this->config, fb, x0, y0, r, color);
}

int SSD1306_t::draw_triangle(uint8_t* fb, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, ssd1306_color_t color) {
	return ssd1306_draw_triangle(&this->config, fb, x0, y0, x1, y1, x2, y2, color);
}

int SSD1306_t::fill_triangle(uint8_t* fb, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, ssd1306_color_t color) {
	return ssd1306_fill_triangle(&this->config, fb, x0, y0, x1, y1, x2, y2, color);
}

int SSD1306_t::draw_char(uint8_t* fb, const font_info_t* font, uint8_t x, uint8_t y, char c, ssd1306_color_t foreground, ssd1306_color_t background) {
	return ssd1306_draw_char(&this->config, fb, font, x, y, c, foreground, background);
}

int SSD1306_t::draw_string(uint8_t* fb, const font_info_t* font, uint8_t x, uint8_t y, const char* str, ssd1306_color_t foreground, ssd1306_color_t background) {
	return ssd1306_draw_string(&this->config, fb, font, x, y, str, foreground, background);
}

int SSD1306_t::stop_scroll() {
	return ssd1306_stop_scroll(&this->config);
}

int SSD1306_t::start_scroll_hori(bool way, uint8_t start, uint8_t stop, ssd1306_scroll_t frame) {
	return ssd1306_start_scroll_hori(&this->config, way, start, stop, frame);
}

int SSD1306_t::start_scroll_hori_vert(bool way, uint8_t start, uint8_t stop, uint8_t dy, ssd1306_scroll_t frame) {
	return ssd1306_start_scroll_hori_vert(&this->config, way, start, stop, dy, frame);
}