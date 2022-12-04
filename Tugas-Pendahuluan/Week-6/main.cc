#include "DLL.h"

// helper
Sepeda createNewSepeda_1301213232(int id, string merk, string warna) {
    Sepeda s;
    s.id = id;
    s.merk = merk;
    s.warna = warna;
    return s;
}

int main() {
    List L;

    createList_1301213232(L);

    int choice = -1;
    int n, id = -1;
    string merk, warna;

     
    for (;;) {
        cout << "== Menu ==" << endl;
        cout << "1 - Menambahkan N data baru" << endl;
        cout << "2 - Menampilkan semua data" << endl;
        cout << "3 - Menampilkan data yang memiliki id ganjil" << endl;
        cout << "0 - Exit" << endl;
        cout << "Masukkan menu: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Masukkan jumlah data yang akan ditambahkan: ";
                cin >> n;
                
                while (n--) {
                    cout << "Masukkan nomor sepeda: ";
                    cin >> id;

                    cout << "Masukkan merk sepeda: ";
                    cin >> merk;

                    cout << "Masukkan warna sepeda: ";
                    cin >> warna;

                    insertFirst_1301213232(L, createNewElement_1301213232(createNewSepeda_1301213232(id, merk, warna)));
                }
                break;
            case 2:
                showAllData_1301213232(L); break;
            case 3:
                showEven_1301213232(L); break;
            case 0:
                goto EXIT;
            default:
                cout << "ERROR: Invalid choice" << endl; break;

        }

    }
    EXIT:
    return 0;
}