#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node_t *list_create (void *data)
{
    node_t *new_list = (node_t *)malloc(8);
    new_list->data = data;
    new_list->next = NULL;
    return new_list;
}

void   list_destroy (node_t **head, void (*fp)(void *data))
{
    node_t *pre_head = *head;
    while (pre_head != NULL)
    {
         (*fp)((*head)->data);
         *head = (*head)->next;
         free(pre_head);
         pre_head = *head;
    }
}

void   list_push (node_t *head, void *data)
{
    node_t *cop_head = head;
    while(cop_head->next != NULL) 
    {
        cop_head = cop_head->next;
    }
    node_t *new_node = (node_t *)malloc(8);
    new_node->data = data;
    new_node->next = NULL;
    cop_head->next = new_node;
}

void   list_unshift (node_t **head, void *data)
{
    node_t *new_head = (node_t *)malloc(8);
    new_head->data = data;
    new_head->next = *head;
    *head = new_head;
}

void  *list_pop (node_t **head)
{
    node_t *cop_head = *head;
    node_t *cop_head_prev = NULL;
    while (cop_head->next != NULL) 
    {
        cop_head_prev = cop_head;
        cop_head = cop_head->next;
    }
    cop_head_prev->next = NULL;
    return cop_head;
}

void  *list_shift (node_t ** head)
{
   if (*head == NULL)
    {
        return NULL;
    }
    node_t *old_head = *head;
    *head = (*head)->next;
    old_head->next = NULL;
    return old_head;
}

void  *list_remove (node_t **head, int pos)
{
    node_t *cop_head = *head;
    node_t *cop_prev = NULL;
    int counter = 0;
    while (cop_head->next != NULL) 
    {
        if (counter == pos) 
        {
            if (counter == 0)
            {
                *head = cop_head->next;
                cop_head->next = NULL;
                return cop_head;
            }
            else
            {
                cop_prev->next = cop_head->next;
                return cop_head;
            }
        }
        counter++;
        cop_prev = cop_head;
        cop_head = cop_head->next;
    }
    cop_prev->next = cop_head->next;
    return cop_head;
}

void   list_print (node_t *head)
{
    node_t *cop_head = head;
    while (cop_head != NULL)
    {
         printf("%p\n", ((char *)cop_head->data));
         cop_head = cop_head->next;
    }
}

void   list_visitor (node_t *head, void (*fp)(void *data))
{
    node_t *cop_head = head;
    while (cop_head != NULL)
    {
         (*fp)(cop_head->data);
         cop_head = cop_head->next;
    }
}


