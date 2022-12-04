#include "DLL.h"

void createNewList(List &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address createNewElement(infotype info) {
    return address{new Element {info, NULL, NULL}};
}

void insertList(List &L, address p) {
    if (!first(L)) {
        // insertFirst
        first(L) = p;
        last(L) = p;
    } else if (info(first(L)) > info(p)) {
        // insertFirst
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    } else {
        address q = next(first(L));
        while (q && info(q) < info(p)) {
            q = next(q);
        }
        if (q) {
            q = prev(q);
            // insertAfter
            next(p) = next(q);
            prev(p) = q;
            prev(next(q)) = p;
            next(q) = p;
        } else {
            // insertLast
            next(last(L)) = p;
            prev(p) = last(L);
            last(L) = p;
        }
    }   
}

void deleteElement(List &L, infotype info, address &out) {
    address cur = first(L);
    while (cur && info(cur) != info) {
        cur = next(cur);
    }
    if (cur) {
        out = cur;
        if (!prev(cur)) {
            first(L) = next(cur);
            prev(cur) = NULL;
        } else if (!next(cur)) {
            last(L) = prev(cur);
            next(last(L)) = NULL;
        } else {
            next(prev(cur)) = next(cur);
            prev(next(cur)) = prev(cur);
        }
        next(out) = NULL;
        prev(out) = NULL;
    }
    out = address{new Element {-1, 0, 0}};
}

void traversal(List L) {
    address cur = first(L);
    while (cur) {
        cout << "INFO: infotype: " << info(cur) << " | next: " << next(cur) << " | prev: " << prev(cur) << endl;
        cur = next(cur);
    }
}

void reverse(List &L) {
    address p = first(L);
    address q = last(L);

    while (p != q && prev(p) != q) {
        infotype temp = info(p);
        info(p) = info(q);
        info(q) = temp;
        p = next(p);
        q = prev(q);
    }
}