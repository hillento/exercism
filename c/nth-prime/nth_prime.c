#include "nth_prime.h"

uint32_t nth(uint32_t n){
	//There is no 0th prime so fail if it is requested	
	if(n < 1) return 0;

	//Set up a count and limit. 999,999 is completely arbitrary and can be adjusted based on need
	uint32_t count = 0;
	uint32_t limit = 999999;

	//make an array of true for sieve method. Mark as false if index is a multiple of a prime
	bool is_prime[limit+1];
	for(unsigned i = 0; i < limit +1; i++){
		is_prime[i] = true;
	}

	//check if the is_prime index is true. If it is then it is a prime, add 1 to the count, mark multiples as not true, and if the count reaches n, return prime (i)
	for( unsigned i = 2; i <= limit; i++){
		if(is_prime[i]){
			count++;
			if(count >= n) return i;
			for(unsigned j = 2; i*j <= limit; j++){
				is_prime[i*j] = false;
			}
		}	
	}
	return 0;
}
