#include <iostream>

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define nil NULL

using namespace std;

typedef int infotype;
typedef struct element *adr;

struct element {
    infotype info;
    adr next;
};

struct List {
    adr first;
};

void create_list(List &N);
adr new_element(infotype x);
void insert_first(List &N, adr p);
void insert_after(List &N, adr p, int x);
void insert_last(List &N, adr p);
void show(List N);
adr delete_last(List &N);
