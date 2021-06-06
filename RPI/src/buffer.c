#include "stdint.h"
#include "stdlib.h"
#include "buffer.h"

Buffer Buffer_init(uint8_t len) {
	Buffer ret = {};
	ret.data = malloc(sizeof(uint8_t)*len);
	ret.len = len;
	return ret;
}
void Buffer_deinit(Buffer* self) { free(self->data); }
