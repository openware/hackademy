#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"

node_t *list_create(void *data)
{
    node_t *newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
    node_t *prev = *head;
    while (prev)
    {
        fp(prev->data);
        free(prev);
        prev = prev->next;
    }
}

// typedef struct node
// {
//     void *data;
//     struct node *next;
// } node_t;

void list_push(node_t *head, void *data)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = list_create(data);
}
