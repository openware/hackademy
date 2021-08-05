#include <stdlib.h>

typedef struct node {
	void	*data;
	struct node	*next;
}		node_t;

node_t *list_create(void *data){
	node_t *pointer;
	pointer = (node_t *) malloc(sizeof(node_t));
	if(pointer == NULL){
		exit(1);
	}
	pointer->data = data;
	pointer->next = NULL;
	return pointer;
}

/*void list_destroy(node_t **head, void(*fp)(void *data)){
	if(head == NULL){
		return ;
	}
	//node_t *ptr = *head;
	node_t *ptrn = NULL;

	for(node_t *ptr = *head; ptr != NULL;){
		ptrn = ptr->next;
		//fp(ptr->data);
		fp(ptr->data);
		//ptr->next = NULL;
		//----free(ptr->data);
		//free(ptr->next);
		ptr=ptrn;
		//ptr = ptr->next;
	}
	//  *head = NULL;
}*/

void list_destroy(node_t **head, void (*fp)(void *data)){
	/*if(*head != NULL){
		//void *p = (*head)->data;
		list_destroy(&(*head)->next,fp);
		//free(*head);
		fp((void *) *head);
		//(*head)->data = NULL;
		*head = NULL;
	}*/
	node_t *ptr = *head;
	node_t *next;
	while(ptr != NULL){
		next = ptr->next;
		if(ptr->data != NULL){
			fp(ptr->data);
		}
		ptr = next;
	}
	*head = NULL;
}

void list_push(node_t *head, void *data){
	node_t *ptr = head;
	for(;ptr->next != NULL; ptr=ptr->next);
	ptr->next = (node_t *) malloc(sizeof(node_t));
	if(ptr->next == NULL){
		exit(1);
	}
	ptr->next->data = data;
	ptr->next->next = NULL;
}

void list_unshift(node_t **head,/* char *key,*/ void *data){
	node_t *ptr = (node_t *) malloc(sizeof(node_t));
	if(ptr == NULL){
		exit(1);
	}
	ptr->data = /*(void *) key*/ data;
	/*if(data != NULL){
		node_t *ptrn = (node_t *) malloc(sizeof(node_t));
		if(ptrn == NULL){
			exit(1);
		}
		ptrn->data = data;
		ptrn->next = *head;
		ptr->next = ptrn;
	}else{*/
	ptr->next = *head;
	//}
	*head = ptr;
}

void *list_pop(node_t **head){
	node_t *ptr = *head;
	node_t *prev = NULL;
	//node_t *ptrn = ptr;
	if(ptr == NULL){
		return NULL;
	}
	void *p;
	for(;ptr->next != NULL;ptr=ptr->next/*,ptrn = ptr*/){
		prev = ptr;
	}
	p = ptr->data;
	free(ptr);
	prev->next = NULL;
	return p;
}

void *list_shift(node_t **head){
	node_t *ptr = *head;
	if(ptr == NULL){
		return NULL;
	}
	void *p = ptr->data;
	*head = ptr->next;
	free(ptr);
	return p;
}

/*void *list_remove(node_t **head, node_t *ptr){// ----
	node_t *pt = *head;
	node_t *prev = NULL;
	if(pt == NULL){
		return NULL;
	}
	void *p;
	//int find = 1;
	for(;pt != NULL ; pt = pt->next){//&& find
		if(pt == ptr){
			p = pt->data;
			if(prev == NULL){
				*head = pt->next;
			}else{
				prev->next = pt->next;
			}
			free(pt);
			return p;
		}
		prev = pt;
	}
	return NULL;
}*/
void *list_remove(node_t **head, int pos){
	node_t *ptr = *head;
	node_t *prev = NULL;
	if(ptr == NULL){
		return NULL;
	}
	for(int i = 1;ptr != NULL && i < pos;ptr = ptr->next,i++){
		prev = ptr;
	}
	if(ptr != NULL){
		void *p = ptr->data;
		if(prev == NULL){
			*head = ptr->next;
		}else{
			prev->next = ptr->next;
		}
		free(ptr);
		return p;
	}
	return NULL;
}

void list_print(node_t *head){
	node_t *ptr = head;
	for(;ptr != NULL;ptr = ptr->next){
		//print(ptr->data);
	}
}

void list_visitor(node_t *head, void (*fp)(void *data)){
	node_t *ptr = head;
	for(;ptr != NULL;ptr = ptr->next){
		fp(ptr->data);
	}
}
