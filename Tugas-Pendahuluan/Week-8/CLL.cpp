#include "CLL.h"


void createList_1301213232(listLagu &L) {
    first(L) = NULL;
}

void createElement_1301213232(infotype lagubaru, adr &pLagu) {
    pLagu = new element;
    info(pLagu) = lagubaru;
    next(pLagu) = NULL;
}

void insertLast_1301213232(listLagu &L, adr pLagu) {
    if (first(L) == NULL) {
        first(L) = pLagu;
        next(pLagu) = first(L);
    } else {
        adr p = first(L);
        while (next(p) != first(L)) {
            p = next(p);
        }
        next(p) = pLagu;
        next(pLagu) = first(L);
    }
}

void deleteFirst_1301213232(listLagu &L, adr &pLagu) {
    if (first(L) != NULL) {
        pLagu = first(L);

        adr lastElement = first(L);
        while (next(lastElement) != first(L)) {
            lastElement = next(lastElement);
        }
        first(L) = next(first(L));
        next(lastElement) = first(L);
        next(pLagu) = NULL;
    }
}

void showSemuaLagu_1301213232(listLagu L) {
    adr p = first(L);
    do {
        cout << "Lagu: " << info(p).judul << " (" << info(p).genre << ") " << "- " << info(p).artis << " - Played " << info(p).playtime << " times." << endl;
        p = next(p);
    } while (p != first(L));
}