#include "CLL.h"

int main(void) {
    List L;
    address out;

    createNewList(L);

    insertList(L, createNewElement(1));
    insertList(L, createNewElement(3));
    insertList(L, createNewElement(5));
    insertList(L, createNewElement(2));
    insertList(L, createNewElement(4));
    insertList(L, createNewElement(0));

    traversal(L);
}