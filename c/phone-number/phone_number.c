#include "phone_number.h"

char *phone_number_clean(const char *input){
	//iterate input and add any digit to array, store length in j
	char* number = calloc(12, sizeof(char));
	int i = 0;
	int j = 0;
	while(input[i] != '\0'){
		if(isdigit(input[i])){
			number[j++] = input[i];
		}
		i++;
	}
	//return 0s if incompatible length
	if( j < 10 || j > 11){
		strcpy(number, "0000000000");
		return number;
	}
	//if there are 11 digits...
	if(j == 11){
		//if any digits are invalid return 0s, else shift all the digits down by 1
		if(number[0] != '1' || number[1] < '2' || number[4] < '2'){
			strcpy(number, "0000000000");
			return number;
		}else{
			for(int k = 0; k < j; k++){
				number[k] = number[k+1];
			}
		}
	}
	//if the length is 10
	if(j == 10 && (number[0] < '2' || number[3] < '2')){
		strcpy(number, "0000000000");
		return number;
	}
	return number;
}
