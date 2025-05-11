#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 100; // Max number of nodes
vector<int> adj[N]; // Adjacency list
bool visited[N];
int nodeValues[N]; // Store value of each node

// Add undirected edge
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// BFS Traversal
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// DFS Traversal
void dfs(int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

// Search for a node using BFS
bool searchNode(int start, int target) {
    fill(visited, visited + N, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == target) return true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

// Sum of node values in connected component
int sumComponent(int start) {
    fill(visited, visited + N, false);
    int total = 0;

    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        total += nodeValues[u];

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return total;
}

int main() {
    // Build graph: 0-1, 0-2, 1-3
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);

    // Assign values to nodes
    nodeValues[0] = 5;
    nodeValues[1] = 10;
    nodeValues[2] = 3;
    nodeValues[3] = 7;

    cout << "BFS from node 0: ";
    fill(visited, visited + N, false);
    bfs(0); cout << endl;

    cout << "DFS from node 0: ";
    fill(visited, visited + N, false);
    dfs(0); cout << endl;

    int target = 3;
    cout << "Search for node " << target << ": ";
    cout << (searchNode(0, target) ? "Found" : "Not Found") << endl;

    cout << "Sum of values from node 0: ";
    cout << sumComponent(0) << endl;

    return 0;
}
