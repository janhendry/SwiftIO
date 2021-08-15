#import "include/swift_adc.h"
#import "include/swift_counter.h"
#import "include/swift_fs.h"
#import "include/swift_gpio.h"
#import "include/swift_i2c.h"
#import "include/swift_i2s.h"
#import "include/swift_lcd.h"
#import "include/swift_platform.h"
#import "include/swift_pwm.h"
#import "include/swift_spi.h"
#import "include/swift_timer.h"
#import "include/swift_uart.h"
#import "include/swift_wifi.h"


//adc
void *swifthal_adc_open(int id){}
int swifthal_adc_close(void *adc){}
int swifthal_adc_read(void *adc){}
int swifthal_adc_info_get(void *adc, swift_adc_info_t *info){}
int swifthal_adc_dev_number_get(void){}


//counter
void *swifthal_counter_open(int id){}
int swifthal_counter_close(void *counter){}
int swifthal_counter_read(void *counter){}
int swifthal_counter_start(void *counter, swift_counter_mode_t mode){}
int swifthal_counter_stop(void *counter){}
int swifthal_counter_clear(void *counter){}
int swifthal_counter_info_get(void *counter, swift_counter_info_t *info){}
int swifthal_counter_dev_number_get(void){}

//fs
char *swifthal_mount_point_get(void){}
void *swifthal_fs_open(const char *path, unsigned char flags){}
int swifthal_fs_close(void *fp){}
int swifthal_fs_remove(const char *path){}
int swifthal_fs_rename(const char *from, char *to){}
int swifthal_fs_write(void *fp, const void *buf, unsigned int size){}
int swifthal_fs_read(void *fp, void *buf, unsigned int size){}
int swifthal_fs_seek(void *fp, int offset, int whence){}
int swifthal_fs_tell(void *fp){}
int swifthal_fs_truncate(void *fp, unsigned int length){}
int swifthal_fs_sync(void *fp){}
int swifthal_fs_mkdir(const char *path){}
void *swifthal_fs_opendir(const char *path){}
int swifthal_fs_readdir(void *dp, swift_fs_dirent_t *entry){}
int swifthal_fs_closedir(void *dp){}
int swifthal_fs_stat(const char *path, swift_fs_dirent_t *entry){}
int swifthal_fs_statfs(const char *path, swift_fs_statvfs_t *stat){}

//gpio
void *swifthal_gpio_open(int id, swift_gpio_direction_t direction, swift_gpio_mode_t io_mode){}
int swifthal_gpio_close(void *gpio){}
int swifthal_gpio_config(void *gpio, swift_gpio_direction_t direction, swift_gpio_mode_t io_mode){}
int swifthal_gpio_set(void *gpio, int level){}
int swifthal_gpio_get(void *gpio){}
int swifthal_gpio_interrupt_config(void *gpio, swift_gpio_int_mode_t int_mode){}
int swifthal_gpio_interrupt_callback_install(void *gpio, void *param, void (*callback)(void *)){}
int swifthal_gpio_interrupt_callback_uninstall(void *gpio){}
int swifthal_gpio_interrupt_enable(void *gpio){}
int swifthal_gpio_interrupt_disable(void *gpio){}
int swifthal_gpio_dev_number_get(void){}

//i2c
void *swifthal_i2c_open(int id){}
int swifthal_i2c_close(void *i2c){}
int swifthal_i2c_config(void *i2c, unsigned int speed){}
int swifthal_i2c_write(void *i2c, unsigned char address, const unsigned char *buf, int length){}
int swifthal_i2c_read(void *i2c, unsigned char address, unsigned char *buf, int length){}
int swifthal_i2c_write_read(void *i2c, unsigned char addr, const void *write_buf, int num_write, void *read_buf, int num_read){}
int swifthal_i2c_dev_number_get(void){}

