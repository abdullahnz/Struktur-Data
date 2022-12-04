#include <iostream>
#include "sll.h"

int main() {
    List L;

    create_list(L);
    
    insert_last(L, new_element(1));
    insert_last(L, new_element(2));
    insert_last(L, new_element(3));
    insert_last(L, new_element(4));
    insert_last(L, new_element(5));

    show(L);

    insert_after(L, new_element(8), 3);
    insert_after(L, new_element(7), 3);

    show(L);

    return 0;
}

