#include "stack.h"

void createStack(Stack &S) {
    top(S) = -1;
}

bool isEmpty(Stack S) {
    return top(S) == -1;
}

bool isFull(Stack S) {
    return top(S) == sizeof(info(S))-1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        info(S)[++top(S)] = x;
    }
}
int pop(Stack &S) {
    return info(S)[top(S)--];
}
void printInfo(Stack S) {
    if (!isEmpty(S)) {
        for (int i = top(S); i >= 0; i--) {
            cout << info(S)[i] << " ";
        }
        cout << endl;
    }
}
