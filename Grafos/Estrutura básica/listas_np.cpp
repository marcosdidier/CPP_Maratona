#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define UNVISITED -1
#define VISITED 0
#define INFINITO INT_MAX

class Graph {
    private:
    vector<vector<pair<int, int>>> adjList; // Primeiro é o destino e segundo é o peso
    int numEdge;
    vector<int> mark;

    public:
    Graph(int n) : numEdge(0), adjList(n), mark(n, UNVISITED) {}

    int n() const {
        return adjList.size();
    }

    void setEdge(int i, int j, int weight) {
        numEdge++;
        adjList[i].push_back({j, weight});
        adjList[j].push_back({i, weight});
    }

    void setMark(int v, int val) {
        mark[v] = val;
    }

    int getMark(int v) const {
        return mark[v];
    }

    int weight(int i, int j) {
        for (auto edge : adjList[i]) {
            if (edge.first == j) {
                return edge.second;
            }
        }
        return -1;
    }

    void Dijkstra(int s, vector<int> &D){
        vector<int>P(n(), -1);
        D.assign(n(), INFINITO);
        mark.assign(n(), UNVISITED);
        
        
        using Trinca = pair<int,pair<int,int>>;
        priority_queue<Trinca, vector<Trinca>, greater<Trinca>> minHeap;
        minHeap.push({0, {s, s}});
        D[s] = 0;

        while(!minHeap.empty()){
            int p, v;
            
                p = minHeap.top().second.first;
                v = minHeap.top().second.second;
                minHeap.pop();

            if (getMark(v) == VISITED) continue;

            setMark(v, VISITED);
            P[v] = p;

            for (auto edge : adjList[v]){
                int w = edge.first;
                int weight = edge.second;
                if (getMark(w) != VISITED && D[w] > (D[v] + weight)){
                    D[w] = D[v] + weight;
                    minHeap.push({D[w], {v, w}});
                }
            }
        }
    }

};

int main() {
    /*int numero_vertices, numero_arestas, vertice_busca;
    int vI, vJ, wt;

    cin >> numero_vertices >> numero_arestas >> vertice_busca;

    vector<int> D(numero_vertices);

    Graph grafo(numero_vertices);

    for (int i = 0; i < numero_arestas; ++i) {
        cin >> vI >> vJ >> wt;
        grafo.setEdge(vI, vJ, wt);
    }

    grafo.Dijkstra(vertice_busca, D);

    for (int i = 0; i < numero_vertices; ++i) {
        cout << D[i];
        if (i < numero_vertices - 1) cout << " ";
    }
    cout << endl;*/

    return 0;
}