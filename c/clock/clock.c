#include "clock.h"

clock_t clock_create(int hour, int minute){
	//1 hour is 60 minutes. Returns hour many hours can be taken from the minutes
	hour += minute/60;
	//How many minutes are left after taking hours out
	minute %= 60;
	//If there are negative minutes, add an hour to it (-3 becomes 57 minutes) and take an hour out
	if(minute < 0){
		minute += 60;
		hour -= 1;
	}
	//Clocks only go to 23:59 before resetting so 28 needs to be 04:00
	hour %= 24;
	//Same as minutes, -3 hours becomes 21
	if(hour < 0){
		hour += 24;
	}
	clock_t clock;
	//write to the clock.text, 2 unsigned numbers. The array will be 6 bytes ( 2 character per num + colon + null terminator)
	snprintf(clock.text, 6, "%02u:%02u", hour, minute);
	return clock;
}
clock_t clock_add(clock_t clock, int minute_add){
	//initialize
	int minute, hour;
	//scan the string and take the 2 numbers out
	sscanf(clock.text,"%d:%d", &hour,&minute);
	//add the minutes to the minutes of the original clock and send it to the create so it will roll over as needed
	minute += minute_add;	
	return clock_create(hour, minute);

}
clock_t clock_subtract(clock_t clock, int minute_subtract){
	//addition is the opposite of subtraction so send negative minutes to the addition function
	return clock_add(clock, -minute_subtract);
}
bool clock_is_equal(clock_t a, clock_t b){
	//Once clocks a and b are create their strings should be identical so strcmp should be 0 if they are the same
	return strcmp(a.text, b.text) == 0;
}
