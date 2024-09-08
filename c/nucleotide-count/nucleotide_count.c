#include "nucleotide_count.h"

char *count(const char *dna_strand){
	
	char *counts = malloc(27);

	int a=0,c=0,g=0,t=0, l=0;
	while(dna_strand[l] != '\0'){
		l++;
	}
	
	for(int i = 0; i < l; i++){
		switch (dna_strand[i]) {
		case 'A':
			a++;
			break;
		case 'C':
			c++;
			break;
		case 'G':
			g++;
			break;
		case 'T':
			t++;
			break;
		default:
			counts[0]='\0';
			return counts;
		}
	}
	snprintf(counts,27,"A:%d C:%d G:%d T:%d",a,c,g,t);
	return counts;
}
