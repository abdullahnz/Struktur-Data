#include "CLL.h"

// helper
infotype createInfo(string artis, string genre, string judul, int playtime) {
    return infotype {artis, judul, genre, playtime};
}

int main()
{
    listLagu songs;
    adr song, out;

    createList_1301213232(songs);
    
    // createElement_1301213232(createInfo("Avenged Sevenfold", "Rock", "M.I.A", 0), song);
    // insertLast_1301213232(songs, song);

    // createElement_1301213232(createInfo("Jason Mraz", "Pop", "Im Yours", 0), song);
    // insertLast_1301213232(songs, song);

    // createElement_1301213232(createInfo("Joo Won", "Pop", "Fly Me To the Moon", 0), song);
    // insertLast_1301213232(songs, song);

    for (int i = 0; i < 12; i++) {
        createElement_1301213232(createInfo("Avenged Sevenfold", "Rock", "M.I.A", i+1337), song);
        insertLast_1301213232(songs, song);
    }

    showSemuaLagu_1301213232(songs);
    cout << endl;

    for (int i = 0; i < 3; i++) {
        deleteFirst_1301213232(songs, out);
        cout << "Deleting " << info(out).judul << " song that you've played " << info(out).playtime << " times." << endl;
    }

    cout << endl;
    showSemuaLagu_1301213232(songs);
    

    return 0;
}