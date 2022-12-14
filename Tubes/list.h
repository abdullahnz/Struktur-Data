#include <iostream>
#include <iomanip>

using namespace std;

struct Customer {
    int custId;
    string name;
    Customer *next;
};

struct Relation {
    string invId;
    Customer *customer;
    float capacity;
    string start, end;
    Relation *next;
};

struct Link {
    int linkId;
    string linkName;
    float cntCapacity;
    int cntCustomer;
    Relation *relation;
    Link *next;
};

struct List {
    Customer *customer;
    Link *link;

    // constructor
    List() {
        this->customer = NULL;
        this->link = NULL;
    }
    // primitive
    void addCustomer(int, string);
    void addLink(int, string);
    Customer *findCustomer(int);
    Link *findLink(int);

};

void infoRelation(Relation *rel);

void showAllLink(List L);
void showAllCustomer(List L);
void addContract(int linkId, int custId, string invId, float capacity, string start, string end, List & L);
void showLinkByCust(List, int);
void showCustByLink(List, int);
void showStat(List);