#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"


node_t *list_create(void *data)
{
    node_t *head = malloc(sizeof(node_t));
    head->data = data;
    head->next = NULL;
    return head;
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
    node_t *now = *head;
    node_t *next;

    while (now != NULL)
    {
        next = now->next;
        fp(now->data);
        free(now);
        now = next;
    }
    *head = NULL;
}

void list_push(node_t *head, void *data)
{
    node_t *new = malloc(sizeof(node_t));
    new->data = data;

    node_t *last = head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new;
}

void list_unshift(node_t **head, void *data)
{
    node_t *new = malloc(sizeof(node_t));
    new->data = data;

    if(*head != NULL)
    {
        new->next = *head;
    }
    *head = new;
}

void *list_pop(node_t **head)
{
    node_t *last = *head;
    node_t *beforeLast = NULL;

    while(last != NULL && last->next != NULL)
    {
        last = last->next;
        beforeLast = last;
    }
    free(beforeLast->next);
    beforeLast->next = NULL;
    return NULL;
}

void *list_shift(node_t **head)
{
    if(*head != NULL)
    {    
        node_t *tmp = *head;
        *head = tmp->next;
        free(tmp);     
    }
    return NULL;
}

void *list_remove(node_t **head, int pos)
{
    node_t *found = *head;
    node_t *before = NULL;
    int i = 0;

    while(found != NULL || i <= pos)
    {
        found = found->next;
        before = found;
        i++;
    }
    if(found != NULL)
    {
        before->next = found;
        free(found);
    }
    return NULL;
}

void list_print(node_t *head)
{
    node_t *elem = head;

    while (elem != NULL)
    {
        printf("%s", (char *)elem->data);
        elem = elem->next;
    }
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
    node_t *elem = head;

    while (elem != NULL)
    {
        fp(elem->data);
        elem = elem->next;
    }
}