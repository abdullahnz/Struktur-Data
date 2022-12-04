#include "queue.h"

// my helper
infotype createLagu(string artis, string judul) {
    return infotype {artis, judul};
}

int main() {
    playlistLagu Q;
    adr pLagu;
    
    createPlaylist(Q);

    int nLagu = 5 + 2;
    for (int i = 0; i < nLagu; i++) {
        createElement(createLagu("Artis-" + to_string(i + 1), 
                                "Lagu-" + to_string(i + 1)), pLagu); 
        enqueue(Q, pLagu);
    }
    
    showSemuaLagu(Q);

    cout << endl;
    
    for (int i = 0; i < nLagu; i++) {
        dequeue(Q, pLagu);
        cout << pLagu->info.judul << " selesai diputar." << endl << endl;
        showSemuaLagu(Q); cout << endl;

    }
}