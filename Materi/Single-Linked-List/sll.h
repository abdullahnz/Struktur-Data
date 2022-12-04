#include <iostream>

using namespace std;

#define next(p) p->next
#define info(p) p->info
#define first(L) L.first

typedef int infotype;
typedef struct element *address;

struct element {
    infotype info;
    address next;
};

struct List {
    address first;
};

void init_list(List &L);
address new_element(infotype info);
void insert_first(List &L, address p);
void insert_after(List &L, address prec, address p);
void insert_sort(List &L, address p);
void traversal(List L);