//i2s
//void *swifthal_i2s_open(int id, const swift_i2s_cfg_t *tx_cfg, const swift_i2s_cfg_t *rx_cfg){}
void *swifthal_i2s_open(int id){}
int swifthal_i2s_close(void *i2s){}
int swifthal_i2s_tx_available_get(void *i2s){}
int swifthal_i2s_rx_available_get(void *i2s){}
int swifthal_i2s_config_set(void *i2s, const swift_i2s_cfg_t *tx_cfg, const swift_i2s_cfg_t *rx_cfg){}
int swifthal_i2s_config_get(void *i2s, swift_i2s_cfg_t *tx_cfg, swift_i2s_cfg_t *rx_cfg){}
int swifthal_i2s_write(void *i2s, const unsigned char *buf, int length, int timeout){}
int swifthal_i2s_write_terminate(void *i2s){}
int swifthal_i2s_read(void *i2s, unsigned char *buf, int length, int timeout){}
int swifthal_i2s_dev_number_get(void){}


//ldc
void *swifthal_lcd_open(const swift_lcd_panel_param_t *param){}
int swifthal_lcd_close(void *lcd){}
int swifthal_lcd_start(void *lcd, void *buf, unsigned int size){}
int swifthal_lcd_stop(void *lcd){}
int swifthal_lcd_fb_update(void *lcd, void *buf, unsigned int size){}
int swifthal_lcd_screen_param_get(void *lcd, int *width, int *height, swift_lcd_pixel_format_t *format,int *bpp){}
int swifthal_lcd_refresh_rate_get(void *lcd){}


//platform
void swifthal_ms_sleep(int ms){}
void swifthal_us_wait(unsigned int us){}
long long swifthal_uptime_get(void){}
unsigned int swifthal_hwcycle_get(void){}
unsigned int swifthal_hwcycle_to_ns(unsigned int cycles){}
void swiftHal_randomGet(unsigned char *buf, int length){}


//pwm
void *swifthal_pwm_open(int id){}
int swifthal_pwm_close(void *pwm){}
int swifthal_pwm_set(void *pwm, int period, int pulse){}
int swifthal_pwm_suspend(void *pwm){}
int swifthal_pwm_resume(void *pwm){}
int swifthal_pwm_info_get(void *pwm, swift_pwm_info_t *info){}
int swifthal_pwm_dev_number_get(void){}


//spi
void *swifthal_spi_open(int id, int speed, void (*w_notify)(void *), void (*r_notify)(void *)){}
int swifthal_spi_close(void *spi){}
int swifthal_spi_config(void *spi, int speed){}
int swifthal_spi_write(void *spi, const unsigned char *buf, int length){}
int swifthal_spi_read(void *spi, unsigned char *buf, int length){}
int swifthal_spi_async_write(void *spi, const unsigned char *buf, int length){}
int swifthal_spi_async_read(void *spi, unsigned char *buf, int length){}
int swifthal_spi_dev_number_get(void){}

//timer
void *swifthal_timer_open(){}
int swifthal_timer_close(void *timer){}
int swifthal_timer_start(void *timer, swift_timer_type_t type, int period){}
int swifthal_timer_stop(void *timer){}
int swifthal_timer_add_callback(void *timer, void *param, void (*callback)(void *)){}
unsigned int swifthal_timer_status_get(void *timer){}


//uart
void *swifthal_uart_open(int id, const swift_uart_cfg_t *cfg){}
int swifthal_uart_close(void *uart){}
int swifthal_uart_baudrate_set(void *uart, int baudrate){}
int swifthal_uart_parity_set(void *uart, swift_uart_parity_t parity){}
int swifthal_uart_stop_bits_set(void *uart, swift_uart_stop_bits_t stop_bits){}
int swifthal_swift_uart_data_bits_set(void *uart, swift_uart_stop_bits_t data_bits){}
int swifthal_uart_config_get(void *uart, swift_uart_cfg_t *cfg){}
int swifthal_uart_char_put(void *uart, unsigned char c){}
int swifthal_uart_char_get(void *uart, unsigned char *c, int timeout){}
int swifthal_uart_write(void *uart, const unsigned char *buf, int length){}
int swifthal_uart_read(void *uart, unsigned char *buf, int length, int timeout){}
int swifthal_uart_remainder_get(void *uart){}
int swifthal_uart_buffer_clear(void *uart){}
int swift_wifi_scan(swift_wifi_scan_result_t *results, int num){}
int swift_wifi_connect(char *ssid, int ssid_length, char *psk, int psk_length){}
int swift_wifi_disconnect(void){}
int swift_wifi_ap_mode_set(int enable, char *ssid, int ssid_length, char *psk, int psk_length){}
int swift_wifi_status_get(swift_wifi_status_t *status){}

