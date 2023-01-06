#include <iostream>
using namespace std;

#include "list.h"

int main(int argc, char * argv[]) {
    List L;

    const string LINKS[12] = {
        "WAI-SAB",
        "SAB-BAA",
        "BAA-KUP",
        "ALO-WTR",
        "WTR-TIA",
        "TIA-SAU",
        "SAU-TUA",
        "TUA-DOB",
        "DOB-TIM",
        "BIA-SOR",
        "SOR-NUM",
        "NUM-MAN"
    };

    // tambah dan show data customer
    for (int i = 10; i > 0; i--)
        L.addCustomer(i, "CUSTOMER_" + to_string(i));
    showAllCustomer(L);

    // tambah dan show data link
    for (int i = 11; i >= 0; i--)
        L.addLink(i + 1, LINKS[i]);
    showAllLink(L);

    // tambah relasi antara link dan customer
    addContract(10, 10, "INV110", 1.0, "JUL 2022", "JAN 2023", L);
    addContract(9, 9, "INV010", 2.5, "JUN 2022", "JAN 2023", L);
    addContract(8, 10, "INV0010", 10.0, "JUN 2022", "OKT 2022", L);
    addContract(8, 9, "INV019", 10.0, "MEI 2022", "SEPT 2022", L);
    addContract(8, 8, "INV109", 2.5, "MEI 2022", "OKT 2022", L);
    addContract(7, 10, "INV009", 2.5, "JUN 2022", "OKT 2022", L);
    addContract(7, 9, "INV018", 1.0, "MEI 2022", "SEPT 2022", L);
    addContract(7, 8, "INV108", 1.0, "APR 2022", "OKT 2022", L);
    addContract(6, 8, "INV008", 10.0, "JUN 2022", "DES 2022", L);
    addContract(6, 7, "INV017", 2.5, "MEI 2022", "NOV 2022", L);
    addContract(6, 6, "INV107", 1.0, "APR 2022", "OKT 2022", L);
    addContract(5, 8, "INV007", 10.0, "JUN 2022", "DES 2022", L);
    addContract(5, 7, "INV106", 2.5, "MEI 2022", "NOV 2022", L);
    addContract(5, 6, "INV006", 1.0, "APR 2022", "OKT 2022", L);
    addContract(4, 5, "INV105", 1.0, "MAR 2022", "NOV 2022", L);
    addContract(4, 4, "INV005", 10.0, "MAR 2022", "OKT 2022", L);
    addContract(4, 3, "INV104", 2.5, "FEB 2022", "SEP 2022", L);
    addContract(3, 5, "INV004", 1.0, "MAR 2022", "NOV 2022", L);
    addContract(3, 4, "INV103", 10.0, "MAR 2022", "OKT 2022", L);
    addContract(3, 3, "INV003", 2.5, "FEB 2022", "SEP 2022", L);
    addContract(2, 3, "INV012", 10.0, "MAR 2022", "MAR 2023", L);
    addContract(2, 2, "INV102", 2.5, "FEB 2022", "FEB 2023", L);
    addContract(2, 1, "INV002", 1.0, "JAN 2022", "JAN 2023", L);
    addContract(1, 3, "INV011", 10.0, "MAR 2022", "MAR 2023", L);
    addContract(1, 2, "INV101", 2.5, "FEB 2022", "FEB 2023", L);
    addContract(1, 1, "INV001", 1.0, "JAN 2022", "JAN 2023", L);

    showCustByLink(L, 1);
    showLinkByCust(L, 3);
    showStat(L);

    return 0;
}