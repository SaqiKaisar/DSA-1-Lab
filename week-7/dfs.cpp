#include <iostream>
#include <vector>
using namespace std;

int V;
vector<vector<int>> adjList;

void DFS(int node, vector<bool> &visited) {

    visited[node] = true;

    cout << node << " ";

    for(int neighbor : adjList[node]) {

        if(!visited[neighbor]) {
            DFS(neighbor, visited);
        }
    }
}

int main() {

    V = 6;
    adjList.assign(V, vector<int>());

    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(3);
    adjList[1].push_back(4);
    adjList[2].push_back(5);

    // Undirected edges
    adjList[1].push_back(0);
    adjList[2].push_back(0);
    adjList[3].push_back(1);
    adjList[4].push_back(1);
    adjList[5].push_back(2);

    vector<bool> visited(V, false);

    cout << "\nDFS Traversal: ";
    DFS(0, visited);
    cout << endl;

    return 0;
}