#include <iostream>
#include <vector>
using namespace std;

// Graph using Adjacency List
class GraphList {
    int V;
    vector<vector<int>> adj;

public:
    GraphList(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Omit for directed graph
    }

    void printGraph() {
        cout << "Adjacency List Representation:\n";
        for (int i = 0; i < V; ++i) {
            cout << i << " -> ";
            for (int j : adj[i])
                cout << j << " ";
            cout << "\n";
        }
    }
};

// Graph using Adjacency Matrix
class GraphMatrix {
    int V;
    vector<vector<int>> matrix;

public:
    GraphMatrix(int V) {
        this->V = V;
        matrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1; // Omit for directed graph
    }

    void printGraph() {
        cout << "\nAdjacency Matrix Representation:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }
};

int main() {
    int V = 5;
    GraphList gList(V);
    GraphMatrix gMatrix(V);

    vector<pair<int, int>> edges = {
        {0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}
    };

    for (auto [u, v] : edges) {
        gList.addEdge(u, v);
        gMatrix.addEdge(u, v);
    }

    gList.printGraph();
    gMatrix.printGraph();

    return 0;
}
