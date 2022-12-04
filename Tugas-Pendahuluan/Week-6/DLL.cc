#include "DLL.h"

void createList_1301213232(List &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address createNewElement_1301213232(infotype info) {
    address p = new Element;
    info(p) = info;
    prev(p) = NULL;
    next(p) = NULL;
    return p;
}

void insertFirst_1301213232(List &L, address p) {
    if (L.first != NULL) {
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    } else {
        first(L) = p;
        last(L) = p;
    }
}

void showAllData_1301213232(List L) {
    if (first(L)) {
        address cur = first(L);
        while (cur) {
            cout << "INFO: " << info(cur).merk << " | " << info(cur).warna << " (id: " << info(cur).id << ")" << endl;
            cur = next(cur);
        }
    } else {
        cout << "INFO: List kosong." << endl;
    }
}

void showEven_1301213232(List L) {
    if (first(L)) {
        address cur = first(L);
        while (cur) {
            if (info(cur).id % 2)
                cout << "INFO: " << info(cur).merk << " | " << info(cur).warna << " (id: " << info(cur).id << ")" << endl;
            cur = next(cur);
        }
    } else {
        cout << "INFO: List kosong." << endl;
    }
}
