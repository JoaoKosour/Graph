#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

typedef struct Pos {
    int x, y;
} Pos;


typedef struct Ator {
    char nome[20];
    char sobrenome[20];
} Ator;

typedef struct Filme {
    char filme[20];
} Filme;

typedef struct Node {
    Ator *atores;
    Filme filme;
    int x, y, peso;
} Node;

typedef struct Grafo {
    Node matriz[N][N];
    int tamanho;
} Grafo;


Pos *endVertex(Grafo , Pos);
int areAdjacent(Grafo , int , int);
Pos *insertEdge(Grafo *, Node);
Pos inserEdge(Grafo *, int , int , int);
Pos inserVertex(Grafo *, int , int , int);
int edgeValue(Grafo *, Pos);
Node vertexValue(Grafo *, Pos);


int main() {
    char filme[50], nome[20], sobrenome[20];
    int kb = -1;
    char c;

  
  return 0;
}


/* 
- Como nao temos indicadores de id para cada aresta usaremos "e" como sendo um par ordenado (x, y) que contem a aresta entre x e y
*/

Pos *endVertex(Grafo G, Pos e) {
    Pos *end_vertex = calloc(2, sizeof(Pos));

    end_vertex[0].y = e.y;
    end_vertex[0].x = e.x;

    end_vertex[1].y = e.x;
    end_vertex[1].x = e.y;

    return end_vertex;
}

int areAdjacent(Grafo G, int v, int w) {
    return (G.matriz[v][w].peso != 0);
}

Pos *insertEdge(Grafo *G, Node O) {
    int i = 1;
    Pos *new_pos = calloc(2, sizeof(Pos));

    while(G->matriz[i][1].peso != 0)
        i++;

    G->matriz[i][1] = O;

    new_pos[0].x = i;
    new_pos[0].y = 1;

    new_pos[1].x = 1;
    new_pos[1].y = i;
    return new_pos;
};

Pos inserVertex(Grafo *G, int v, int w, int _KB) {
    Pos node_pos;
    node_pos.y = v;
    node_pos.x = w;

    G->matriz[v][w].peso = _KB;
    G->matriz[w][v].peso = _KB;

    return node_pos;
}

void replaceEdge(Grafo *G, Pos e, int o) {
    G->matriz[e.x][e.y].peso = o;
    G->matriz[e.y][e.x].peso = o;
}


// consideramos o vertice v como um par ordenado (x, y)
void replaceVertex(Grafo *G, Pos v, Node o) {
    G->matriz[v.x][v.y] = o;
    G->matriz[v.y][v.x] = o;
}

int edgeValue(Grafo *G, Pos e) {
    return G->matriz[e.x][e.y].peso;
}

Node vertexValue(Grafo *G, Pos v) { //retorna o elemento armazenado no vértice v.
    return G->matriz[v.x][v.y];
}