#include "CLL.h"

void createNewList(List &L) {
    first(L) = NULL;
}

address createNewElement(infotype info) {
    return address{new Element {info, NULL}};
}

void insertList(List &L, address p) {
    if (!first(L)) {
        first(L) = p;
        next(p) = first(L);
    } else if (info(first(L)) > info(p)) {
        next(p) = first(L);
        address cur = next(first(L));
        while (next(cur) != first(L)) {
            cur = next(cur);
        }
        next(cur) = p;
        first(L) = p;
    } else {
        address cur = next(first(L));
        address prev = first(L);

        while (cur != first(L) && info(cur) < info(p)) {
            prev = cur;
            cur = next(cur);
        }
        
        if (cur != first(L)) {
            next(p) = cur;
            next(prev) = p;
        } else {
            next(p) = first(L);
            next(prev) = p;
        }
    }
}

void deleteElement(List &L, infotype info, address &out);

void traversal(List L) {
    address cur = first(L);
    while (next(cur) != first(L)) {
        cout << "INFO: infotype: " << info(cur) << " | next: " << next(cur) << endl;
        cur = next(cur);
    }
    cout << "INFO: infotype: " << info(cur) << " | next: " << next(cur) << endl;
}