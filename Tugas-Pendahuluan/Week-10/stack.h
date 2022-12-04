#include <iostream>

using namespace std;

#define top(s) s.top
#define info(s) s.info

typedef char infotype;
struct Stack {
    infotype info[15];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);

void push(Stack &S, infotype x);
int pop(Stack &S);
void printInfo(Stack S);

