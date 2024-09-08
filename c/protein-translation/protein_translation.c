#include "protein_translation.h"

proteins_t proteins(const char *const rna){
	//initialize everything
	proteins_t proteins;
	proteins.count = 0;
	proteins.valid = true;

	//while the array isn't over jump by 3s
	for(int i = 0; rna[i] != '\0'; i = i+3){
		//if there aren't 3 chars to check, it is not valid.
		if(rna[i+1] == '\0' || rna[i+2] == '\0'){
			proteins.valid = false;
			break;
		}
		//create a buffer to write the 3 characters into
		char *s = malloc(4*sizeof(char));
		s[3] = '\0';
		//write the character (plus terminator) into buffer
		snprintf(s,4,"%s%s%s",&rna[i],&rna[i+1],&rna[i+2]);
		//Check if any sequences match; Iterate the count; set the protein to the matching name; free the buffer; go to next iteration;
		if(strcmp(s,"AUG") == 0){
				proteins.proteins[proteins.count++] = Methionine;
				free(s);
				continue;
		}else if(strcmp(s, "UUU") == 0 || strcmp(s, "UUC") == 0){
			proteins.proteins[proteins.count++] = Phenylalanine;
				free(s);
				continue;
		}else if(strcmp(s, "UUA") == 0 || strcmp(s, "UUG") == 0){
			proteins.proteins[proteins.count++] = Leucine;
				free(s);
				continue;
		}else if(strcmp(s,"UCU") == 0 || strcmp(s,"UCC") == 0 || strcmp(s,"UCA") == 0 || strcmp(s,"UCG") == 0){
		proteins.proteins[proteins.count++] = Serine;
				free(s);
				continue;
		}else if(strcmp(s, "UAU") == 0 || strcmp(s, "UAC") == 0){
			proteins.proteins[proteins.count++] = Tyrosine;
				free(s);
				continue;
		}else if(strcmp(s, "UGU") == 0 || strcmp(s, "UGC") == 0){
			proteins.proteins[proteins.count++] = Cysteine;
				free(s);
				continue;
		}else if(strcmp(s, "UGG") == 0 ){
			proteins.proteins[proteins.count++] = Tryptophan;
				free(s);
				continue;
		}else if(strcmp(s,"UAA") == 0 || strcmp(s,"UAG") == 0 || strcmp(s,"UGA") == 0){
			//if the squence stops, free the buffere and stop looking
				free(s);
			break;
		}else{
			//if no match is found, no matter how far in, the sequence becomes invalid
			free(s);
			proteins.valid = false;
			break;
		}
	}
	return proteins;
}
