#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "binary_tree.h"

node_t  *allocnode(){
    // Allocate memory for new node
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = 1;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
node_t  *insert(node_t *root, char *key, void *data){
    
}
void    print_node(node_t *node);
void    visit_tree(node_t *node, void (*fp)(node_t *root));
void    destroy_tree(node_t *node, void (*fdestroy)(node_t *root));