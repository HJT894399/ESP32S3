#ifndef __I2C0_H
#define __I2C0_H
#include "driver/i2c.h"

#define IIC_SCL_PIN 42
#define IIC_SDA_PIN 41

esp_err_t i2c0_init(void);
esp_err_t i2c0_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint16_t len);
esp_err_t i2c0_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint16_t len);

#endif