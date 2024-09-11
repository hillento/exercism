#include "yacht.h"

int score(dice_t dice, category_t category){
	//Set up a score tracker and an array for the count of each dice
	int score = 0, counts[6] = {0};

	//go to the correct variable
	switch (category) {
		case FULL_HOUSE:
			//get the count of each face
			for(int i = 0; i < 5; i++){
				++counts[dice.faces[i] - 1];
			}
			//Check if there 2 values that appear 2 and 3 times
			//do if/for nest so itteration only happens twice
			for(int j = 0; j < 5; j++){
				if(counts[j] ==2){
					for(int jj = 0; jj < 5; jj++){
						if( counts[jj] == 3){
							//face value is j/jj +1. multiply each face value by their count for score
							return ((j+1) * 2) + ((jj+1) * 3);
							break;
						}
					}
				}
			}
			return 0;
			break;
		case FOUR_OF_A_KIND:
			//Fill count array with face counts
			for(int i = 0; i < 5; i++){
				//if at any point the count is 4, return the score of face value * 4
				if(++counts[dice.faces[i] -1] == 4){
					return (dice.faces[i]) * 4;
					break;
				}
			}
			return 0;
			break;
		case BIG_STRAIGHT:
			//counts array
			for(int i = 0; i < 5; i++){
				++counts[dice.faces[i] - 1];
			}
			//if it fits the criteria for the big straight, return the score of 30
			if(counts[1] > 0 && counts[2] > 0 && counts[3] > 0 && counts[4] > 0 && counts[5]){
				return 30;
				break;
			}
			return 0;
			break;
		case LITTLE_STRAIGHT:
			for(int i = 0; i < 5; i++){
				++counts[dice.faces[i] - 1];
			}
			//if it fits the criteria for the little straight, return the score of 30
			if(counts[0] > 0 && counts[1] > 0 && counts[2] > 0 && counts[3] > 0 && counts[4]){
				return 30;
				break;
			}
			return 0;
			break;
		case CHOICE:
			//add each face value to the score, return the total
			for(unsigned int i = 0; i < 5; i++){
				score += dice.faces[i];
			}
			return score;
			break;
		case YACHT:
			for(unsigned int i = 1; i < 5; i++){
				//while iterating the face values, if there is ever a value that is not the same as the first value, it is not a yacht, return 0 score
				if(dice.faces[0] != dice.faces[i]){
					return 0;
				}else{
					//return 50 if they all match
					return 50;
				}
			}
			break;
		default:
			//for cases ONES...SIXES whenever the face value corresponding with the category, appears, increase the score by the face value
			for(int i = 0; i < 5; i++){
				if(dice.faces[i] == category +1){
					score += category +1;
				}
			}
			return score;
	}
	return 0;
}
