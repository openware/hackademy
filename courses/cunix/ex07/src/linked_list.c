/*
 * =====================================================================================
 *
 *       Filename:  linked_list.c
 *
 *    Description:  Defines Linked list and its maintaining functions 
 *
 *        Version:  1.0
 *        Created:  08/06/2021 01:19:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
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

void list_destroy(node_t **head, void(*fp)(void *data))
{
    if (*head != NULL)
    {
        node_t *next = (*head)->next;
        list_destroy(&next, fp);
        (*fp)((*head)->data);
        free(*head);
    }
}

void list_push(node_t *head, void *data)
{
    node_t *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    current->next = new_node;
}

void list_unshift(node_t **head, void *data)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->next = (*head)->next;
    new_node->data = data;
    (*head)->next = new_node;
}

void *list_pop(node_t **head)
{
    node_t *current = *head;
    node_t *poped_node = current->next;

    while (poped_node->next != NULL)
    {
        current = current->next;
        poped_node = poped_node->next;
    }

    current->next = NULL;
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
    while (--pos != 0)
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
    node_t *current = head;
    while (current != NULL)
    {
        printf("%s", (char *)(current->data));
        current = current->next;
    }
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
    node_t *current = head;
    while (current != NULL)
    {
        (*fp)(current);
        current = current->next;
    }
}
