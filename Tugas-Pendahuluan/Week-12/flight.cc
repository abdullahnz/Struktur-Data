#include "flight.h"

void createListJadwal(listJadwal &L) {
    L.first = NULL;
}

adr_jadwalP createElementJadwal(infotype x) {
    return adr_jadwalP{new elementJadwal{x, NULL} };
}

void insertLastJ(listJadwal &L, adr_jadwalP p) {
    if (!L.first) {
        L.first = p;
    } else {
        adr_jadwalP cur = L.first;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = p;
    }
}


void showJadwal(listJadwal L) {
    if (!L.first) {
        cout << "Tidak ada jadwal penerbangan hari ini." << endl;
    } else {
        cout << "== List Jadwal Penerbangan ==" << endl;
        adr_jadwalP cur = L.first;
        while (cur) {
            cout << "> " << cur->info.kode 
                 << " | " << cur->info.jenis << " (kap: " << cur->info.kapasitas << ")" 
                 << " | " << cur->info.asal  << " - " << cur->info.tujuan 
                 << " | " << cur->info.waktu << " | " << cur->info.tanggal 
                 << endl;
            cur = cur->next;
        }
    }
    cout << endl;
}
void deleteFirstJ(listJadwal &L, adr_jadwalP &p) {
    p = L.first;
    if (L.first) {
        L.first = L.first->next;
    }
}

adr_jadwalP searchJ(listJadwal L, string dari, string ke, string tanggal) {
    adr_jadwalP cur = L.first;

    while (cur && (cur->info.asal != dari || cur->info.tujuan != ke || cur->info.tanggal != tanggal)) {
        cur = cur->next;
    }
    return cur;
}