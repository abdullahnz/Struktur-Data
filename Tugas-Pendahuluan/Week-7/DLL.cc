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
            cout << "INFO: " << info(cur).nama << " | " << info(cur).barang << " | " << info(cur).lama_pengiriman << " hari " << " (id: " << info(cur).id << ")" << endl;
            cur = next(cur);
        }
    } else {
        cout << "INFO: List kosong." << endl;
    }
}

float secondSmallest_1301213232(List L) {
    int firstMin, secondMin;
    address cur = first(L);

    firstMin = info(cur).lama_pengiriman;
    cur = next(cur);

    while (cur) {
        if (info(cur).lama_pengiriman < firstMin) {
            secondMin = firstMin;
            firstMin = info(cur).lama_pengiriman;
        } else if (info(cur).lama_pengiriman < secondMin && info(cur).lama_pengiriman != firstMin) {
            secondMin = info(cur).lama_pengiriman;
        }
        cur = next(cur);
    }
    
    return secondMin;
}

void reverseList_1301213232(List &L) {
    address temp, cur;
    
    if (first(L)) {
        cur = first(L);
        while (cur) {
            temp = prev(cur);
            prev(cur) = next(cur);
            next(cur) = temp;
            cur = prev(cur);
        }
        
        if (temp) {
            first(L) = prev(temp);
        }
    }
}
