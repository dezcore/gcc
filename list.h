#ifndef LIST_H_
#define LIST_H_


#define ELEMENT_TYPE int

typedef struct _Node {
    ELEMENT_TYPE value;
    struct _Node * next;
} Node;

typedef struct _LIST {
    Node * head;
} List;

List listCreate();
void listAdd( List * l, ELEMENT_TYPE e );
size_t listSize( List l );
void listDisplay( List l );
void listClear( List * l );

#endif