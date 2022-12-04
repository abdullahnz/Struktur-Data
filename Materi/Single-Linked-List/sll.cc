#include "sll.h"

void init_list(List &L) {
    first(L) = NULL;
}

address new_element(infotype info) {
    address p = new element;
    info(p) = info;
    next(p) = NULL;
    return p;
}

void insert_first(List &L, address p) {
    if (first(L) == NULL)
        first(L) = p;
    else {
        next(p) = first(L);
        first(L) = p;
    }
}

void insert_after(List &L, address prec, address p) {
    next(p) = next(prec);
    next(prec) = p;
}

void insert_sort(List &L, address p) {
    if (first(L) == NULL) {
        insert_first(L, p);
    } else {
        address prec = first(L);
        if (info(p) < info(prec)) {
            insert_first(L, p);
        } else {
            while (next(prec) != NULL && info(p) > info(next(prec))) {
                prec = next(prec);
            }
            insert_after(L, prec, p);
        }
    }
}

void traversal(List L) {
    if (first(L) != NULL) {
        address cur = first(L);
        while (cur != NULL) {
            cout << info(cur) << " ";
            cur = next(cur);
        }
        cout << endl;
    } 
}