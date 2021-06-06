#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/ioctl.h"
#include "linux/i2c-dev.h"

#include "i2c_device.h"

I2CDevice I2CDevice_init(uint8_t i2c_port, uint16_t addr) {
	char i2c_base_filename[] = "/dev/i2c-%d";
	char i2c_filename[20];
	sprintf(i2c_filename, i2c_base_filename, i2c_port);

	I2CDevice i2c_device = {};
	i2c_device._i2c_file = open(i2c_filename, O_RDWR);		// open i2c file
	if (i2c_device._i2c_file < 0) {
		fprintf(stderr, "Error: failed to open I2C device...\n");
		exit(1);
	}
	ioctl(i2c_device._i2c_file, I2C_SLAVE, addr);			// change addr of device

	return i2c_device;
}

uint8_t I2CDevice_write(I2CDevice* self, Buffer send_buffer) {
	if (write(self->_i2c_file, send_buffer.data, send_buffer.len) != send_buffer.len) {
		fprintf(stderr, "Error: failed to write to I2C device...\n");
		return 1;
	}
	else { return 0; }
}



