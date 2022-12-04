#include <iostream>

using namespace std;

struct infotype {
    string artis, judul;
};

typedef struct element *adr;

struct element {
    infotype info;
    adr next;
};

struct playlistLagu {
    adr head, tail;
};

void createPlaylist(playlistLagu &Q);
void createElement(infotype laguBaru, adr &pLagu);
void enqueue(playlistLagu &Q, adr pLagu);
void dequeue(playlistLagu &Q, adr &pLagu);
void showSemuaLagu(playlistLagu Q);
