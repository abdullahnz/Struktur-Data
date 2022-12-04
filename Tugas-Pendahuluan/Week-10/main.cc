#include "stack.h"

int main() {
    Stack S;

    createStack(S);

    string str = "PERCAYADIRI";
    for (int i = str.size()-1; i >= 0; i--)
        push(S, str[i]);
    
    printInfo(S);

    int nPop = 7;
    for (int i = 0; i < nPop; i++) 
        pop(S);

    printInfo(S);


}  