#include <iostream>
 
using namespace std;
 
#define first(L) (L).first
#define next(P) (P)->next
#define info(P) (P)->info
 
typedef int infotype;
typedef struct Element *address;
 
struct Element {
   infotype info;
   address next;
   Element(infotype info, Element *next){
       this->info = info;
       this->next = NULL;
   };
};
struct List {
   struct Element *first;
};
 
void create_list(List &L);
address create_new_element(infotype info);
void insert_last(List &L, address elm);
void show_all_data(List L);
address find_max(List L);
void show_middle(List L);