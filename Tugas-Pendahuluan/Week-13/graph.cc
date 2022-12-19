#include "graph.h"

adrNode newNode(char x) {
    return adrNode { new Node { x, NULL, NULL } };
}

void addNode(adrNode &G, adrNode p) {
    if (!G) {
        G = p;
    } else {
        adrNode cur = G;
        while (cur->next)
            cur = cur->next;
        cur->next = p;
    }
}

adrNode findNode(adrNode G, char x) {
    adrNode cur = G;
    if (cur) {
        while (cur && cur->info != x)
            cur = cur->next;
    }
    return cur;
}

// helper
void insert(adrNode &G, adrEdge p) {
    if (G->child) {
        p->next = G->child;
    }
    G->child = p;
}

void addEdge(adrNode &G, char x, char y) {
    adrNode nodeX = findNode(G, x);
    adrNode nodeY = findNode(G, y);

    if (!nodeX) 
        addNode(G, newNode(x));
    if (!nodeY) 
        addNode(G, newNode(y));

    insert(nodeX, (adrEdge)newNode(y));
    insert(nodeY, (adrEdge)newNode(x));
}

bool isConnected(adrNode G, char x, char y) {
    adrNode nodeX = findNode(G, x);
        
    adrEdge curX = nodeX->child;
    if (curX) {
        while (curX && curX->info != y) {
            curX = curX->next;
        }
    }
    return curX != NULL;
}

void printGraph(adrNode G) {
    if (G) {
        adrNode cur = G;
        while (cur) {
            cout << "node " << cur->info << ": ";
            adrEdge  child = cur->child;
            while (child) {
                cout << child->info << (child->next ? " - " : "");
                child = child->next;
            }
            cout << endl;
            cur = cur->next;
        }
    }
}
