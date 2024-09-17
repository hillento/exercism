#include "sublist.h"

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count){
	//Check if they're both null to avoid further computes
	if(list_to_compare == NULL && base_list == NULL) return EQUAL;
	//if the lists are the same length check if any elements are different, if they are return unequal, if they are all the same return equal
	if(list_to_compare_element_count == base_list_element_count){
		for(size_t i = 0; i < base_list_element_count; i++){
			if( list_to_compare[i] != base_list[i]){
				return UNEQUAL;
			}
		}
		return EQUAL;
		//if the base lsit is bigger
	}else if( base_list_element_count > list_to_compare_element_count){
		//and the list to compare is null, then it's automatically a sublist
		if(list_to_compare == NULL) return SUBLIST;
		//the furthest element we need to start at is the base count - compare count 
		for(size_t i = 0; i < base_list_element_count - list_to_compare_element_count+1; i++){
			//j can be used to count matches because we iterate it on match
			size_t j =0;
			//for each element about iterate the smaller list until a mismatch is found, then move to the next one
			for(j = 0; j < list_to_compare_element_count; j++){
				if(base_list[i+j] != list_to_compare[j]){
					break;
				}
			}
			//if the smaller list is fully iterated, then it's a sublist
			if(j == list_to_compare_element_count){
				return SUBLIST;
			}
		}
		//if a sublist isn't found, then they are unequal.
		return UNEQUAL;
	//repeat same logic as above but swap the lists
	}else if (list_to_compare_element_count > base_list_element_count){
		if(base_list == NULL) return SUPERLIST;

		for(size_t i = 0; i < list_to_compare_element_count - base_list_element_count+1; i++){
			size_t j = 0;
			for(j = 0; j < base_list_element_count; j++){
				if(base_list[j] != list_to_compare[i + j]){
					break;
				}
			}
			if(j == base_list_element_count){
				return SUPERLIST;
			}
		}
		return UNEQUAL;
	}
	//if no other returns are hit, then the lists are unequal
	return UNEQUAL;
}
