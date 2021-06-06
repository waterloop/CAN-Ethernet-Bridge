#ifndef __I2C_DRIVER
#define __I2C_DRIVER

#include "stdint.h"
#include "buffer.h"

typedef struct {
	int _i2c_file;
} I2CDevice;

I2CDevice I2CDevice_init(uint8_t i2c_port, uint16_t addr);

uint8_t I2CDevice_write(I2CDevice* self, Buffer send_buffer);
uint8_t I2CDevice_read(I2CDevice* self, Buffer read_buffer);

#endif
