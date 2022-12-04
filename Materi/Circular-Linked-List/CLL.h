#include <iostream>

using namespace std;

#define info(p) p->info
#define next(p) p->next
#define first(L) L.first

typedef int infotype;
typedef struct Element *address;

struct Element {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createNewList(List &L);
address createNewElement(infotype info);

void insertList(List &L, address p);
void deleteElement(List &L, infotype info, address &out);

void traversal(List L);