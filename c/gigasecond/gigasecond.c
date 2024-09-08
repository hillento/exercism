#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size)
{
	//time_t before = construct_date(2011, 4, 25, 0, 0, 0);
	const int gs = 1000000000;
	const unsigned d_M[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	};
	
   
	
	
	

}

static inline size_t is_leap_year(int year)
{
   if (year % 400 == 0)
      return 1;
   if (year % 100 == 0)
      return 0;
   if (year % 4 == 0)
      return 1;
   return 0;
}
