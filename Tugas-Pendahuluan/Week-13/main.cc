#include "graph.h"

#define println(n) for (int i = 0; i < n; i++) cout << "="; cout << endl;


int main() {
    adrNode G = NULL;

    addNode(G, newNode('A'));
    addNode(G, newNode('B'));
    addNode(G, newNode('C'));
    addNode(G, newNode('D'));

    addEdge(G, 'D', 'B');
    addEdge(G, 'A', 'B');
    addEdge(G, 'A', 'C');
    addEdge(G, 'A', 'D');

    println(64);

    printGraph(G);    
    
    println(64);

    cout << (isConnected(G, 'A', 'B') ? "Node A terhubung dengan Node B" 
                                      : "Node A tidak terhubung dengan Node B") << endl;
    cout << (isConnected(G, 'B', 'A') ? "Node B terhubung dengan Node A" 
                                      : "Node B tidak terhubung dengan Node A") << endl;
    cout << (isConnected(G, 'C', 'B') ? "Node C terhubung dengan Node B" 
                                      : "Node C tidak terhubung dengan Node B") << endl;
    cout << (isConnected(G, 'C', 'D') ? "Node B terhubung dengan Node C" 
                                      : "Node B tidak terhubung dengan Node C") << endl;

    println(64);
    
    return 0;
}