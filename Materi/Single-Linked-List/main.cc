#include "sll.h"

#define MAXSIZE 10

int main(void) {
    List L;
    
    init_list(L);
    infotype new_data[MAXSIZE] = {1, 4, 3, 7, 10, 0, 2, 23, 5, 4};

    for (int i = 0; i < MAXSIZE; i++)
        insert_sort(L, new_element(new_data[i]));
    
    traversal(L);
}