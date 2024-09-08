#include "sieve.h"


uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
	uint32_t pc = 0;

	if( limit < 2) return pc;

	bool is_prime[limit+1];
	for(unsigned i = 0; i < limit+1; i++){
		is_prime[i] = true;
	}

	for( unsigned i = 2; i <= limit; i++){
		if(is_prime[i]){ 
			primes[pc] = i;
			pc++;
			if(pc >= max_primes) break;
			for(unsigned j = 2; i*j <= limit; j++){
				is_prime[i*j] = false;
			}
		}	
	}
	return pc;
}
