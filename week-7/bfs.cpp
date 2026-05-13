#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V;
vector<vector<int>> adjList;

void BFS(int start) {

    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nBFS Traversal: ";

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbor : adjList[node]) {

            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
}

int main() {

    V = 6;
    adjList.assign(V, vector<int>());

    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(3);
    adjList[1].push_back(4);
    adjList[2].push_back(5);

    // Since undirected graph
    adjList[1].push_back(0);
    adjList[2].push_back(0);
    adjList[3].push_back(1);
    adjList[4].push_back(1);
    adjList[5].push_back(2);

    BFS(0);

    return 0;
}