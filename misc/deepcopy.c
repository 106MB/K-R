#include <stdio.h>
#include <stdlib.h>
//program to practice deep copy of linked list
struct node {
    int data;
    struct node * next;
};

void addNode(int item, struct node * list);
void printList(struct node * list);
void iterativeCopy(struct node *list, struct node *copyList);


int main(){
    struct node *list;
    struct node *copyList;
    list = malloc(sizeof(struct node));
    list->next = NULL;
    list->data = 0;
    copyList = malloc(sizeof(struct node));
    copyList->next = NULL;
    copyList->data = 0;
    addNode(6, list);
    addNode(10, list);
    addNode(420, list);
    addNode(106, list);
    iterativeCopy(list, copyList);
    //recursiveCopy(list, copyList);
    printList(list);
    printList(copyList);
}

void addNode(int item, struct node * list){
    
    struct node * newNode;
    newNode = malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("No Memory\n");
        exit(1);
    }
    
    newNode->data = item;
    newNode->next = NULL;
   
    if(list->next == NULL){
        list->next = newNode;
    } else {
        struct node *current;
        current = list;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(struct node *list){
    struct node *current;
    current = list->next;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

void iterativeCopy(struct node *list, struct node *copyList){
    struct node *current;
    current = list->next;
   
    while(current != NULL){
        addNode(current->data, copyList);
        current = current->next;
        
    }
}
