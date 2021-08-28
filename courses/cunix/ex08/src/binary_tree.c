#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct  node 
{
    char          *key;
    void          *data;
    struct node   *left;
    struct node   *right;
} node_t;

node_t  *allocnode()
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
    
    node_t *node_to_insert = root; 
    
    while (node_to_insert != NULL)
    {
        if (strcmp(key, node_to_insert->key) >= 0)
        {
            if (node_to_insert->right == NULL)
            {
                node_to_insert->right = allocnode();
                node_to_insert->right->data = data;
                node_to_insert->right->key = key;
                break;
            }
            
            node_to_insert = node_to_insert->right;
        }   
        else
        {
            if (node_to_insert->left == NULL)
            {
                node_to_insert->left = allocnode();
                node_to_insert->left->data = data;
                node_to_insert->left->key = key;
                break;
            }
            
            node_to_insert = node_to_insert->left;
        }
    }
    
    return node_to_insert;
}

void print_node(node_t *node)
{
    if (node != NULL)
    {
        printf("key = %s; data = %s\n", node->key, (char *) node->data);
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


