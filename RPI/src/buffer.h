#ifndef __BUFFER
#define __BUFFER

#include "stdint.h"

typedef struct {
	uint8_t* data;
	uint8_t len;
} Buffer;

Buffer Buffer_init(uint8_t len);
void Buffer_deinit(Buffer* self);


#endif
