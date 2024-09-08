#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size){
	time_t gs = input + 1000000000;
	struct tm *return_time;
	return_time = gmtime(&gs);
	strftime(output, size, "%Y-%m-%d %H:%M:%S", return_time);
}
