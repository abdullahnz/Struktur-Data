#include <iostream>

using namespace std;

#define info(p) p->info
#define next(p) p->next
#define prev(p) p->prev
#define first(L) L.first
#define last(L) L.last

typedef int infotype;
typedef struct Element *address;

struct Element {
    infotype info;
    address prev, next;
};

struct List {
    address first, last;
};

void createNewList(List &L);
address createNewElement(infotype info);

void insertList(List &L, address p);
void deleteElement(List &L, infotype info, address &out);

void traversal(List L);
void reverse(List &L);