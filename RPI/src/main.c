#include "stdio.h"
#include "unistd.h"
#include "buffer.h"
#include "i2c_device.h"

int main();

int main() {
	Buffer send_buffer = Buffer_init(2);
	send_buffer.data[0] = 0b11010010;
	send_buffer.data[1] = 0b01101001;

	I2CDevice i2c_device = I2CDevice_init(1, 0b1001101);
	while (1) {
		I2CDevice_write(&i2c_device, send_buffer);
		// usleep(1000*500);
	}

	return 0;
}