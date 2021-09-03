#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

node_t *allocnode () 
{
    node_t *root = (node_t*)malloc(16);
    root->left = NULL;
    root->right = NULL;
    return root;
}

node_t *insert (node_t *root, char  *key, void *data)
{
    if (root == NULL) 
    {
        node_t *new_root = allocnode();
        new_root->key = key;
        new_root->data = data;
        return new_root;
    }
    else if (*key < *root->key) 
    {
        if (root->left == NULL) 
        {
            root->left = insert(root->left, key, data);
            return root;
        }
        insert(root->left, key, data);
        return root;
    }
    else
    {
        if (strcmp(key, root->key) == 0)
        {
            root->data = data;
            return root;
        }
        if (root->right == NULL) 
        {
            root->right = insert(root->right, key, data);
            return root;
        }
        insert(root->right, key, data);
        return root;
    }
}

void   print_node (node_t *node) 
{
    if (node == NULL) 
    {
        return;
    }
    printf("%p\n", node->data);
    print_node(node->right);
    print_node(node->left);
}
void visit_tree (node_t* node, void(*fp)(node_t *root)) 
{
    if (node == NULL) 
    {
        return;
    }
    (*fp)(node);
    visit_tree(node->right, fp);
    visit_tree(node->left, fp);
}
void    destroy_tree (node_t *node, void (*fdestroy)(node_t *root)) 
{
    if (node == NULL) 
    {
        return;
    }
    destroy_tree(node->right, fdestroy);
    destroy_tree(node->left, fdestroy);
    (*fdestroy)(node);
    free(node);
}
