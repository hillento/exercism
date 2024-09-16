#include "all_your_base.h"

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base, int8_t input_length){
	//If the base is invalid return 0 as ERROR
	if(input_base < 2 || output_base < 2 || input_length < 1){
		return 0;
	}

	//Convert input digits into base 10.
	uint16_t decimal = 0;
	//Iterate starting from the righ side of the number to make ocnversion easier
	for(int i = 0; i < input_length; i++){
		//n stores the current value
		int n = digits[input_length - 1 - i];
		if(n >= input_base || n < 0) return 0;
		decimal += n * pow(input_base,i);
	}

	//find number of digits. Add 1 for terminator
	size_t out_size = 1;
	while(pow(output_base, out_size) < decimal){
		out_size++;
	}
	

	//make output number
	for(int j = out_size-1; j >= 0; j--){
		digits[j] = decimal % output_base;
		decimal /= output_base;
	}
	return out_size;
}
