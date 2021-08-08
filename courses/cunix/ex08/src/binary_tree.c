#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

node_t *allocnode()
{
    node_t *tree_root = malloc(sizeof(node_t));
    return tree_root;
}

node_t *insert(node_t *root, char *key, void *data)
{
    // if the root is not empty, recur the tree down
    if (root)
    {
        if (data <= root->data)
        {
            root->left = insert(root->left, key, data);
        }
        else
        {
            root->right = insert(root->right, key, data);
        }

        return root;
    }
    else
    {
        node_t *new_node = allocnode();
        new_node->key = key;
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
    }
}

void print_node(node_t *node)
{
    if (node)
    {
        printf("key: '%s', data: '%s'", node->key, (char *)(node->data));
    }
}

void visit_tree(node_t *node, void (*fp)(node_t *root))
{
    if (node)
    {
        visit_tree(node->left, fp);
        (*fp)(node);
        visit_tree(node->right, fp);
    }
}

void destroy_tree(node_t *node, void (*fdestroy)(node_t *root))
{
    if (node)
    {
        destroy_tree(node->left, fdestroy);
        destroy_tree(node->right, fdestroy);
        (*fdestroy)(node);
        free(node);
    }
}

