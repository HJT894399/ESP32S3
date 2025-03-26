#include "i2c0.h"

esp_err_t i2c0_init(void)
{
    i2c_config_t i2c_configstruct = {
        .clk_flags = 0,
        .master.clk_speed = 200000,
        .mode = I2C_MODE_MASTER,
        .scl_io_num = IIC_SCL_PIN,
        .sda_io_num = IIC_SDA_PIN,
        .scl_pullup_en = true,
        .sda_pullup_en = true,
    };

    // 用 i2c0
    if (i2c_param_config(I2C_NUM_0, &i2c_configstruct) != ESP_OK)
    {
        printf("i2c init fail\n");
        return ESP_FAIL;
    }

    if (i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0) != ESP_OK)
    {
        printf("i2c install fail\n");
        return ESP_FAIL;
    }

    return ESP_OK;
}

esp_err_t i2c0_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint16_t len)
{
    i2c_cmd_handle_t i2c_cmd = i2c_cmd_link_create();
    if (i2c_master_start(i2c_cmd) == ESP_FAIL)
        return ESP_FAIL;

    if (i2c_master_write_byte(i2c_cmd, (dev_addr << 1 | 0x00), true) == ESP_FAIL)
        return ESP_FAIL;

    if (i2c_master_write_byte(i2c_cmd, reg_addr, true) == ESP_FAIL)
        return ESP_FAIL;

    for (int i = 0; i < len; i++)
    {
        if (i2c_master_write_byte(i2c_cmd, data[i], true) == ESP_FAIL)
            return ESP_FAIL;
    }
    if (i2c_master_stop(i2c_cmd) == ESP_FAIL)
        return ESP_FAIL;

    if (i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, portMAX_DELAY) == ESP_FAIL)
        return ESP_FAIL;

    i2c_cmd_link_delete(i2c_cmd);

    return ESP_OK;
}

esp_err_t i2c0_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint16_t len)
{
    i2c_cmd_handle_t i2c_cmd = i2c_cmd_link_create();
    if (i2c_master_start(i2c_cmd) == ESP_FAIL)
        return ESP_FAIL;
    if (i2c_master_write_byte(i2c_cmd, (dev_addr << 1 | 0x00), true) == ESP_FAIL)
        return ESP_FAIL;
    if (i2c_master_write_byte(i2c_cmd, reg_addr, true) == ESP_FAIL)
        return ESP_FAIL;
    if (i2c_master_start(i2c_cmd) == ESP_FAIL)
        return ESP_FAIL;
    if (i2c_master_write_byte(i2c_cmd, (dev_addr << 1 | 0x01), true) == ESP_FAIL)
        return ESP_FAIL;
    for (int i = 0; i < len; i++)
    {
        if (i2c_master_read_byte(i2c_cmd, data[i], I2C_MASTER_NACK) == ESP_FAIL)
            return ESP_FAIL;
    }
    if (i2c_master_stop(i2c_cmd) == ESP_FAIL)
        return ESP_FAIL;

    if (i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, portMAX_DELAY) == ESP_FAIL)
        return ESP_FAIL;

    i2c_cmd_link_delete(i2c_cmd);

    return ESP_OK;
}