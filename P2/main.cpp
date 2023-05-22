#include <iostream>
#include "Digraph.h"

using namespace std;

int main() {
    Digraph graph("test.csv");
    graph.display();
    cout << endl;
    graph.inDegree(3);
    graph.inDegree(5);
    cout << endl << "DFS visit order starting at 0: " << endl;
    graph.displayDFS(0);
    cout << endl;
    cout << endl << "BFS visit order starting at 0: " << endl;
    graph.createBFS(0);
}
