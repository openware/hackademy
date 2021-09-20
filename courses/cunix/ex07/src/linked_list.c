#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include <assert.h>





 node_t  *list_create(void *data){
  node_t * head;
  head = (node_t *) malloc(sizeof(node_t));
  head->data = data;
  head->next = NULL;
  return head;
 };

void    list_destroy(node_t **head, void (*fp)(void *data)){
  struct node *current = (struct node*) malloc(sizeof(struct node));
   //struct node* current = *head;
   struct node* next;
   current=*head;
 
   while (current != NULL){
       next = current->next;
       fp(current->data);
       free(current);
       //fp(current);
       current = next;
   }
   //*head = NULL;
  

  /*struct node* current = *head;
  struct node* next;
  while (current != NULL) {
    next = current->next;
    free(current);
    fp(current);
    current = next;
  }
  *head = NULL;*/

    /*node_t* prev = NULL;
    node_t* head2 = *head;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
        fp(prev);
    }
    head2=*head;
    free(head2);
    fp(head2);*/
}

void    list_push(node_t *head, void *data){
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data  = data;
    new_node->next = (head);
    (head) = new_node;
}

void    list_unshift(node_t **head, void *data){

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head;  
    new_node->data  = data;
    new_node->next = NULL;
    if (*head == NULL){
       *head = new_node;
    } else{
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
     }
}



void    *list_remove(node_t **head,  int pos){
    int i = 0;
    node_t * current = *head;
    //node_t * temp_node = NULL;
    node_t* temp_node = (node_t*) malloc(sizeof(node_t));
    for (i = 0; i < pos-1; i++) {
        current = current->next;
    }
    temp_node = current->next;
    current->next = temp_node->next;
    //free(temp_node);

    return temp_node;

  /*
   if (*head == NULL){

   }else{
 
   // Store head node
   struct node* temp = *head;
   struct node* next1 = *head;
 
    // If head needs to be removed
    
    if (pos == 0)
    {
        *head = temp->next;   // Change head
        free(temp);               // free old head
        
    }else{
 
    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<pos-1; i++)
         temp = temp->next;
 
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL){

    }else{
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct node *next = temp->next->next;
 
    // Unlink the node from linked list
    next1=temp->next;
    free(next1);  // Free memory
 
    temp->next = next; 
     }
    }
   }
    
   return 0;  */
}

void    *list_pop(node_t **head){
    struct node  *preNode;
    //node_t* toDeLast = (node_t*) malloc(sizeof(node_t));
    
    if(*head == NULL){}
    else
    {
        struct node *toDelLast = (struct node*) malloc(sizeof(struct node));
        toDelLast = *head;
        preNode = *head;
        while(toDelLast->next != NULL)
        {
            preNode = toDelLast;
            toDelLast = toDelLast->next;
        }
        if(toDelLast == *head)
        {
            return NULL;
        }
        else
        {
            preNode->next = NULL;
        }
        //free(toDelLast);
        return toDelLast;
    }

  /*struct node* temp = *head;
  struct node* next2=*head;
  for (int i=0; temp!=NULL&&temp->next!=NULL; i++)
         temp = temp->next;
  //struct node* prev = temp;
  next2=temp->data;
  free(next2);
  temp->next =NULL;*/
  return NULL;
}

void    *list_shift(node_t **head){
  struct node* t = *head;
  /**head = temp->next; 
  free(temp);  */ 
  if( t == NULL)
    {
        return NULL;
    }else{
      node_t* del = (node_t*) malloc(sizeof(node_t));
      node_t *temp = *head;
  //struct node *temp_del = *head;
      temp = temp->next;
      del=*head;
    //free(del);
      *head = temp;
      return del;
    }
   //return del;    

}

void    list_print(node_t *head){
  struct node *temp = head;
  while(temp != NULL){
        if(temp->next == NULL){
            printf("%p", temp->data);

            //puts(temp->data);
        }
        temp = temp->next;
    }
}

void list_visitor(node_t *head, void (*fp)(void *data)){
node_t *temp = head;
node_t *out=temp;
//int f=0;
while(temp != NULL){
  if(temp->next == NULL){
            out=temp->data;
            fp(out->data);
        }
        temp = temp->next;
}
}