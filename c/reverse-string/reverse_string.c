#include "reverse_string.h"

char *reverse(const char *value){
	//initialize the length of l at 0
	unsigned int l = 0;
	//get the length of the array (without the null terminator)
	while(value[l] != '\0'){
		l++;
	}
	//create the pointer and assigned is length to l+1 (must include terminator for memcheck)
	char *ptr;
	ptr = malloc((l+1)*sizeof(char));
	//for each available spot of ptr, take the last character - the currect position in ptr. 
	for(unsigned int i = 0; i < l; i++ ){
		ptr[i] = value[l-1-i];
	}
	//add the terminator
	ptr[l] = '\0';
	return ptr;
}
