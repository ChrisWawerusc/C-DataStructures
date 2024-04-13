#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
//Adds at beginning of list
void Push(struct Node **head_ref , int data){
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=(*head_ref);
    (*head_ref)=newNode;
}
//appends at end
void appendNode(struct Node **head_ref , int data){
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;

    struct Node *last = *head_ref;
    if(*head_ref==NULL){
        *head_ref=newNode;
        return ;
    }else{
        while (last->next!=NULL)
        {
            last=last->next;
        }
        last->next=newNode;
        return;
    }
     
}

// Main function
int main() {
    struct Node *head=NULL;
    struct Node *node1=createNode(10);
    head=node1;
    appendNode(&head,100);
    appendNode(&head,20);
    appendNode(&head,30);
    appendNode(&head,40);
    
    struct Node* current = node1;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Free allocated memory
    free(node1);
    
}
