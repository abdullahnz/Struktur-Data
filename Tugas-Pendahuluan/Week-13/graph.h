#include <iostream>

using namespace std;

typedef char infotype;
typedef struct Node *adrNode;
typedef struct Edge *adrEdge;

struct Node {
    infotype info;
    adrEdge child;
    adrNode next;
};

struct Edge {
    infotype info;
    adrEdge next;
};

adrNode newNode(char x);
void addNode(adrNode &G, adrNode p);
adrNode findNode(adrNode G, char x);
void addEdge(adrNode &G, char x, char y);
bool isConnected(adrNode G, char x, char y);
void printGraph(adrNode G);

// helper
void insert(adrNode &G, adrEdge p);

