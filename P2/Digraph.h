//
// Created by lolita kim on 11/30/21.
//
#include <iostream>
#ifndef HW6_DIGRAPH_H
#define HW6_DIGRAPH_H

using namespace std;

class Digraph {
private:
    int** matrix;
    int size;
    bool* visited;
    void DFSHelper(int vertex, bool visited[]);

public:
    Digraph(const Digraph &otherGraph);
    Digraph(int n);
    Digraph(string filename);
    ~Digraph();
    void addEdge(int a, int b);
    void display()  const;
    void displayDFS(int vertex);
    Digraph& createBFS(int vertex);
    int inDegree(int i) const;
};

#endif //HW6_DIGRAPH_H
