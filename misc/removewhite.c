#include "stdio.h"

int main(){
    char c;

    while((c = getchar()) != '\n'){
        if(c == ' ' || c == '\t') putchar('\0');
        else putchar(c); 
    }
}
