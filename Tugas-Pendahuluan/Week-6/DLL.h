#ifndef DLL_INCLUDED

#define DLL_INCLUDED
#include <iostream>

using namespace std;

#define first(L) (L).first
#define last(L) (L).last
#define next(p) (p)->next
#define prev(p) (p)->prev
#define info(p) (p)->info

struct Sepeda {
    int id;
    string merk, warna;
};

typedef Sepeda infotype;
typedef struct Element *address;

struct Element {
    infotype info;
    address prev, next;
};

struct List {
    address first, last;
};

void createList_1301213232(List &L);
address createNewElement_1301213232(infotype info);
void insertFirst_1301213232(List &L, address p);
void showAllData_1301213232(List L);
void showEven_1301213232(List L);

#endif