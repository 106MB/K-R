#include "stdio.h"

struct node{
    int count;
    struct node *next;
};

int main(){
    int data = 0;
    struct node *getdata = NULL;
    
    //if getdata was not initialized, this statement would cause a runtime error
    //must initialize pointer before accessing data getting pointed to.
    getdata->count = data + 1;
    printf("%d", getdata->count);
}
