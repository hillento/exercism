#include "circular_buffer.h"

circular_buffer_t* new_circular_buffer(size_t capacity){

	circular_buffer_t* buffer = malloc(sizeof(circular_buffer_t));
	buffer->capacity = capacity;
	buffer->data = malloc(capacity * sizeof(buffer_value_t));
	buffer->head = 0;
	buffer->tail = 0;
	buffer->filled = 0;
	return buffer;
}
void clear_buffer(circular_buffer_t* buffer){
	buffer->filled = 0;
	buffer->head = 0;
	buffer->tail = 0;
}
void delete_buffer(circular_buffer_t* buffer){
	free(buffer->data);
	free(buffer);
}

unsigned int write(circular_buffer_t* buffer, buffer_value_t value){
	if(buffer->filled){
		errno = ENOBUFS;
		return EXIT_FAILURE;
	}

	buffer->data[buffer->head] = value;
	buffer->head = (buffer->head + 1) % buffer->capacity;
	if(buffer->tail == buffer->head){
		buffer->filled = 1;
	};
	return EXIT_SUCCESS;
}
unsigned int overwrite(circular_buffer_t* buffer, buffer_value_t value){
	if(!buffer->filled){
		return write(buffer, value);
	}
	buffer->data[buffer->head] = value;
	buffer->head = (buffer->head + 1) % buffer->capacity;
	buffer->tail = (buffer->tail + 1) % buffer->capacity;
	return EXIT_SUCCESS;
	
}
unsigned int read(circular_buffer_t* buffer, buffer_value_t* value){

	if(buffer->tail == buffer->head && (!buffer->filled)){
		errno = ENODATA;
		return EXIT_FAILURE;
	}
	*value = buffer->data[buffer->tail];
	buffer->tail = (buffer->tail + 1) % buffer->capacity;
	buffer->filled = 0;
	return EXIT_SUCCESS;
}

