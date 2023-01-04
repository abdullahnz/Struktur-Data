#include "tree.h"

adrNode newNode(infotype x) {
    return adrNode { new Node { x, NULL, NULL } };
}

adrNode findNode(adrNode root, infotype x) {
    if (!root || root->info == x)
        return root;
    
    if (x < root->info)
        return findNode(root->left, x);

    return findNode(root->right, x);
}

void insertNode(adrNode &root, adrNode p) {
    if (!root) {
        root = p;
    } else { 
        if (p->info < root->info)
            insertNode(root->left, p);
        else
            insertNode(root->right, p);
    }
}
void printPreOrder(adrNode root) {
    if (root) {
        cout << root->info << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printDescendant(adrNode root, infotype x) {
    adrNode node = findNode(root, x);
    if (node) {
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

int sumNode(adrNode root) {
    if (root)
        return root->info + sumNode(root->left) 
                          + sumNode(root->right);
    return 0;
}

int countLeaves(adrNode root) {
    if (!root->left || !root->right) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

int heightTree(adrNode root) {
    if (!root)
        return -1;
    
    int heightLeft = heightTree(root->left);
    int heightRight = heightTree(root->right);

    return max(heightLeft, heightRight) + 1;
}