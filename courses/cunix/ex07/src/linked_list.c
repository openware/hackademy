#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    void *data;
    struct node *next;
} node_t;


node_t *list_create(void *data) 
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void list_destroy(node_t **head, void (*fp)(void *data)) 
{
    if (*head != NULL) 
    {
        list_destroy(&(*head)->next, fp);
        (*fp)((*head)->data);
        free(*head);
        *head = NULL;
    }
}


void list_push(node_t *head, void *data) 
{
    if (head == NULL) 
    {
        head = list_create(data);
    } 
    else 
    {
        node_t *new_node = list_create(data);

        while (head->next != NULL) 
        {
            head = head->next;
        }

        head->next = new_node;
    }
}

void list_unshift(node_t **head, void *data) 
{
    if (*head != NULL) 
    {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->data = data;
        new_node->next = *head;
        (*head) = new_node;
    }
}


void *list_pop(node_t **head) 
{
    node_t *current = *head;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    void *data = current->next->data;
    free(current->next);
    current->next = NULL;

    return data;
}

void *list_shift(node_t **head) 
{
    node_t *first = *head;
    *head = (*head)->next;
    void *data = first->data;
    free(first);

    return data;
}

void *list_remove(node_t **head, int pos) 
{
    int i = 1;
    node_t *current_head = *head;

    while (i++ < pos && current_head->next->next)
    {
        current_head = current_head->next;
    }

    node_t *current = current_head->next;
    void *data = current->data;
    current_head->next = current->next;
    free(current);

    return data;
}

void list_print(node_t *head) 
{
    while (head != NULL) 
    {
        printf("%s", (char *)head->data);
        head = head->next;
    }
}

void list_visitor(node_t *head, void (*fp)(void *data)) 
{
    while (head != NULL) 
    {
        (*fp)(head->data);
        head = head->next;
    }
}
