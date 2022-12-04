#include <iostream>

#define first(L) (L).first
#define next(p) (p)->next
#define info(p) (p)->info

using namespace std;

struct infotype {
    string artis, judul, genre;
    int playtime;
};

typedef struct element *adr;

struct element {
    infotype info;
    adr next;
};

struct listLagu {
    adr first;
};

void createList_1301213232(listLagu &L);
void createElement_1301213232(infotype lagubaru, adr &pLagu);

void insertLast_1301213232(listLagu &L, adr pLagu);
void deleteFirst_1301213232(listLagu &L, adr &pLagu);

void showSemuaLagu_1301213232(listLagu L);
