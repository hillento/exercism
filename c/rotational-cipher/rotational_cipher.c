#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key){
	//a = 97
		
	int l = 0;
	while(text[l] != '\0'){
		l++;
	}
	
	char *rtext = calloc(l+1, 1);
	for(int i = 0; i < l; i++){
		if(  text[i] >= 'a' && text[i] <= 'z'){
			int n = text[i] + shift_key;
			if(n > 'z'){
				n -= 26;
			}
			rtext[i] = n;
		}else if(text[i]>= 'A' && text[i]<= 'Z'){
			int n = text[i] + shift_key;
			if(n > 'Z'){
				n -= 26;
			}
			rtext[i] = n;
		}else{
			rtext[i] = text[i];
		}
	}
	return rtext;
}
