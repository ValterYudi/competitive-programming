#include <bits/stdc++.h>

using namespace std;

typedef struct _grafo Grafo;
typedef struct _viz Viz;
struct _viz {
   int noj;
   float peso;
   Viz* prox;
};
struct _grafo {
   int nv; /* numero de nos ou vertices */
   int na; /* numero de arestas */
   Viz** viz; /* viz[i] aponta para a lista de arestas vizinhas do no i */
};

void ordenacaoTopologica(Grafo *grafo, int *visitados, int no, int *pilha, int *posicaoPilha) {
   visitados[no] = 1;
   Viz *vizinho = grafo->viz[no];
   while (vizinho != NULL) {
      int no_viz = vizinho->noj;
      if (!visitados[no_viz])
         ordenacaoTopologica(grafo, visitados, no_viz, pilha, posicaoPilha);
      vizinho = vizinho->prox;
   }
   pilha[(*posicaoPilha)++] = no;
}

int main() {
   Grafo *grafo;
   // Ler grafo
   int *visitados = (int *)malloc(grafo->nv * sizeof(int));
   int *pilha = (int *)malloc(grafo->nv * sizeof(int));
   int posicaoPilha = 0;

   for (int i = 0; i < grafo->nv; i++) {
      visitados[i] = 0;
   }

   for (int i = 0; i < grafo->nv; i++) {
      if (!visitados[i]) {
         ordenacaoTopologica(grafo, visitados, i, pilha, &posicaoPilha);
      }
   }

   printf("Ordenação Topológica:");
   for (int i = posicaoPilha - 1; i >= 0; i--) {
      printf(" %d", pilha[i]);
   }
   printf("\n");

   return 0;
}