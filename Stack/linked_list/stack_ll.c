#include <stdio.h>
#include "stack_ll.h"
#include <stdlib.h>

stack_using_linked_list *createStackLl() {
    stack_using_linked_list * n = (stack_using_linked_list *) malloc(sizeof(stack_using_linked_list)) ; 
    if (!n) {
        return NULL ; 
    }
    n -> top = NULL ; 
    return n ; 
}
void freeStackLl(stack_using_linked_list * sll) {       // sll refers to stack linked list 
    if (!sll) return ; 
    node * temp = NULL ; 
    while(sll -> top) {
        temp = sll -> top ; 
        sll -> top = sll -> top -> next ; 
        free(temp) ; 
    }
    free(sll) ; 
}
node * createNode(int data) {
    node * n = (node*) malloc(sizeof(node)) ; 
    if(!n) {
        return NULL ; 
    }
    n -> data = data ; 
    n -> next = NULL ; 
    return n ; 
}
void pushStackLl(stack_using_linked_list * sll , int data) {
    if (!sll) return ; 
    if (!sll -> top) {
        sll -> top = createNode(data) ; 
        if(!sll -> top) return ;  
    }
    else {
    node * n = createNode(data) ; 
    n -> next = sll -> top ; 
    sll -> top = n ;
    } 
}
void popStackLl(stack_using_linked_list * sll , int * data , int * found) {
    if (!sll || !sll -> top){
        *found = 0 ; 
        return ; 
    } 
    *found = 1 ; 
    *data = sll -> top -> data ; 
    node * temp = sll -> top ;  
    sll -> top = sll -> top -> next ; 
    free(temp) ; 
}
void peekStackLl(stack_using_linked_list * sll , int * data , int * found) {
    if(!sll || !sll -> top){
        *found = 0 ; 
        return ; 
    } 
    *found = 1 ; 
    *data = sll -> top -> data ; 
    return ; 
}
int isEmptyStackLl(stack_using_linked_list * sll) {
    return (sll -> top == NULL) ; 
}




