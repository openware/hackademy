#include <stdlib.h>
#include <string.h>
typedef struct node{
	char	*key;
	void	*data;
	struct node	*left;
	struct node	*right;
}		node_t;

node_t *allocnode(){
	node_t *p = (node_t *) malloc(sizeof(node_t));
	return p;
}

node_t *insert(node_t *root, char *key, void *data){
	if(root == NULL){
		node_t *ptr = allocnode();
		if(ptr == NULL){
			//printf("alloc failed!\n");
			exit(1);
		}
		ptr->key = key;
		ptr->data = data;
		ptr->left = ptr->right = NULL;
		return ptr;
	}else{
		if(strcmp(data, root->data)>=0){
			root->left = insert(root->left,key,data);
		}else{
			root->right = insert(root->right,key,data);
		}
		return root;
	}
}

void print_node(node_t *node){
	if(node != NULL){
		//...
		print_node(node->left);
		print_node(node->right);
	}
}

void visit_tree(node_t *node, void (*fp)(node_t *root)){
	if(node != NULL){
		fp(node);
		visit_tree(node->left,fp);
		visit_tree(node->right,fp);
	}
}

void destroy_tree(node_t *node, void (*fdestroy)(node_t *root)){
	if(node != NULL){
		destroy_tree(node->left,fdestroy);
		destroy_tree(node->right,fdestroy);
		fdestroy(node);
	}
}
