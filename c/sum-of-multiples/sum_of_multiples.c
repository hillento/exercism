#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit){
	int sum = 0;
	for(unsigned int i = 0; i < limit; i++)
	{
		for(unsigned int j = 0; j < number_of_factors; j++)
		{
			if(factors[j] && i % factors[j] == 0)
			{
				sum += i;
				j = number_of_factors;
			}
		}
	}
	return sum;
}
