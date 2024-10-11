#include "list_ops.h"

list_t* new_list(size_t length, list_element_t elements[]){
	list_t *list = malloc(sizeof(list_t) + sizeof(list_element_t) * length);
	list->length = length;

	if(!list){
		return NULL;
	}
	if(elements){
		memcpy(list->elements, elements, sizeof(*elements) * length);
	}
	return list;
}

list_t *append_list(list_t *list1, list_t *list2){
	if(!list1 || !list2){
		return NULL;
	}
	list_t *list = new_list(list1->length + list2->length, NULL);
	if(!list){
		return NULL;
	}
	memcpy(list->elements, list1->elements, sizeof(list_element_t) * list1->length);
	memcpy(list->elements + list1->length, list2->elements, sizeof(list_element_t) * list2->length);

	return list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
	if(!list){
		return NULL;
	}

	list_t *f_list = new_list(list->length, NULL);

	if(!f_list){
		return NULL;
	}

	f_list->length = 0;
	for(size_t i = 0; i < list->length; i++){
		list_element_t e = list->elements[i];
		if(filter(e)){
			f_list->elements[f_list->length++] = e;
		}
	}

	f_list = realloc(f_list, sizeof(list_t) + sizeof(list_element_t) * f_list->length);
	return f_list;
}


size_t length_list(list_t *list){
	return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)){
	if(!list){
		return NULL;
	}
	list_t *m_list = new_list(list->length, NULL);
	if(!m_list){
		return NULL;
	}
	for(size_t i = 0; i < list->length; i++){
		m_list->elements[i] = map(list->elements[i]);
	}
	return m_list;
}

list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t)){
	list_element_t a = initial;
	for( size_t i = 0; i < list->length; i++){
		a = foldl(a, list->elements[i]);
	}
	return a;
}

list_element_t foldr_list(list_t *list, list_element_t initial,list_element_t (*foldr)(list_element_t, list_element_t)){
	list_element_t a = initial;
	for(size_t i = 0; i < list->length; i++){
		a = foldr(list->elements[list->length - 1 - i], a);
	}
	return a;
}

list_t *reverse_list(list_t *list){
	list_t *list2 = new_list(list->length, list->elements);
	for(size_t i = 0; i < list2->length; i++){
		memcpy(&list2->elements[i], &list->elements[list->length - i - 1], sizeof(list_element_t));
	}
	return list2;

}

void delete_list(list_t *list){
	free(list);
}
