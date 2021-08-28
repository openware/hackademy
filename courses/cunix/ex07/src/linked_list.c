#include <stdlib.h>
#include <stdio.h>

typedef struct node 
{
    void *data;
    struct node *next;
} node_t;

node_t *list_create(void *data) 
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    
    return new_node;
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
    if (*head != NULL) 
    {
        list_destroy(&((*head)->next), fp);
        (fp)((*head)->data);
        free(*head);
    }    
}

void list_push(node_t *head, void *data)
{
    node_t *curr_node = head;
    
    while (curr_node->next != NULL)
    {
        curr_node  = curr_node->next;
    }
    
    curr_node->next = malloc(sizeof(node_t));
    curr_node->next->data = data;
    curr_node->next->next = NULL;
}

void list_unshift(node_t **head, void *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->next = *head;
    new_node->data = data;
    *head = new_node;
}

void *list_pop(node_t **head)
{
    node_t *pre_last_node = *head;
    
    while (pre_last_node->next->next != NULL)
    {
        pre_last_node = pre_last_node->next;
    }
    
    void *last_node_data = pre_last_node->next->data;
    free(pre_last_node->next);
    pre_last_node->next = NULL;
    
    return last_node_data;
}

void *list_shift(node_t **head)
{
    node_t *new_head = (*head)->next;
    void *head_data = (*head)->data;
    free(*head);
    *head = new_head;
    
    return head_data;
}

void *list_remove(node_t **head, int pos)
{
    node_t *curr_node = *head;
    
    for (int i = 0; i < pos - 1; i++) 
    {
        curr_node = curr_node->next;
    }
    
    node_t *node_to_delete = curr_node->next;
    void *data = node_to_delete->data;
    curr_node->next = node_to_delete->next;
    free(node_to_delete);
    
    return data;
}

void list_print(node_t *head)
{
    node_t *curr_node = head;
    
    while (curr_node != NULL) 
    {
        printf("%s\n", (char *)curr_node->data);
        curr_node = curr_node->next;
    }
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
    node_t *curr_node = head;
    
    while (curr_node != NULL)
    {
        (*fp)(curr_node->data);
        curr_node = curr_node->next;
    }
}

