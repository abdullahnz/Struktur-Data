#ifndef DLL_INCLUDED

#define DLL_INCLUDED
#include <iostream>

using namespace std;

#define first(L) (L).first
#define last(L) (L).last
#define next(p) (p)->next
#define prev(p) (p)->prev
#define info(p) (p)->info
#define INT_MAX 0x7fffffff

struct AsuransiBarang {
    int id, lama_pengiriman;
    string nama, barang;
};

typedef AsuransiBarang infotype;
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
void showAllData_1301213232(List L);
void insertFirst_1301213232(List &L, address p);
void reverseList_1301213232(List &L);
float secondSmallest_1301213232(List L);

#endif