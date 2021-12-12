#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"


node_t *allocnode(){
    node_t *binary_tree_root = malloc(sizeof(node_t));
    binary_tree_root->left = NULL;
    binary_tree_root->right = NULL;
    return binary_tree_root;
}


node_t *insert(node_t *root, char *key, void *data){
    if (root != NULL){
        if (root->data <= data){
            root->right = insert(root->right, key, data);
        }
        else{
            root->left = insert(root->left, key, data);
        }
        return root;
    }
    else{// If root is empty it creates new
        node_t *new = allocnode();
        new->key = key;
        new->data = data;
        return new;
    }
}


void print_node(node_t *node){
    if (node != NULL){
        printf("Node data: '%p', Node key: '%p'", node->key, node->data);
    }
    else{
        printf("Empty Node");
        return;
    }
}


void destroy_tree(node_t *node, void (*fdestroy)(node_t *root)){
    if (node != NULL){
        destroy_tree(node->left, fdestroy);
        destroy_tree(node->right, fdestroy);
        (*fdestroy)(node);
        free(node);
    }
    else{
        return;
    }
}


void visit_tree(node_t *node, void (*fp)(node_t *root)){
    if (node != NULL){
        visit_tree(node->left, fp);
        visit_tree(node->right, fp);
        (*fp)(node);
    }
    else{
        return;
    }
}