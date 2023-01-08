#include "list.h"

void List::addCustomer(int custId, string name) {
    Customer *newCustomer = new Customer {
        custId,
        name,
        NULL
    };

    if (this->customer)
        newCustomer->next = this->customer;

    this->customer = newCustomer;
}

void List::addLink(int linkId, string name) {
    Link *newLink = new Link {
        linkId,
        name,
        0,
        0,
        NULL,
        NULL
    };
    if (this->link)
        newLink->next = this->link;

    this->link = newLink;
}

Customer *List::findCustomer(int custId) {
    Customer *cust = this->customer;
    while (cust && cust->custId != custId)
        cust = cust->next;
    return cust;
}

Link *List::findLink(int linkId) {
    Link *link = this->link;
    while (link && link->linkId != linkId)
        link = link->next;
    return link;
}

void showAllLink(List L) {
    Link *curLink = L.link;
    cout << "== List All Links ==" << endl;
    cout << "ID" << "\t" << "LINK" << endl;
    while (curLink) {
        cout << curLink->linkId << "\t" << curLink->linkName << endl;
        curLink = curLink->next;
    }
    cout << endl;

}

void showAllCustomer(List L) {
    Customer *curCust = L.customer;

    cout << "== List All Customers ==" << endl <<
        "ID\tNAME" << endl;

    while (curCust) {
        cout << curCust->custId << "\t" << curCust->name << endl;
        curCust = curCust->next;
    }
    cout << endl;
}

void addContract(int linkId, int custId, string invId, float capacity, string start, string end, List &L) {
    // find link by id
    Link *link = L.findLink(linkId);
    if (!link) {
        cout << "LINK ID NOT FOUND !" << endl;
    } else {
        // find customer by id
        Customer *cust = L.findCustomer(custId);
        if (!cust) {
            cout << "CUSTOMER ID NOT FOUND !" << endl;
        } else {
            Relation *rel = new Relation {
                invId,
                cust,
                capacity,
                start,
                end,
                NULL
            };
            // add relation
            if (link->relation)
                rel->next = link->relation;
            link->relation = rel;
            
            // add count customer n capacity
            link->cntCustomer++;
            link->cntCapacity += capacity;
        }

    }
}

void infoLink(Link *link) {
    cout << link->linkId << "\t" <<
        link->linkName << "\t\t" <<
        link->relation->capacity << "\t\t" <<
        link->relation->start << " - " << link->relation->end << endl;
}

void showLinkByCust(List L, int custId) {
    Link *curLink = L.link;
    cout << "== LIST OF LINK CUSTOMER " << custId << " ==" << endl;
    cout << "ID" << "\t" << "LINK NAME" << "\t" << "CAPACITY" << "\t" << "CONTRACT" << endl;
    while (curLink) {
        Relation *rel = curLink->relation;
        while (rel) {
            if (rel->customer->custId == custId) {
                infoLink(curLink);
            }
            rel = rel->next;
        }
        curLink = curLink->next;
    }
    cout << endl;
}

void infoRelation(Relation *rel) {
    cout << rel->customer->custId << "\t" <<
        rel->customer->name << "\t" <<
        rel->capacity << " GB" << "\t\t" <<
        rel->start << " - " <<
        rel->end << endl;
}

void showRelationOfLink(Link *link) {
    cout << "== CUSTOMER INFO FOR LINK " << link->linkName << " ==" << endl;
    cout << "ID" << "\t" << "CUSTOMER NAME" << "\t" << "CAPACITY" << "\t" << "CONTRACT" << endl;
    
    Relation *rel = link->relation;
    while (rel) {
        infoRelation(rel); 
        rel = rel->next;
    }
    cout << endl;
    cout << "TOTAL" << "\t" << "CAPACITY" << endl;
    cout << link->cntCustomer << "\t" << link->cntCapacity << " GB" << endl;
    cout << endl;
}


void showCustByLink(List L, int linkId) {
    Link *link = L.findLink(linkId);
    showRelationOfLink(link);
}

void showStat(List L) {
    float totalCapacity = 0;
    int totalCustomer = 0;

    int linkTerisi = 0;
    int linkKosong = 0; 

    Link *link = L.link;
    while (link) {
        if (link->relation) {
            showRelationOfLink(link);  
            totalCapacity += link->cntCapacity;
            totalCustomer += link->cntCustomer;
            linkTerisi++;
        } else {
            linkKosong++;
        }
        link = link->next;
    }

    // cout << endl;
    cout << "== STATS ==" << endl;
    cout << "LINK TERISI\tLINK KOSONG\tCUSTOMER\tCAPACITY" << endl;
    cout << linkTerisi << "\t\t" << linkKosong << "\t\t" << totalCustomer << "\t\t" << totalCapacity << endl;
    cout << endl;
}