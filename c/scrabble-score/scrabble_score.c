#include "scrabble_score.h"

unsigned int score(const char *word){
	//start the score at 0
	int score = 0;
	//iterate the word
	for(int i = 0; word[i] != '\0'; i++){
		//make each character lower case if it isn't already
		char cand = word[i];
		if(cand >= 65 && cand <= 90){
				cand += 32;
		}
		//just use a swtich to return the proper score. all 1 value letters are defualt to save space
		switch (cand) {
			case 'd':
			case 'g':	
				score += 2;
				break;
			case 'b':
			case 'c':
			case 'm':
			case 'p':
				score += 3;
				break;
			case 'f':
			case 'h':
			case 'v':
			case 'w':
			case 'y':
				score += 4;
				break;
			case 'k':
				score += 5;
				break;
			case 'j':
			case 'x':
				score += 8;
				break;
			case 'q':
			case 'z':
				score += 10;
				break;
			default:
				score +=1;
				break;
		}
	}
	return score;
			
}
