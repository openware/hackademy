
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
    if (head != NULL)
    {
        node_t *new_node = list_create(data);

        while (head->next != NULL)
        {
            head = head->next;
        }

        head->next = new_node;
    }


    else
    {
        head = list_create(data);
    }
    
}

void list_unshift(node_t **head, void *data)
{
    if (*head != NULL)
    {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->data = data;
        new_node->next = *head;
        *head = new_node;
    }
}

void *list_pop(node_t **head)
{
    node_t *node_bef = *head;

    while (node_bef->next->next != NULL)
    {
        node_bef = node_bef->next;
    }

    void *data = node_bef->next->data;
    free(node_bef->next);
    node_bef->next = NULL;

    return data;
}

void *list_shift(node_t **head)
{

    node_t *head_f = *head;
    *head = (*head)->next;
    void *data = head_f->data;
    free(head_f);

    return data;
}

void *list_remove(node_t **head, int pos)
{
    int i = 1;
    node_t *slc_head = *head;

    while (i++ < pos && slc_head->next->next)
    {
        slc_head = slc_head->next;
    }
    
    node_t *slc_n = slc_head->next;
    void *data = slc_n->data;
    slc_head->next = slc_n->next;
    free(slc_n);

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

