#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node
{
    char *key;
    char *data;
    struct node *left;
    struct node *right;
} 
node_t;

node_t *allocnode()
{
    node_t *node = malloc(sizeof(node_t));
    node->left = NULL;
    node->right = NULL;

    return node;
}

node_t *insert(node_t *root, char *key, void *data)
{

    if (root == NULL)
    {
        root = allocnode();
        root->key = key;
        root->data = data;

        return root;
    }

    
    else if (root != NULL)
    {
        int cmp = strcmp(key, root->key);
        if (cmp <= 0)
        {
            root->left = insert(root->left, key, data);
        }
        else
        {
            root->right = insert(root->right, key, data);
        }
    }
    return root;
}

void print_node(node_t *node)
{
    if (node != NULL)
    {
        printf("%s", (char *)node->data);
    }
}

void visit_tree(node_t *node, void (*fp)(node_t *root))
{
    if (node != NULL)
    {
        visit_tree(node->left, fp);
        visit_tree(node->right, fp);
        fp(node);
    }
}

void destroy_tree(node_t *node, void (*fdestroy)(node_t *root))
{
    if (node != NULL)
    {
        destroy_tree(node->left, fdestroy);
        destroy_tree(node->right, fdestroy);
        fdestroy(node);
        free(node);
    }
}








