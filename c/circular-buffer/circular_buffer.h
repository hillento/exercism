#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

typedef int buffer_value_t;

typedef struct{
	int filled;
	unsigned int capacity;
	unsigned int head;
	unsigned int tail;
	buffer_value_t* data;
}circular_buffer_t;

circular_buffer_t* new_circular_buffer(size_t n);
void clear_buffer(circular_buffer_t* buffer);
void delete_buffer(circular_buffer_t* buffer);
unsigned int write(circular_buffer_t* buffer, buffer_value_t value);
unsigned int overwrite(circular_buffer_t* buffer, buffer_value_t value);
unsigned int read(circular_buffer_t* buffer, buffer_value_t* value);


#endif
