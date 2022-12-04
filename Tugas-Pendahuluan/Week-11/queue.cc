#include "queue.h"

void createPlaylist(playlistLagu &Q) {
    Q.head = NULL;
    Q.tail = NULL;
}

void createElement(infotype laguBaru, adr &pLagu) {
    pLagu = new element;
    pLagu->info = laguBaru;
    pLagu->next = NULL;
}

void enqueue(playlistLagu &Q, adr pLagu) {
    if (!Q.head && !Q.tail) {
        Q.head = pLagu;
        Q.tail = pLagu;
    } else {
        Q.tail->next = pLagu;
        Q.tail = pLagu;
    }
}

void dequeue(playlistLagu &Q, adr &pLagu) {
    pLagu = NULL;
    if (Q.head && Q.tail) {
        pLagu = Q.head;
        
        if (Q.head != Q.tail) {
            Q.head = Q.head->next;

        } else {
            Q.head = NULL;
            Q.tail = NULL;
        }
    }
}

void showSemuaLagu(playlistLagu Q) {
    if (!Q.head && !Q.tail) {
        cout << "Playlist lagu anda kosong." << endl;
    } else {
        cout << "My Playlist:" << endl;
        adr cur = Q.head;
        while (cur) {
            cout << "> " << cur->info.artis 
                << " - " << cur->info.judul << endl;
            cur = cur->next;
        }
    }
}
