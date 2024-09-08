#include "square_root.h"

int square_root(int n){
	//Candidate for square root starts at 1
	int r = 1;

	//if our candidate r does not equan n when squared, get new candidate using heron's formula
	while(r*r != n){
		int candidate = (r + n/r)/2;
		//if we get the same candidate and it is still not right, heron's formula is not sufficient for n
		if(candidate == r){
			return -1;
		}
		r = candidate;
	}
	return r;
}

