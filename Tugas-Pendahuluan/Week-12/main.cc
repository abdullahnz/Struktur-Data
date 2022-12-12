#include "flight.h"


int main() {
    listJadwal L;
    adr_jadwalP out;
    infotype p;
    int n;

    createListJadwal(L);

    cout << "== Masukkan Jumlah Penerbangan ==" << endl;
    cout << " > "; cin >> n;

    while (n--) {
        cout << "== Masukkan Jadwal Penerbangan ==" << endl;
        cout << " > Kode     : "; cin >> p.kode;
        cout << " > Jenis    : "; cin >> p.jenis;
        cout << " > Tanggal  : "; cin >> p.tanggal;
        cout << " > Waktu    : "; cin >> p.waktu;
        cout << " > Asal     : "; cin >> p.asal;
        cout << " > Tujuan   : "; cin >> p.tujuan;
        cout << " > Kapasitas: "; cin >> p.kapasitas;
        insertLastJ(L, createElementJadwal(p));
    }
    cout << endl;

    // insertLastJ(L, createElementJadwal(infotype{"A-001", "Boeing", "8-Desember-2022", "10.00", "Surabaya", "Solo", 550}));
    // insertLastJ(L, createElementJadwal(infotype{"A-002", "Airbus", "9-Desember-2022", "11.00", "Surabaya", "Malang", 600}));
    // insertLastJ(L, createElementJadwal(infotype{"A-003", "ATR", "9-Desember-2022", "12.00", "Surabaya", "Malang", 500}));
    // insertLastJ(L, createElementJadwal(infotype{"A-004", "ATR", "10-Desember-2022", "12.00", "Solo", "Malang", 500}));
    // insertLastJ(L, createElementJadwal(infotype{"A-005", "Boeing", "9-Desember-2022", "12.00", "Surabaya", "Malang", 500}));
   
    showJadwal(L);
    
    cout << "== Penerbangan Surabaya - Malang (9-Desember-2022) ==" << endl;
    adr_jadwalP src = searchJ(L, "Surabaya", "Malang", "9-Desember-2022");
    
    if (!src) {
        cout << "Penerbangan tidak ditemukan." << endl;
    } else {
        while (src) {
            cout << "> " << src->info.kode 
                << " | " << src->info.jenis << " (kap: " << src->info.kapasitas << ")" 
                << " | " << src->info.asal  << " - " << src->info.tujuan 
                << " | " << src->info.waktu << " | " << src->info.tanggal 
                << endl;
            src = searchJ(listJadwal{src->next}, "Surabaya", "Malang", "9-Desember-2022");
        }
    }
    return 0;
}