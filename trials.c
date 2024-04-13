#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(int key,int left,int right,int arr[],int size){
    int median=left+(right-left)/2;
    if(key==arr[median]){
        return median;
    }
    
    if(key>arr[median]){
        left=median+1;
        return search( key, left, right,arr, size);
    }else{
        right=median-1;
        return search( key, left, right, arr, size);
       }  
}
// //Unsorted Arrays
void insertBefore(int arr[],int size,int x,int *elements){
    if(*elements>=size){
        printf("The array is full\n");
    }else{
        for(int i=*elements-1;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[0]=x;
        *elements=*elements+1;
    }
    return;
}

void insertAt(int arr[],int x,int size,int index,int *elements){
    if(*elements>=size){
        printf("The array is full\n");
    }else{
        for(int i=*elements-1;i>=index;i--){
            arr[i+1]=arr[i];
        }
        arr[index]=x;
        *elements=*elements+1;
    }
    return;
}

void insertAfter(int arr[],int x,int size,int index,int *elements){
    if(*elements>=size){
        printf("The array is full\n");
    }else{
        for(int i=*elements-1;i>=index+1;i--){
            arr[i+1]=arr[i];
        }
        arr[index+1]=x;
        *elements=*elements+1;
    }
    return;
}

void DeleteElement(int arr[],int size,int *elements,int x){
     for(int i=x;i<*elements-1;i++){
            arr[i]=arr[i+1];
        }
    *elements= *elements-1;
}

// //Sorted Array
void insertSort(int arr[],int size,int *elements,int x){
    int i;
    if(*elements>size){
        printf("The array is full!");
    }else{
        for(i=*elements-1;i>=0 && arr[i]>x; i--){
            arr[i+1]=arr[i];
        }
      arr[i+1]=x;
      *elements= *elements+1;  
    }
}


//Stacks 
///Array Implementation
struct Stack{
    int *array;
    int top;
    int capacity;
};

struct Stack* createStack(int capacity){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int*)malloc(capacity*sizeof(int));
    return stack;
}

int isFull(struct Stack* stack){
    return stack->top==stack->capacity-1;
}
int isEmpty(struct Stack* stack){
    return stack->top==-1;
}
int Push(struct Stack *stack,int x){
    if(isFull(stack)){
        printf("The Stack is full!");
    }else{
        stack->top=stack->top+1;
        stack->array[stack->top]=x;
        // printf("Element has been added to stack!");
    }
}
int Pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("The stack is empty!");
    }else{
        int popped=stack->array[stack->top];
        stack->top=stack->top-1;
        return popped;
    }
}
int iterateStack(struct Stack *stack){
    while(!isEmpty(stack)){
        int element = Pop(stack);
        printf("%d\n", element);
    }
}
// //Linked List implementation
struct StackNode{
    int data;
    struct StackNode *next;
};
struct StackNode *createStackNode(int data){
    struct StackNode *node= (struct StackNode*)malloc(sizeof(struct StackNode));
    node->data=data;
    node->next=NULL;
    return node;
};
void pushToStack(struct StackNode **head_ref, int data){
    struct StackNode *node= (struct StackNode*)malloc(sizeof(struct StackNode));
    node->data=data;
    node->next=NULL;
    if(*head_ref==NULL){
        *head_ref=node;
    }else{
        node->next=(*head_ref);
        (*head_ref)=node;
        printf("Node has been successfully added!");
    }
}
int popOffStack(struct StackNode **head_ref){
    if(*head_ref==NULL){
        printf("Stack is empty and cannot pop!");
        return -1;
    }else{
        struct StackNode *temp= *head_ref;
        int data=temp->data;
        *head_ref=temp->next;
        free(temp);
        printf("\nElement succesfully popped!");
        return data;
    }
}



//Queues
struct Queue{
    int front,rear,size;
    int *array;
    int capacity;
};

struct Queue *createQueue(int capacity){
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity=capacity;
    queue->front=0;
    queue->rear=capacity-1;
    queue->size=0;
    queue->array=(int*)malloc(capacity*sizeof(int));
    return queue;
}
int isFull(struct Queue* queue){
    return queue->rear+1 % queue->capacity == queue->front;
}
int isEmpty(struct Queue* queue){
    return queue->front==0;
}

