//
// Created by lolita kim on 11/30/21.
//

#include "Digraph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>

using namespace std;

Digraph ::Digraph(const Digraph &otherGraph) {
    matrix = new int*[size];
    for(int i = 0; i < size; i++){
        matrix[i] = new int[size];
        for(int j = 0; j < otherGraph.size; j++){
            matrix[i][j] = otherGraph.matrix[i][j];
        }
    }
    visited = new bool[size];
}

Digraph ::Digraph(int n) {
    size = n;
    matrix = new int*[size];
    for(int i = 0; i < size; i++){
        matrix[i] = new int[size];
        for(int j = 0; j < size; j++){
            matrix[i][j] = 0;
        }
    }
    visited = new bool[size];
}

Digraph ::Digraph(string filename) {
    string vertex1;
    string vertex2;
    string line;
    ifstream myFile;

    myFile.open(filename);
    if(!myFile.is_open())
        cout << "ERROR.";

    else {
        getline(myFile, line);
        istringstream str(line);
        str >> size;
        //create an array
        matrix = new int*[size];
        for (int i = 0; i < size; i++){
            matrix[i] = new int[size];
            for (int j = 0; j < size; j++){
                matrix[i][j] = 0;
            }
        }
        //read the file and add edges
        while (getline(myFile, line)){
            istringstream str(line);
            getline(str, vertex1, ',');
            getline(str,vertex2, '\n');
            addEdge(stoi(vertex1), stoi(vertex2));
        }
    }
}

Digraph ::~Digraph() {
    for (int i = 0; i < size; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Digraph::addEdge(int a, int b) {
    matrix[a][b] = 1;
}
void Digraph ::display() const {
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void Digraph ::displayDFS(int vertex) {
    visited = new bool[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;
    DFSHelper(vertex, visited);
}
void Digraph ::DFSHelper(int vertex, bool *visited) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int i = 0; i < size; i++){
        if (matrix[vertex][i] != 0 && !visited[i]){
            visited[vertex] = true;
            DFSHelper(i, visited);
        }
    }
}
Digraph &Digraph ::createBFS(int vertex) {
    visited = new bool[size];
    Digraph* newGraph = new Digraph(size);
    for (int i = 0; i < size; i++)
        visited[i] = false;
    deque<int> queue;
    visited[vertex] = true;
    queue.push_back(vertex);
    //print the first element out
    cout << vertex << " ";
    while(!queue.empty()){
        vertex = queue.front();
        queue.pop_front();
        for (int i = 0; i < size; i++) {
            if (matrix[vertex][i] != 0 && !visited[i]) {
                visited[i] = true;
                cout << i << " ";
                newGraph->addEdge(vertex, i);
                queue.push_back(i);
            }
        }
    }
    cout << endl << endl << "BFS Spanning tree: " << endl;
    cout << endl;
    newGraph->display();
    return* newGraph;
}
int Digraph ::inDegree(int i) const {
    int count = 0;
    for (int n = 0; n < size; n++){
        if(matrix[n][i] == 1){
            count++;
        }
    }
    cout << "Deg-(" << i << ") = " << count << endl;
    return count;
}






