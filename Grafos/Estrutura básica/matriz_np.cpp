#include <iostream>
#include <vector>

#define UNVISITED 0
#define VISITED 1

using namespace std;


typedef struct Graph{
    vector<vector<int>> matrix;
    int numEdge;
    vector<int>mark;
} Graph;

Graph *create_graph(int n){

    Graph *g = new Graph;
    g->matrix = vector<vector<int>>(n, vector<int>(n, 0));
    g->numEdge = 0;
    g->mark = vector<int>(n, 0);

    return g;
}

int n(Graph *g){
    return g->mark.size();
}

int e(Graph *g){
    return g->numEdge;
}

int first(Graph *g, int v){
    for (int i = 0; i < n(g); i++){
        if (g->matrix[v][i] != 0){
            return i;
        }
    }
    return n(g);
}

int next(Graph *g, int v, int w){
    for (int i = w + 1; i < n(g); i++){
        if (g->matrix[v][i] != 0) return i;
    }

    return n(g);
}

void setEdge(Graph *g, int i, int j, int wt){
    if (wt == 0){
        return;
    } else if (g->matrix[i][j] == 0) {
        g->numEdge++;
        g->matrix[i][j] = wt;
        g->matrix[j][i] = wt;
    }
}

void delEdge(Graph *g, int i, int j){
    if (g->matrix[i][j] != 0){
        g->numEdge--;
        g->matrix[i][j] = 0;
        g->matrix[j][i] = 0;    
    }
}

bool isEdge(Graph *g, int i, int j){
    if (g->matrix[i][j] != 0) return true;
    return false;
}

int weight(Graph *g, int i, int j){
    if (isEdge(g, i, j)) return g->matrix[i][j];
    return -1;
}

void setMark(Graph *g, int v, int val){
    g->mark[v] = val;
}

int getMark(Graph *g, int v){
    return g->mark[v];
}

void graphTraverse(Graph *g){
    for (int v = 0; v < n(g); v++){
        setMark(g, v, UNVISITED);

    }
}



int main(void){

    int numero_vertices, numero_arestas;
    cin >> numero_vertices;
    Graph *g = create_graph(numero_vertices);
    cin >> numero_arestas;
    for (int i = 0; i < numero_arestas; i++){
        int a1, a2, peso;
        cin >> a1 >> a2 >> peso;
        setEdge(g, a1, a2, peso);
    }

    string comando;
    while((cin >> comando) && comando != "parar"){
        int i, j;
        cin >> i >> j;
        int wt = weight(g, i, j);
        cout << wt << endl;
    }

    delete g;

    return 0;
}