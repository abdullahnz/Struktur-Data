#include "DLL.h"



int main() {
    List L;
    AsuransiBarang p;

    createList_1301213232(L);

    int choice = -1;
    int n;


    while(1) {
        cout << "== Menu ==" << endl;
        cout << "1 - Menambahkan N data baru" << endl;
        cout << "2 - Menampilkan semua data" << endl;
        cout << "3 - Reverse list" << endl;
        cout << "4 - Menampilkan lama pengiriman kedua" << endl;
        cout << "0 - Exit" << endl;
        cout << "Masukkan menu: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Masukkan jumlah data yang akan ditambahkan: ";
                cin >> n;
                
                while (n--) {
                    cout << "Masukkan id nasabah: ";
                    cin >> p.id;

                    cout << "Masukkan nama nasabah: ";
                    cin >> p.nama;

                    cout << "Masukkan nama barang: ";
                    cin >> p.barang;

                    cout << "Masukkan lama pengiriman (dalam hari): ";
                    cin >> p.lama_pengiriman;

                    insertFirst_1301213232(L, createNewElement_1301213232(p));
                }
                break;
            case 2:
                showAllData_1301213232(L); break;
            case 3:
                reverseList_1301213232(L); break;
            case 4:
                cout << "Lama pengiriman terkecil kedua adalah " << secondSmallest_1301213232(L) << " hari." << endl; break;
            case 0:
                exit(1);
            default:
                cout << "ERROR: Invalid choice" << endl; break;

        }

    }
    EXIT:
    return 0;
}