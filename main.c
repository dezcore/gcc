#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Définition de quelques macros
#define FALSE 0
#define TRUE 1
#define BOOL int 
#define MINI(a, b) a < b ? a : b

int macroTest() {
    int a = 3;
    int b = 6;
    int c = 33;
    int res = MINI(a, b) + 2;
    BOOL state = TRUE;

    if(state == FALSE) {
        printf("res == %d \n", res);
    } else {
        printf("Hello world !");
    }

    return 0;
}

int sizeOfTest() {
    printf("sizeof(char) === %d bytes\n", (int) sizeof(char));
    printf("sizeof(short) === %d bytes\n", (int) sizeof(short));
    printf("sizeof(int) === %d bytes\n", (int) sizeof(int));
    printf("sizeof(long) === %d bytes\n", (int) sizeof(long));
    return 0;
}

int testList() {
    List l = listCreate();
    listDisplay(l);
    printf("\n");

    listAdd(&l, 20);
    listDisplay(l);
    printf("\n");

    listAdd(&l, 30);
    listDisplay(l);
    printf("\n");

    listAdd(&l, 10);
    listDisplay(l);
    printf("\n");

    listAdd(&l, 50);
    listDisplay(l);
    printf("\n");

    listAdd(&l, 40);
    listDisplay(l);
    printf("\n");

    printf("Size Before == %lu\n", listSize(l));

    listClear(&l);
    listDisplay(l);
    printf("\n");
    printf("Size After == %lu\n", listSize(l));

    return 0;
}

int main() {
    testList();
    return 0;
}