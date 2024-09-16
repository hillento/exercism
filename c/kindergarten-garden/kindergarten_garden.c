#include "kindergarten_garden.h"

//move switch to it's own function to save a step
int char_to_enum(char c){
	switch (c){
		case 'C':
			return CLOVER;
		case 'G':
			return GRASS;
		case 'R':
			return RADISHES;
		case 'V':
			return VIOLETS;
		default:
			return -1;
	}
}

plants_t plants(const char *plants, const char *student){
	//initialize the return variable
	plants_t r;
	//Get the length of the plants array so the halfway can be tracked for the 3rd and 4th plant
	int l = 0;
	while(plants[l] != '\0'){
		l++;
	}
	//get the first letter of the student. multiply it by 2 so it can be used as the base for the diagram position
	int s = (student[0] - 'A') * 2;
	//make the return array for the plants.
	r.plants[0] = char_to_enum(plants[s]);
	r.plants[1] = char_to_enum(plants[s+1]);
	r.plants[2] = char_to_enum(plants[((l+1)/2) + s]);
	r.plants[3] = char_to_enum(plants[((l + 1)/2) + s + 1]);

	return r;
}
