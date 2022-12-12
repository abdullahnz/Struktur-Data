#include <iostream>

using namespace std;

struct jadwalPenerbangan {
    string kode, jenis, tanggal, waktu, asal, tujuan;
    int kapasitas;
};

typedef struct elementJadwal *adr_jadwalP;
typedef jadwalPenerbangan infotype;

struct elementJadwal {
    infotype info;
    adr_jadwalP next;
};

struct listJadwal {
    adr_jadwalP first;
};

void createListJadwal(listJadwal &L);
adr_jadwalP createElementJadwal(infotype x);
void insertLastJ(listJadwal &L, adr_jadwalP p);
void showJadwal(listJadwal L);
void deleteFirstJ(listJadwal &L, adr_jadwalP &p);
adr_jadwalP searchJ(listJadwal L, string dari, string ke, string tanggal);

