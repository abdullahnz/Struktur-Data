#include "sll.h"
 
void create_list(List &L) {
   first(L) = NULL;
}
 
address create_new_element(infotype info) {
   return new Element(info, NULL);
}
 
void insert_last(List &L, address elm) {
   if (first(L) == NULL) {
       first(L) = elm;
   } else {
       address cur = first(L);
       while (next(cur) != NULL)
           cur = next(cur);
       next(cur) = elm;
   }
}
 
void show_all_data(List L) {
   if (first(L) == NULL) {
       cout << "List Kosong" << endl;
   } else {
       address cur = first(L);
       while (cur != NULL) {
           cout << info(cur) << " ";
           cur = next(cur);
       }
       cout << endl;
   }
}
 
address find_max(List L) {
   if (first(L) != NULL) {
       address max = first(L);
       address cur = next(max);
       while (cur != NULL) {
           if (info(cur) > info(max))
               max = cur;
           cur = next(cur);
       }
       return max;
   }
   return NULL;
}
 
void show_middle(List L) {
   if (first(L) != NULL) {
       int sz = 0;
       address cur = first(L);
       while (cur != NULL) {
           sz++;
           cur = next(cur);
       }
       cur = first(L);
       sz = sz / 2;
       while (sz--)
           cur = next(cur);
       cout << info(cur) << endl;
   } else {
       cout << "List Kosong" << endl;
   }
}
