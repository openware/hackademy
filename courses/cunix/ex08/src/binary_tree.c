/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.c
 *
 *    Description: Binary tree in C 
 *
 *        Version:  1.0
 *        Created:  15.08.2021 16:47:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Den Kalenichenko (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

int my_strcmp(char*, char*);

node_t* allocnode() {
    node_t* node =  (node_t*)malloc(sizeof(node_t));
    node->left = NULL;
    node->right = NULL;
    return node;
}

node_t* insert(node_t* root, char* key, void* data) {
    if (root != NULL) {
        int compare = my_strcmp(key, root->key);
        if (compare <= 0) {
            root->left = insert(root->left, key, data);
        } else {
            root->right = insert(root->right, key, data);
        }
        return root;
    } else {
        node_t* node = allocnode();
        node->key = key;
        node->data = data;
        return node;
    }
}


void print_node(node_t* node) {
    if (node != NULL) {
        printf("%s", (char*)node->data);
    }
}

void visit_tree(node_t* node, void (*fp)(node_t* root)) {
    if (node != NULL) {
        visit_tree(node->left, fp);
        (*fp)(node);
        visit_tree(node->right, fp);
    }
}

void destroy_tree(node_t* node, void (*fdestroy)(node_t* node)) {
    if (node != NULL) {
        destroy_tree(node->left, fdestroy);
        destroy_tree(node->right, fdestroy);
        (*fdestroy)(node);
        free(node);
    }
}

int my_strcmp(char* str1, char* str2) {
    while(*str1 == *str2) {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return *str1 < *str2 ? -1 : 1;
}
