//basic implementation of linked list in C
#include "stdio.h"
#include "stdlib.h"
#define EXIT 6

struct node{
    int data;
    struct node *next;
};

//core functions
void insert(struct node *headptr);
void delete(struct node *headptr);
void search(struct node *headptr);
void insertFront(struct node *headptr);

//helper functions
struct node *traverse(struct node *headptr, int data);
void print(struct node *headptr);



int main(){
    int flag = 0; //flag for user input
    struct node headnode;
    headnode.next = NULL; //init head node

    printf("\n\t******************\n");
    printf("\t**Welcome to the**\n");
    printf("\t** Linked List  **\n");
    printf("\t******************\n");

    while(flag != EXIT){
        printf("\n1) Insert\n2) Delete\n3) Search\n4) Print\n5) Insert Front\n6) Exit\n");
        printf("\nChoose an option: ");
        scanf("%d", &flag);
        switch(flag){
            case 1:
                insert(&headnode);
                break;
            case 2:
                delete(&headnode);
                break;
            case 3:
                search(&headnode);
                break;
            case 4:
                print(&headnode);
                break;
            case 5:
                insertFront(&headnode);
                break;
            case 6:
                printf("\nGoodbye\n\n");
                break;
            default:
                printf("\nInvalid Input\n");
                break;
        }
    }
}

void insert(struct node *headptr){
    struct node *newNode;
    struct node *prevNode;
    struct node *nextNode;

    newNode = malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("Error: Unable to create node\n");
        free(newNode);
        exit(1);
    }

    printf("Enter item to insert: ");
    scanf("%d", &newNode->data);
    
    //traverse list and return node address before new node
    prevNode = traverse(headptr, newNode->data);
    nextNode = prevNode->next;

    if(nextNode == NULL || nextNode->data != newNode->data){
        //insert node
        prevNode->next = newNode;
        newNode->next = nextNode;
        printf("\nItem added\n");
    } else {
        printf("\nItem already entered!\n");
        free(newNode);
    }

}

void delete(struct node *headptr){
    struct node *prevNode;
    struct node *delNode;
    int data; // data to be deleted

    printf("Enter item to be deleted: ");
    scanf("%d", &data);

    prevNode = traverse(headptr, data);
    delNode = prevNode->next;

    if(delNode != NULL && delNode->data == data){
        prevNode->next = delNode->next;
        free(delNode);
        delNode = NULL;
        printf("\nItem deleted\n");
    } else {
        printf("\nItem does not exist!\n");
    }

}

void search(struct node *headptr){
    struct node *prevNode;
    struct node *searchNode;
    int data; // item to be searched for

    printf("Enter item to search for: ");
    scanf("%d", &data);

    prevNode = traverse(headptr, data);
    searchNode = prevNode->next;

    if(searchNode != NULL && searchNode->data == data){
        printf("\nItem found!\n");
    } else {
        printf("\nItem does not exist!\n");
    }
}

void insertFront(struct node *headptr){
    struct node *newNode;
    int data;

    newNode = malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("Unable to add item\n");
        exit(1);
    }

    printf("\nEnter item: ");
    scanf("%d", &data);

    
        newNode->data = data;
        newNode->next = headptr->next;
        headptr->next = newNode;
        printf("\nitem Added\n");
    
    

    

}



//helper functions
struct node *traverse(struct node *headptr, int data){
    struct node *previous = headptr;
    struct node *current = headptr->next;

    while(current != NULL && current->data < data){
        previous = current;
        current = current->next;
    }

    return previous;
}

void print(struct node *headptr){
    struct node *current = headptr->next;
    
    putchar('\n');
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

