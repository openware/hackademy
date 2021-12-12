#include <stdlib.h>
#include <stdio.h>


typedef struct node {
    void         *data;
    struct node  *next;
}              node_t;


void list_push(node_t *head, void *data){
    node_t *from_end = head;
    while (from_end->next){
        from_end = from_end->next;
    }
    node_t *next_node = malloc(sizeof(node_t));
    next_node->data = data;
    next_node->next = NULL;
    from_end->next = next_node;
}


node_t *list_create(void *data){
    node_t *array = malloc(sizeof(node_t));
    array->data = data;
    array->next = NULL;
    return array;
}


void list_destroy(node_t **head, void (*fp)(void *data)){
    node_t *next_node = (*head)->next;
    list_destroy(&next_node, fp);
    (*fp)((*head)->data);
    free(*head);
}


void *list_pop(node_t **head){
    node_t *copy_of_head = *head;
    node_t *copy_previous_head = NULL;
    while (copy_of_head->next != NULL){
        copy_previous_head = copy_of_head;
        copy_of_head = copy_of_head->next;
    }
    copy_previous_head->next = NULL;
    return copy_of_head;
}


void *list_shift(node_t **head){
    if (head){
    node_t *previous_head = *head;
    *head = (*head)->next;
    free(previous_head->data);
    free(previous_head);
    return head;
    }
    else{
        return NULL;
    }
}


void *list_remove(node_t **head, int pos){
    node_t *node = *head;
    while (pos-- > 0){
        node = node->next;
    }
    node_t *rm_node = node->next;
    node->next = rm_node->next;
    free(rm_node->data);
    free(rm_node);
    return rm_node;
}


void list_unshift(node_t **head, void *data){
    node_t *new_array = malloc(sizeof(node_t));
    new_array->data = data;
    new_array->next = (*head)->next;
    (*head)->next = new_array;
    head = &new_array;
}


void list_print(node_t *head){
    node_t *print_data = head;
    while (print_data){
        printf("%s", (char *)(print_data->data));
        print_data = print_data->next;
    }
}


void list_visitor(node_t *head, void (*fp)(void *data)){
    node_t *head_node = head;
    while (head_node){
        (*fp)(head_node->data);
        head_node = head_node->next;
    }
}