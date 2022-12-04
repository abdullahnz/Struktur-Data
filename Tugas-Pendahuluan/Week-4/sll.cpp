#include "sll.h"

void create_list(List &N) {
    first(N) = nil;
}

adr new_element(infotype x) {
    adr p = new element;
    info(p) = x;
    next(p) = nil;
    return p;
}

void insert_first(List &N, adr p) {
    if (first(N) == nil) {
                first(N) = p;
    } else {
            next(p) = first(N);
            first(N) = p;
    }
}

void insert_after(List &N, adr p, infotype x) {
    if (first(N) != nil) {
            adr q = first(N);
            while (q != nil && info(q) != x) {
                    q = next(q);
            }
            if (q != nil) {
                    adr tmp = next(q);
                    next(q) = p;
                    next(next(q)) = tmp;
            }
    }

}

void insert_last(List &N, adr p) {
    if (first(N) == nil) {
            first(N) = p;
    } else {
            adr q = first(N);
            while (next(q) != nil) {
                    q = next(q);
            }
            next(q) = p;
    }
    // cout << "DEBUG: " << info(q) << endl;
}

void show(List N) {
    adr p;
    if (first(N) != nil) {
            p = first(N);
            while (p != nil) {
                    cout << info(p) << " ";
                    p = next(p);
            }
            cout << endl;
    } else {
            cout << "List Kosong" << endl;
    }
}

adr delete_last(List &N) {
    adr p, q;
    if (first(N) == nil) {
            p = nil;
            cout << "List Kosong" << endl;
    } else if (next(first(N)) == nil) {
            p = first(N);
            first(N) = nil;
    } else {
            q = first(N);
            p = first(N);
            while (next(p) != nil) {
                    q = p;
                    p = next(p);
            }
            next(q) = nil;
    }
    return p;
}
