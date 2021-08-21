/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.c
 *
 *    Description:  Binary tree implementation 
 *
 *        Version:  1.0
 *        Created:  08/21/2021 03:54:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node
{
    char *key;
    void *data;
    struct node *left;
    struct node *right;
} node_t;

node_t *allocnode()
{
    node_t *node =  malloc(sizeof(node_t));

    if (!node)
    {
        printf("Node memory allocation failed!");
        exit(1);
    }

    return node;
}

node_t *insert(node_t *root, char *key, void *data)
{
    if (!root)
    {
        node_t *root = allocnode();
        root->key = key;
        root->data = data;
        root->left = NULL;
        root->right = NULL;

        return root;
    }

    if (strcmp(data, root->data) >= 0)
    {
        root->left = insert(root->left, key, data);
    }
    else
    {
        root->right = insert(root->right, key, data);
    }

    return root;
}

void print_node(node_t *node)
{
    if (node)
    {
        printf("key: %s, data: %s\n", node->key, (char *) node->data);
    }
}

// inorder traversal
void visit_tree(node_t *node, void (*fp)(node_t *root))
{
    if (!node)
    {
        return;
    }

    visit_tree(node->left, fp);
    (*fp)(node);
    visit_tree(node->right, fp);
}

// postorder deletion
void destroy_tree(node_t *node, void (*fdestroy)(node_t *root))
{
    if (!node)
    {
        return;
    }

    destroy_tree(node->left, fdestroy);
    destroy_tree(node->right, fdestroy);
    (*fdestroy)(node);
    free(node);
}