void Enqueue(struct Queue* queue,int x){
    if(isFull(queue)){
        printf("The Queue is full!");
    }else{
        queue->rear = queue->rear+1 % queue->capacity;
        queue->array[queue->rear]=x;
        queue->size=queue->size+1;
    }
}
int Dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("The Queue is empty!");
    }else{
        int firstOut=queue->array[queue->front];
        queue->front=queue->front+1;
        queue->size=queue->size-1;
        return firstOut;
    }
}
void iterateQueue(struct Queue *queue){
    int i = queue->front;
    int count = 0;
    while (count < queue->size) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
        count++;
    }
} 
//Linked list implementation
struct NodeQueue{
    int data;
    struct NodeQueue *next;
};
struct QueueNode{
    struct NodeQueue *front;
    struct NodeQueue *rear;
};
struct QueueNode *createQueue(){
    struct QueueNode *queue= (struct QueueNode*)malloc(sizeof(struct QueueNode));
    queue->front=NULL;
    queue->rear=NULL;
    return queue;
}
struct NodeQueue *createNode(int data){
    struct NodeQueue *new_node= (struct NodeQueue*)malloc(sizeof(struct NodeQueue));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
};
void enqueueNode(struct QueueNode *queue, int data){
    struct NodeQueue *new_node= (struct NodeQueue*)malloc(sizeof(struct NodeQueue));
    new_node->data=data;
    new_node->next=NULL;
    if(queue->rear==NULL){
        queue->front=new_node;
        queue->rear=new_node;
        printf("Element successfully enqueued!\n");

    }else{
        queue->rear->next=new_node;
        queue->rear=new_node;
        printf("Element successfully enqueued!\n");
    }
};
int dequeueNode(struct QueueNode *queue){
    if(queue->front==NULL){
        printf("Queue is empty, cannot dequeue!");
        return -1;
    }else{
        struct NodeQueue *temp=queue->front;
        int data= temp->data;
        queue->front=temp->next;
        free(temp);
        printf("Element successfully dequeued!\n");
        return data;
    }
}
void displayQueue(struct QueueNode *queue) {
    struct NodeQueue* current = queue->front;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


// //Linked List
struct Node{
    int data;
    struct Node *next;
};
struct Node *createNode(int data){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    return node;
}
void Push(struct Node **head_ref,int x){
    struct Node *last = *head_ref;
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=x;
    node->next=NULL;
   
    if(*head_ref==NULL){
        *head_ref=node;
        return;
    }else{
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=node;
    }
}

void insertBeginning(struct Node **head_ref,int x){
    struct Node *last = *head_ref;
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=x;
    node->next=(*head_ref);
    (*head_ref)=node;
    
    
    printf("Element is now the first node");
}

void insertAfterNode(struct Node *prev_node,int x){
    if(prev_node==NULL){
        printf("Node Does not exist");
    }else{
       
        struct Node *node=(struct Node*)malloc(sizeof(struct Node));
        node->data=x;
        node->next=prev_node->next;
        prev_node->next=node;
    }
}

void deleteNode(struct Node **head_ref, int data){
    struct Node *temp = *head_ref;
    struct Node *Q;


    if(*head_ref==NULL){
        return;
    }else{
        if(temp->data==data && temp==(*head_ref)){
            *head_ref=temp->next;
            free(temp);
            return;
        }

        while(temp->data!=data && temp!=NULL){
            Q=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            printf("Element not found in the list!");
            return;
        }
        
        Q->next=temp->next;
        free(temp);
        printf("Node has been succesfully deleted!");
    }
}

int count(struct StackNode *head){
    int count=0;
    struct StackNode *current=head;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}

void main(){
    struct QueueNode *queue=createQueue();
    enqueueNode(queue,10);
    enqueueNode(queue,20);
    enqueueNode(queue,30);
    enqueueNode(queue,40);
    enqueueNode(queue,50);
    displayQueue(queue);
    dequeueNode(queue);
    displayQueue(queue);
    enqueueNode(queue,99);
    displayQueue(queue);
    

}
