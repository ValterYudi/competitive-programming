#include <bits/stdc++.h>

using namespace std;

class WeightedDigraph {
    unordered_map<int, list<pair<int, int>>> graph;

public:
    void addEdge(int u, int v, int weight) {
        graph[u].push_back({v, weight});
    }

    void topologicalSortUtil(int v, unordered_map<int, bool>& visited, stack<int>& stack) {
        visited[v] = true;

        for (auto& neighbor : graph[v]) {
            if (!visited[neighbor.first]) {
                topologicalSortUtil(neighbor.first, visited, stack);
            }
        }

        stack.push(v);
    }

    void topologicalSort() {
        unordered_map<int, bool> visited;
        stack<int> stack;

        for (auto& pair : graph) {
            int vertex = pair.first;
            if (!visited[vertex]) {
                topologicalSortUtil(vertex, visited, stack);
            }
        }

        cout << "Ordenação Topológica: ";
        while (!stack.empty()) {
            cout << stack.top() << " ";
            stack.pop();
        }
        cout << endl;
    }

    void relaxa(int u, int v, int w, vector<int>& dist, vector<int>& pred) {
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            pred[v] = u;
        }
    }

    void initializeSingleSource(int s, vector<int>& dist, vector<int>& pred) {
        for (auto& pair : graph) {
            int vertex = pair.first;
            dist[vertex] = INT_MAX;
            pred[vertex] = -1;
        }

        dist[s] = 0;
    }

    void relaxaArestas(vector<int>& dist, vector<int>& pred) {
        for (auto& pair : graph) {
            int u = pair.first;
            for (auto& neighbor : graph[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                relaxa(u, v, w, dist, pred);
            }
            cout << "Distâncias: ";
            for (auto& d : dist) {
                cout << d << " ";
            }
            cout << endl;

            cout << "Predecessores: ";
            for (auto& p : pred) {
                cout << p << " ";
            }
            cout << endl;
        }
    }

    // me de um algoritmo para encontrar 
};

int main() {
    WeightedDigraph g;
    g.addEdge(0, 6, 2);
    g.addEdge(1, 2, -4);
    g.addEdge(1, 4, 1);
    g.addEdge(1, 6, 8);
    g.addEdge(3, 0, 3);
    g.addEdge(3, 4, 5);
    g.addEdge(5, 1, 2);
    g.addEdge(7, 0, 6);
    g.addEdge(7, 1, -1);
    g.addEdge(7, 3, 4);
    g.addEdge(7, 5, -4);

    vector<int> ordem = {7, 0, 1, 3, 5, 4, 6, 2};

    vector<int> dist(8);
    vector<int> pred(8);
    g.initializeSingleSource(7, dist, pred);
    
    for(int i = 0; i < ordem.size(); ++i) {
        g.relaxaArestas(dist, pred);
    }

    return 0;
}