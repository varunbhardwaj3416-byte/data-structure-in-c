#include <stdio.h>
#include "circular_queue.h"
#include <stdlib.h>

circular_queue * createCircularQueue(int capacity) {
    if (!capacity) return NULL ; 
    circular_queue * q = (circular_queue *) malloc(sizeof(circular_queue)) ; 
    if(!q) return NULL ; 
    q -> queue = (int *) malloc(sizeof(int) * capacity) ; 
    if(!q -> queue) return NULL ; 
    q -> front = q -> rear = -1 ; 
    q -> size = 0 ; 
    q -> capacity = capacity ; 
    return q ; 
}
void doubleQueue(circular_queue * q) {
    if(!q) return ; 
    int * t = realloc(q -> queue , sizeof(int) * q -> capacity * 2) ; 
    if(!t){
        free(t) ; 
        return ; 
    }
    q -> queue = t ; 
    // now copy all the element's of queue from front to rear in new array 
    int temp[q->capacity *2] ; 
    for(int i = 0 ; i < q -> capacity ; ++i) {
        temp[i] = q -> queue[(q -> front + i) % (q -> capacity)] ; 
    }
    // copy temp elements into our queue 
    for (int i = 0 ; i < q -> capacity ; ++i) {
        q -> queue[i] = temp[i] ; 
    }
    q -> capacity = q -> capacity * 2 ; 
    return ;
} 
void enQueue(circular_queue * q , int data ) {
    if(!q) return ; 
    if(q -> front == -1){
        q -> front = 0 ; 
    } 
    if((q -> rear + 1) % (q -> capacity) == q -> front) {
        // queue is full Double the queue
        doubleQueue(q) ; 
    }
    q -> queue[++q -> rear] = data ; 
    q -> size = q -> size + 1 ; 
}
void deQueue(circular_queue * q , int * data , int *found) {
    if(q -> size == 0) {
        *found = 0 ; 
        return ; 
    }
    *found = 1 ; 
    *data = q -> queue[q -> front] ; 
    q -> front = (q -> front + 1) % (q -> capacity) ; 
    q -> size = q -> size - 1 ; 
    if(!q -> size) {
        // if size becomes 0 
        q -> front = q -> rear = -1 ; 
    }
}
int capacity(circular_queue * q) {
    if (!q) return -1 ; 
    return q -> capacity ;
}
int size (circular_queue * q) {
    if (!q) return -1 ; 
    return q -> size ; 
}
void freeQueue(circular_queue * q) {
    if(!q) return ; 
    free(q -> queue) ; 
    free(q) ; 
}