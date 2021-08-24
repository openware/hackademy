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
#include "linked_list.h"

node_t  *_node_create(void *data, node_t *next)
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

    void *data = popped_node->data;
    free(popped_node);
    return data;
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

    void *data = old_head->data;
    free(old_head);
    return data;
}

// Removes and returns node being pointed by 'ptr'
void *list_remove(node_t **head, int pos)
{
    if (!head || !(*head) || pos < 0)
    {
        return NULL;
    }

    node_t *curr = *head;
    for (int i = 0; i < pos; i++)
    {
        if (!curr->next)
        {
            return NULL;
        }

        curr = curr->next;
    }

    // node pointed by 'ptr' is not in the list
    if (!curr->next)
    {
        return NULL;
    }

    node_t *node_to_remove = curr->next;
    curr->next = node_to_remove->next;

    void *data = node_to_remove->data;
    free(node_to_remove);
    return data;
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
        fp(curr->data);
        curr = curr->next;
    }
}
