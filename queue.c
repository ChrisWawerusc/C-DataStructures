#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front,rear,size;
    int capacity;
    int *array;
};

struct Queue *createQueue(int capacity){
    struct Queue *queue= (struct Queue*)malloc(sizeof(struct Queue));
    queue->front=0;
    queue->rear=0;
    queue->size=0;
    queue->capacity=capacity;
    queue->array=(int*)malloc(capacity*sizeof(int));
    return queue;
}
int isFull(struct Queue *queue){
    return queue->size== queue->capacity;
}
int isEmpty(struct Queue *queue){
    return queue->size== 0;
}

int Enqueue(struct Queue *queue,int item){
    if(isFull(queue)){
        return -1;
    }else{
        queue->array[queue->rear]=item;
        queue->rear=(queue->rear+1) % queue->capacity;
        queue->size++;
        printf("%d has been successfully added to the queue\n",item);
    }
}
int Dequeue(struct Queue *queue){
    if(isEmpty(queue)){
        return -1;
    }else{
        int item=queue->array[queue->front];
        queue->front=(queue->front+1) % queue->capacity;
        queue->size--;
        return item;
    }
}

int main(){
    struct Queue *queue = createQueue(10);

    Enqueue(queue,20);
    Enqueue(queue,30);
    Enqueue(queue,40);
    Enqueue(queue,50);
}
