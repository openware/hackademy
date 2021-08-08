#include <stdlib.h>
#include <stdio.h>

typedef struct node 
{
    void *data;
    struct node *next;
}
node_t;

node_t *list_create(void *data)
{
    node_t *head = malloc(sizeof(node_t));
    head->data = data;
    head->next = NULL;

    return head;
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
    if (*head)
    {
        node_t *next = (*head)->next;
        list_destroy(&next, fp);

        (*fp)((*head)->data);
        
        free(*head);
    }
}

void list_push(node_t *head, void *data)
{
    if (head)
    {
        node_t *end = head;
        while (end->next)
        {
            end = end->next;
        }

        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = data;
        new_node->next = NULL;

        end->next = new_node;
    }
}

void list_unshift(node_t **head, void *data)
{
    if (*head)
    {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = data;
        new_node->next = (*head)->next;

        (*head)->next = new_node;

        head = &new_node;
    }
}

void *list_pop(node_t **head)
{
    node_t *penult_node = *head;
    while (penult_node->next->next)
    {
        penult_node = penult_node->next;
    }

    node_t *poped_node = penult_node->next;
    penult_node->next = NULL;

    free(poped_node->data);
    free(poped_node);

    return poped_node;
}

void *list_shift(node_t **head)
{
    node_t *old_head = *head;
    *head = (*head)->next;

    free(old_head->data);
    free(old_head);
    
    return head;
}

void *list_remove(node_t **head, int pos)
{
    node_t *current = *head;
    while (pos-- > 0)
    {
        current = current->next;
    }

    node_t *removed_node = current->next;

    current->next = removed_node->next;

    free(removed_node->data);
    free(removed_node);
    
    return removed_node;
}

void list_print(node_t *head)
{
    node_t *node = head;
    while (node)
    {
        printf("%s", (char *)(node->data));
        node = node->next;
    }
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
    node_t *node = head;
    while (node)
    {
        (*fp)(node->data);
        node = node->next;
    }
}
