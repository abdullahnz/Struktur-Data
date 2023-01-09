#include <iostream>
#include <stdlib.h>
using namespace std;

#include "list.h"

#ifdef linux
#define __clearscreen() system("clear")
#else
#define __clearscreen() system("cls")
#endif

 
const string MONTHS[12] = {
    "JAN", 
    "FEB",
    "MAR",
    "APR",
    "MEI",
    "JUN",
    "JUL",
    "AGU",
    "SEP",
    "OKT",
    "NOV",
    "DES"
};

int choice() {
    cout << "== CUSTOMER MANAGEMENT ==" << endl;
    cout << "1) Add Link" << endl
         << "2) Add Customer" << endl
         << "3) Add Contract Customer into Link" << endl
         << "4) Show All Link" << endl    
         << "5) Show All Customer" << endl    
         << "6) Show Link By Customer" << endl    
         << "7) Show Customer By Link" << endl
         << "8) Display Stats" << endl;
    cout << "Input choice: ";
    int inp; cin >> inp;
    return inp;   
}

void initData(List &L) {
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

    for (int i = 10; i > 0; i--)
        L.addCustomer(i, "CUSTOMER_" + to_string(i));
 
    for (int i = 11; i >= 0; i--)
        L.addLink(i + 1, LINKS[i]);

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
}

int main(int argc, char * argv[]) {
    List L;

    int selectedCustId, selectedLinkId;
    string invId, start, end;
    float capacity;

    int inpMonth, inpYear, inpContract, endYear, endContract;
    
    // current customer and link ID after initData();
    int curCustomerId = 11, curLinkId = 13;

    string customerName;
    string linkName;

    int option;
    initData(L);


    for (;;) {
        option = choice();
        switch (option) {
            case 1:
                cout << "Input Link Name (replace space with underscore): "; cin >> linkName;
                L.addLink(curLinkId++, linkName);
                __clearscreen();
                break;
            case 2:
                cout << "Input Customer Name (replace space with underscore): "; cin >> customerName;
                L.addCustomer(curCustomerId++, customerName);
                __clearscreen();
                break;
            case 3:
                cout << "Input Link ID: "; cin >> selectedLinkId;
                cout << "Input Customer ID: "; cin >> selectedCustId;
                cout << "Input Invoice ID: "; cin >> invId;
                cout << "Input Capacity: "; cin >> capacity;            
                cout << "== START CONTRACT ==" << endl;
                for (int i = 0; i < (sizeof(MONTHS)/sizeof(MONTHS[0])) / 2; i++)
                    cout << setw(2) << i+1 << ") " << MONTHS[i] << "\t\t" << setw(2) << i+7 << ") " << MONTHS[i+6] << endl;
                cout << "Input month: "; cin >> inpMonth;
                cout << "Input year: "; cin >> inpYear;
                cout << "Contract (in month): "; cin >> inpContract;
    
                endContract = (inpMonth + inpContract);
                endYear = inpYear;
                if (endContract > 12) {
                    endYear += (endContract / 12);
                }
                addContract(selectedLinkId, selectedCustId, invId, capacity, 
                            MONTHS[inpMonth-1] + " " + to_string(inpYear),
                            MONTHS[(endContract-1) % 12] + " " + to_string(endYear), 
                            L);
                __clearscreen();
                break;
            case 4:
                __clearscreen();
                showAllLink(L);
                break;
            case 5:
                __clearscreen();
                showAllCustomer(L);
                break;
            case 6:
                cout << "Input Customer ID: "; cin >> selectedCustId;
                __clearscreen();
                showLinkByCust(L, selectedCustId);
                break;
            case 7:
                cout << "Input Link ID: "; cin >> selectedLinkId;
                __clearscreen();
                showCustByLink(L, selectedLinkId);
                break;
            case 8:
                __clearscreen();
                showStat(L);
                break;
        };
    }
    return 0;
}

