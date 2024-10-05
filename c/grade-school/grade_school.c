#include "grade_school.h"

void init_roster(roster_t *actual){
	//make a blank roster starting at count 0
	actual->count = 0;
}

int add_student(roster_t *actual, char *name, int grade){
	//ensure no duplicates
	for(size_t i = 0; i < actual->count; i++){
		if(strcmp(name,actual->students[i].name) == 0){
			return false;
		}
	}
	
	//Find correct grade, then alphabetical position, set placement variable accordingly
	size_t placement = actual->count;
	for(size_t i = 0; i < actual->count; i++){
		if(actual->students[i].grade < grade){
			continue;
		}
		//if the grade is the same and the new name is alphabetically closer to z, increment i
		if(actual->students[i].grade == grade && strcmp(name, actual->students[i].name) > 0){
			continue;
		}
		placement = i;
		break;
	}
	//shift the index of the existing student up accordingly
	for(size_t i = actual->count; i > placement; i--){
		actual->students[i] = actual->students[i-1];
	}
	//insert the new student and increment the count
	actual->students[placement].grade = grade;
	strcpy(actual->students[placement].name,name);
	actual->count++;
	return true;
}

roster_t get_grade(roster_t *roster, int grade){
	//make a return roster
	roster_t r;
	r.count = 0;
	//scan the roster and only add the students of the correct grade to the new roster
	for(size_t i = 0; i < roster->count; i++){
		if(roster->students[i].grade == grade){
			r.students[r.count++] = roster->students[i];
		}
	}
	return r;
}
