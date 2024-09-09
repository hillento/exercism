#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){
	//To store the number of factors found
	size_t count = 0;
	//i starts at 2 as the first candidate for a prime factor
	for(size_t i = 2; n >= i; i++){
		//because we can repeate factors, just take the factor as many times as it can be used
		while(n % i == 0){
			//add the candidate to factors array and then add 1 to the count
			factors[count++] = i;
			//reduce n by dividing by the prime factor
			n /= i;
		}
	}
	return count;
}
