#include <bits/stdc++.h>

using namespace std;

class Grafo {
public:
    int numVertices;
    vector<vector<int>> listaAdj;

    Grafo(int numVertices) : numVertices(numVertices), listaAdj(numVertices) {}

    void adicionarAresta(int v1, int v2) {
        listaAdj[v1].push_back(v2);
        listaAdj[v2].push_back(v1);  // Comente esta linha se o grafo for direcionado
    }

    void imprimirGrafo() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vértice " << i << ": ";
            for (const auto &vizinho : listaAdj[i]) {
                cout << vizinho << " ";
            }
            cout << endl;
        }
    }

    void dfs(int v, vector<bool> &visitados) {
        visitados[v] = true;
        cout << v << " ";

        for (const auto &vizinho : listaAdj[v]) {
            if (!visitados[vizinho]) {
                dfs(vizinho, visitados);
            }
        }
    }

    void dfs(int v) {
        vector<bool> visitados(numVertices, false);
        dfs(v, visitados);
    }

    void bfs(int v) {
        vector<bool> visitados(numVertices, false);
        queue<int> fila;

        visitados[v] = true;
        fila.push(v);

        while (!fila.empty()) {
            int vertice = fila.front();
            fila.pop();
            cout << vertice << " ";

            for (const auto &vizinho : listaAdj[vertice]) {
                if (!visitados[vizinho]) {
                    visitados[vizinho] = true;
                    fila.push(vizinho);
                }
            }
        }
    }

    void bfs() {
        vector<bool> visitados(numVertices, false);
        for (int i = 0; i < numVertices; ++i) {
            if (!visitados[i]) {
                bfs(i);
            }
        }
    }

    // Prim
    // Kruskal
    // Dijkstra
    // Bellman-Ford
    // Floyd-Warshall
    // Ford-Fulkerson
    // Edmonds-Karp
    // Hopcroft-Karp
    // Dinic
    // Tarjan
    // Kosaraju
    // Topological Sort
    // Bridges
    // Articulation Points
    // Strongly Connected Components
    // Lowest Common Ancestor
    // Eulerian Path
    // Hamiltonian Path
    // Bipartite Matching
    // Chinese Postman
    // Travelling Salesman
    // 2-SAT
    // Maximal Matching
    // Maximal Independent Set
    // Maximal Clique
    // Maximal Bipartite Matching
    // Max Flow
    // Min Cut
    // Min Cost Max Flow
    // Min Cost Matching
    // Min Cost Bipartite Matching
    // Min Vertex Cover
    // Max Independent Set
    // Min Dominating Set
    // Min Edge Cover
    // Min Path Cover
    
    // https://cp-algorithms.com

};

int main() {
    // Exemplo de uso
    Grafo grafo(5);

    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(3, 4);

    grafo.imprimirGrafo();
    
    cout << "DFS: ";
    grafo.dfs(0);
    cout << endl;

    cout << "BFS: ";
    grafo.bfs(0);
    cout << endl;

    return 0;
}
