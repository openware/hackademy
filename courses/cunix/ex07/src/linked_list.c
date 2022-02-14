#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void memory_error()
{
    printf("Failed to allocate memory");
    exit(1);
}

node_t  *create_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL)
    {
        memory_error();
    }
    node->data = data;
    node->next = NULL;
    return node;
}

node_t *list_create(void *data)
{
    return create_node(data);
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
    if (*head == NULL)
    {
        return;
    }
    node_t *next = (*head)->next;
    list_destroy(&next, fp);
    (*fp)((*head)->data);
    free(*head);
}

void list_push(node_t *head, void *data)
{
    node_t *start = head;
    while (start->next)
    {
        start = start->next;
    }

    start->next = create_node(data);
}

void list_unshift(node_t **head, void *data)
{
    *head = create_node(data);
}

void *list_pop(node_t **head)
{
    void *data;
    if ((*head)->next == NULL)
    {
        data = (*head)->data;
        free(*head);
        return data;
    }

    node_t *start = *head;
    while (start->next->next)
    {
        start = start->next;
    }

    node_t *node = start->next;
    start->next = NULL;

    data = node->data;
    free(node);
    return data;
}

void *list_shift(node_t **head)
{
    if (head == NULL || *head == NULL)
    {
        return NULL;
    }
    node_t *node = *head;
    void *data = (*head)->data;
    *head = (*head)->next;
    free(node);
    return data;
}

void *list_remove(node_t **head, int pos)
{
    int i = 0;
    node_t *start = *head;
    while (i < pos)
    {
        start = start->next;
        i++;
    }
    void *data = start->next->data;
    void *node = start->next;
    start->next = start->next->next;
    free(node);
    return data;
}

void list_print(node_t *head)
{
    node_t *start = head;
    while (start)
    {
        printf("%s", (char *)(start->data));
        start = start->next;
    }
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
    node_t *start = head;
    while (start)
    {
        fp(start->data);
        start = start->next;
    }
}


