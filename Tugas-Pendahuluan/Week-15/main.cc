#include "tree.h"

int main() {
    adrNode root = NULL;

    // int x[9] = {5,3,9,10,4,7,1,8,6};
    // int x[9] = {8,3,10,1,6,4,7,14,13};

    int x[10] = {100, 99, 80, 60, 55, 40, 35, 20, 10, 1};
    
    for (int i = 0; i < 10; i++)
        insertNode(root, newNode(x[i]));

    // printPreOrder(root);

    printDescendant(root, 99);

    // for (int i = 0; i < 64; i++) cout << "="; cout << endl;

    // for (int i = 0; i < 9; i++) {
    //     cout << x[i] << " ";
    //     insertNode(root, newNode(x[i]));
    // }

    // printf("\n");
    
    // printf("\nPre Order\t\t: ");
    // printPreOrder(root);
    // printf("\n");
    
    // printf("\nDescendent of Node 9\t: ");
    // printDescendant(root, 9); 
    // printf("\n\n");

    // printf("Sum of BST Info\t\t: %d\n", sumNode(root)); 
    // printf("Number of Leaves\t: %d\n", countLeaves(root));
    // printf("Height of Tree\t\t: %d\n", heightTree(root));

    // for (int i = 0; i < 64; i++) cout << "="; cout << endl;

    return 0;
}