#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List listCreate() {
    List l;
    l.head = NULL;
    return l;
}

Node * listNodeAdd(Node * listNode, ELEMENT_TYPE value ) {

    if(listNode == NULL || value < listNode->value) {
        Node * newNode = (Node *) malloc(sizeof(Node));

        if(newNode == NULL){
            fputs( "Cannot allocate a new list node\n", stderr );
            exit(EXIT_FAILURE);
        }
        newNode->value = value;
        newNode->next = listNode;
        return newNode;
    }

    listNode->next = listNodeAdd(listNode->next, value);
    return listNode;
}

void listAdd(List * list, ELEMENT_TYPE value) {
    list->head = listNodeAdd(list->head, value);
}

size_t listSize(List list ) {
    size_t length = 0;

    Node * currentNode = list.head;

    while(currentNode != NULL) {
        length++;
        currentNode = currentNode->next;
    }

    return length;
}

void listDisplay( List list ) {
    Node * currentNode = list.head;

    printf( "[" );
    while(currentNode != NULL) {
        printf( "%d", currentNode->value );
        currentNode = currentNode->next;
        if(currentNode != NULL) printf( ", " );
    }
    printf( "]" );
}

void listClear( List * list ) {
    Node * currentNode = list->head;

    while(currentNode != NULL) {
        Node * nodeToDelete = currentNode;
        currentNode = currentNode->next;
        free(nodeToDelete);
    }

    list->head = NULL;
}