#include <bits/stdc++.h>

using namespace std;

void troca(int a, int b, int* v) {
    int f = v[a];
    v[a] = v[b];
    v[b] = f;
}

void corrige_abaixo(int *prios, int atual, int tam) {
    int pai = atual;
    int filho_esq, filho_dir, filho;
    while (2 * pai + 1 < tam) {
        filho_esq = 2 * pai + 1;
        filho_dir = 2 * pai + 2;

        if (filho_dir < tam && prios[filho_dir] > prios[filho_esq])
            filho = filho_dir;
        else
            filho = filho_esq;

        if (prios[pai] >= prios[filho])
            break;

        troca(pai, filho, prios);
        pai = filho;
    }
}

void heap_constroi(int *prios, int tam) {
    for (int i = tam / 2 - 1; i >= 0; i--) {
        corrige_abaixo(prios, i, tam);
    }
}

int main() {
    int tamanho_maximo;
    cin >> tamanho_maximo;

    int prios[tamanho_maximo];
    int tam = 0;

    for (int i = 0; i < tamanho_maximo; i++) {
        cin >> prios[i];
        tam++;
    }

    heap_constroi(prios, tam);
    troca(1, 2, prios);
    troca(4, 6, prios);
    troca(5, 7, prios);
    troca(6, 7, prios);
    cout << "[";
    for (int i = 0; i < tam - 1; i++) {
        cout << prios[i] << ", ";
    }
    cout << prios[tam-1] << "]\n";

    return 0;
}
