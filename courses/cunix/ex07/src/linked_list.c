#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linked_list.h"

typedef struct  node {
    void        *data;
    struct node *next;
}  node_t;

node_t *list_create(void *data)
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->data = data;
    head->next = NULL;
    return head;
}

//----------------------------------------------------

void list_destroy(node_t **head, void (*fp)(void *data))
{
    node_t *cur_node = *head;
    node_t *new_node;
    while (cur_node != NULL)
    {
        new_node = cur_node->next;
        fp(cur_node->data);
        free(cur_node);
        cur_node = new_node;
    }
    *head = NULL;
}

//---------------------------------------------------

void list_push(node_t *head, void *data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    node_t *main = head;
    while(main->next != NULL)
    {
        main = main->next;
    }
    main->next = new_node;
}

//-----------------------------------------------------

void list_unshift(node_t **head, void *data)
{
    node_t *main = (node_t *)malloc(sizeof(node_t));
    main->data = data;
    main->next = *head;
    *head = main;
}

//---------------------------------------------------

void *list_pop(node_t **head)
{
    node_t *cur_node = *head;
    node_t *prev_node = NULL;
    while(cur_node->next != NULL)
    {
        cur_node = cur_node->next;
        prev_node = cur_node;
    }
    free(prev_node->next);
    prev_node->next = NULL;
    return 0;
}

//---------------------------------------------------

void *list_shift(node_t **head)
{
    node_t *temp = *head;
    *head = temp->next;
    free(temp);     
    return 0;
}

//---------------------------------------------------

void *list_remove(node_t **head, int pos)
{
    node_t *next_node = *head;
    node_t *prev_node = NULL;
    int i = 0;
    while(next_node != NULL || i <= pos)
    {
        next_node = next_node->next;
        prev_node = next_node;
        i++;
    }
	prev_node->next = next_node;
    free(next_node);
    return 0;
}
//---------------------------------------------------

void list_print(node_t *head)
{
    node_t *cur_node = head;
    while (cur_node != NULL)
    {
        printf("%s", (char *)cur_node->data);
        cur_node = cur_node->next;
    }
}

//---------------------------------------------------

void list_visitor(node_t *head, void (*fp)(void *data))
{
    node_t *node = head;
    while (node != NULL)
    {
        fp(node->data);
        node = node->next;
    }
} 
