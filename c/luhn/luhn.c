#include "luhn.h"
bool luhn(const char *num){

	//final sum, length of array, cound of digits
	int sum = 0, l = 0, c = 0;
	//set to determine if digit should be doubled
	bool dbl_flg = false;
	
	//Gets the length of the string without the string library
	while(num[l] != '\0'){
		l++;
	}
		
	//If the length of the array is less than 2, don't event test
	if(l < 2) return false;
	
	for(int i = l - 1; i >= 0; i--)
	{
		//Itterate loop if character is white space
		if(num[i] == ' ') continue;
		//Only consider characters 0-9
		if(num[i] <= '9' && num[i] >= '0'){
			//Add 1 to count of digits
			c++;
			if(!dbl_flg){
				sum += num[i] - '0';
				dbl_flg = true;
			} else if(dbl_flg){
				int s1 = (num[i] - '0') *2;
				dbl_flg = false;
				if(s1 > 9){
					sum += (s1-9);
				}else{
					sum+= s1;
				}
			}
		}else{
			return false;
		}
	}
	return (sum % 10 == 0) && c >= 2;
}
