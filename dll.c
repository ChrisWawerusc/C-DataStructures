#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct DoublyLinkedList{
    struct Node *head;
    struct Node *tail;
};
struct Node *createNode(int data){
    struct Node *node= (struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    node->prev=NULL;
};
struct DoublyLinkedList *createList(){
    struct DoublyLinkedList *list=(struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    list->head=NULL;
    list->tail=NULL;
};

void insertAtBeginning(struct DoublyLinkedList *list, int data){
    struct Node *new_node = createNode(data);
    if(list->head==NULL){
      list->head=new_node;
      list->tail=new_node;
      printf("Element is only one in the list!\n");

    }else{
        new_node->next=list->head;
        list->head->prev=new_node;
        list->head=new_node;
        printf("Element is now at the beginning of the list!\n");
    }
};
void insertAtEnd(struct DoublyLinkedList *list, int data){
    struct Node *new_node = createNode(data);
    if(list->tail==NULL){
      list->head=new_node;
      list->tail=new_node;
    }else{
        new_node->prev=list->tail;
        list->tail->next=new_node;
        list->tail=new_node;
        printf("Element is now at the end of the list!\n");
    }
};
int count(struct DoublyLinkedList *list){
    int count=0;
    while(list->head!=NULL){
        count++;
        list->head=list->head->next;
    }
    return count;
}

void main(){
    struct DoublyLinkedList *list= createList();
    insertAtEnd(list,20);
    insertAtEnd(list,90);
    insertAtEnd(list,30);
    insertAtEnd(list,80);
    insertAtBeginning(list,45);
    int result=count(list);
    printf("There are %d elements in this list", result);
}

