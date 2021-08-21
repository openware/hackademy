/*
 * =====================================================================================
 *
 *       Filename:  linked_list.c
 *
 *    Description:  linked list implementation 
 *
 *        Version:  1.0
 *        Created:  08/21/2021 01:46:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	void	*data;
	struct node	*next;
} node_t;

// Special internal function for node creation
void *_node_create(void *data, node_t *next)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
    {
        printf("Node memory allocation failed!");
        exit(1);
    }

    node->data = data;
    node->next = next;

    return node;
}

node_t *list_create(void *data)
{
    return _node_create(data, NULL);
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
    if (!head || !(*head))
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
    if (!head)
    {
        return;
    }

    node_t *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }

    curr->next = _node_create(data, NULL);
}

void list_unshift(node_t **head, void *data)
{
    if (!head || !(*head))
    {
        return;
    }

    *head = _node_create(data, *head);
}

// Removes and returns the last node
void *list_pop(node_t **head)
{
    if (!head || !(*head))
    {
        return NULL;
    }

    // if Head is the only node, remove and return it
    if ((*head)->next == NULL)
    {
        node_t *old_head = *head;
        *head = NULL;
        return old_head;
    }

    // if Head has any 'next' nodes, traverse them to the last but one node
    node_t *curr = *head;
    while (curr->next->next)
    {
        curr = curr->next;
    }

    node_t *popped_node = curr->next;
    curr->next = NULL;
    return popped_node;
}

// Removes and returns the first node
void *list_shift(node_t **head)
{
    if (!head || !(*head))
    {
        return NULL;
    }

    node_t *old_head = *head;
    *head = (*head)->next; // even if there is no 'next' node, we make Head points to NULL
    return old_head;
}

// Removes and returns node being pointed by 'ptr'
void *list_remove(node_t **head, node_t *ptr)
{
    if (!head || !(*head) || !ptr)
    {
        return NULL;
    }

    node_t *curr = *head;
    while (curr->next != ptr && curr->next)
    {
        curr = curr-> next;
    }

    // node pointed by 'ptr' is not in the list
    if (!curr->next)
    {
        return NULL;
    }

    node_t *node_to_remove = curr->next;
    curr->next = node_to_remove->next;
    return node_to_remove;
}

void list_print(node_t *head)
{
    node_t *curr = head;
    while (curr)
    {
        printf("%s", (char *)(curr->data));
        curr = curr->next;
    }
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
    node_t *curr = head;
    while (curr)
    {
        (*fp)(curr->data);
        curr = curr->next;
    }
}
