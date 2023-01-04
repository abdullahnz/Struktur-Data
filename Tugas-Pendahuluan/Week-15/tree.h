#include <iostream>
using namespace std;

typedef struct Node * adrNode;
typedef int infotype;

struct Node {
    infotype info;
    adrNode left, right;
};

adrNode newNode(infotype x);
adrNode findNode(adrNode root, infotype x);

void insertNode(adrNode &root, adrNode p);
void printPreOrder(adrNode root);

void printDescendant(adrNode root, infotype x);
int sumNode(adrNode root);

int countLeaves(adrNode root);
int heightTree(adrNode root);