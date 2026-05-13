#include <iostream>
#include <vector>
using namespace std;

int V;

// Adjacency Matrix
vector<vector<int>> adjMatrix;

// Adjacency List
vector<vector<int>> adjList;

// Function to add edge (Undirected Graph)
void addEdge(int u, int v) {

    // Matrix
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;

    // List
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

// Print Adjacency Matrix
void printMatrix() {

    cout << "\nAdjacency Matrix:\n";

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Print Adjacency List
void printList() {

    cout << "\nAdjacency List:\n";

    for(int i = 0; i < V; i++) {

        cout << i << " -> ";

        for(int x : adjList[i]) {
            cout << x << " ";
        }

        cout << endl;
    }
}

int main() {

    V = 5;

    // Initialize structures
    adjMatrix.assign(V, vector<int>(V, 0));
    adjList.assign(V, vector<int>());

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    printMatrix();
    printList();

    return 0;
}