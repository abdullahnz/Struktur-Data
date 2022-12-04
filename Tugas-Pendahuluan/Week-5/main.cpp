#include "sll.h"
 
#define JUM_DATA_PROMPT "Jumlah data yang ditambahkan: "
#define DATA_BARU_PROMPT "Masukkan data baru: "
 
infotype read_data(string msg) {
   infotype data;
   cout << msg;
   cin  >> data;
   return data;
}
 
int main() {
   int choice, n;
   List L;
   address max;
  
   create_list(L);
  
   for (;;) {
       cout << "== MENU ==\n"
               "1. Menambahkan N data baru\n"
               "2. Menampilkan semua data\n"
               "3. Menampilkan nilai maksimum\n"
               "4. Menampilkan nilai tengah\n"
               "0. Exit\n"
               "Masukkan menu: ";
       cin >> choice;
       switch (choice) {
           case 1:
               first(L) = NULL;
               n = read_data(JUM_DATA_PROMPT);
               while (n--)
                   insert_last(L, create_new_element(read_data(DATA_BARU_PROMPT)));
               break;
           case 2:
               show_all_data(L);
               break;
           case 3:
               max = find_max(L);
               if (max != NULL)
                   cout << info(max) << endl;
               else
                   cout << "List Kosong" << endl;
               break;
           case 4:
               show_middle(L);
               break;
           case 0:
               goto EXIT;
               break;
           default:
               cout << "Invalid choice" << endl;
               break;
       }
   }
 
   EXIT:
   return 0;
}
