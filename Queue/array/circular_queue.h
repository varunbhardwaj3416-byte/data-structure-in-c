#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct queue{
    int * queue ; 
    int front ; 
    int rear ; 
    int capacity ;
    int size ;  
} circular_queue ; 
circular_queue * createCircularQueue(int) ; // for capacity arg is being there 
void enQueue(circular_queue * , int) ;
void deQueue(circular_queue * , int * , int *) ; // first int * for return deQueued element , second for if Queue is empty then No deQueue operation .
void doubleQueue(circular_queue *) ; 
int capacity(circular_queue * ) ; 
int size(circular_queue * ) ; 
void freeQueue(circular_queue *) ; 
#endif 