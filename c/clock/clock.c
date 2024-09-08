#include "clock.h"

clock_t clock_create(int hour, int minute){
	clock_t clock;
	hour += minute/60;
	minute %= 60;

	if(minute < 0){
		hour -=1;
		minute += 60;
	}
	if(hour <0){
		hour += 24;
	}
	sprintf(clock.text,"%02u:%02u",hour,minute);
	return clock;

}
clock_t clock_add(clock_t clock, int minute_add){
	int hour;
	int minute;
	sscanf(clock.text, "%d:%d", &hour, &minute);
	minute += minute_add;
	return clock_create(hour, minute);
}
clock_t clock_subtract(clock_t clock, int minute_subtract){
	return clock_add(clock, -minute_subtract);
}
bool clock_is_equal(clock_t a, clock_t b){
	return a.text == b.text;
}
