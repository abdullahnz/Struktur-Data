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

void addContract(int linkId, int custId, string invId, float capacity, string start, string end, List & L) {
    // find link by id
    Link *link = L.findLink(linkId);
    if (!link) {
        cout << "LINK ID NOT FOUND !" << endl;
    } else {
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
            if (link->relation)
                rel->next = link->relation;
            link->relation = rel;
        }

    }
}

void showLinkByCust(List L, int custId) {
    Link *curLink = L.link;
    cout << "== LIST OF LINK CUSTOMER " << custId << " ==" << endl;
    cout << "ID" << "\t" << "LINK NAME" << "\t" << "CAPACITY" << "\t" << "CONTRACT" << endl;
    while (curLink) {
        Relation *rel = curLink->relation;
        while (rel) {
            if (rel->customer->custId == custId) {
                cout << curLink->linkId << "\t" <<
                    curLink->linkName << "\t\t" <<
                    rel->capacity << "\t\t" <<
                    rel->start << " - " << rel->end << endl;
            }
            rel = rel->next;
        }
        curLink = curLink->next;
    }
    cout << endl;

}

void showCustByLink(List L, int linkId) {
    Link *link = L.findLink(linkId);
    Relation *rel = link->relation;

    cout << "== CUSTOMER INFO FOR LINK " << link->linkId << " ==" << endl;
    cout << "ID" << "\t" << "CUSTOMER NAME" << "\t" << "CONTRACT" << endl;

    float totalCapacity = 0;
    int totalCustomer = 0;

    while (rel) {
        cout << rel->customer->custId << "\t" <<
            rel->customer->name << "\t" <<
            rel->start << " - " <<
            rel->end << endl;
        totalCapacity += rel->capacity;
        totalCustomer++;
        rel = rel->next;
    }
    cout << endl;
    cout << "TOTAL" << "\t" << "CAPACITY" << endl;
    cout << totalCustomer << "\t" << totalCapacity << endl;
    cout << endl;
}

void showStat(List L) {
    Link *curLink = L.link;
    while (curLink) {
        if (curLink->relation) {
            showCustByLink(L, curLink->linkId);
            cout << endl;
        }
        curLink = curLink->next;
    }
}