#include "stdio.h"
#include "stdlib.h"

void insertsort(int list[], int numElements);

int main(){
    int num_items;
    int *items;
    printf("how many items?: ");
    scanf("%d", &num_items);

    items = malloc(sizeof(items) * num_items);
    printf("\nenter %d items: ", num_items);
    for(int i; i < num_items; i++){
        scanf("%d", &items[i]);
    }
    insertsort(items, num_items);
    free(items);
    items = NULL;

}

void insertsort(int list[], int numElements){
    int unsorted;
    int sorted;
    int unsorted_item;
    
    for(unsorted = 1; unsorted < numElements; unsorted++){
        unsorted_item = list[unsorted];
        for(sorted = unsorted-1; sorted >= 0 && list[sorted] > unsorted_item; sorted--){
            list[sorted+1] = list[sorted]; //traverse list
        }
        list[sorted+1] = unsorted_item; //insert item
    }

    putchar('\n');
    for(int i; i < numElements; i++){
        printf("%d ", list[i]);
    }
    putchar('\n');
}
