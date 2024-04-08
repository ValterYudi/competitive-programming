#include "numeros_matriz.h"

void remover_numeros_matriz(int l, int c, int n_linhas, int n_colunas, int m[n_linhas][n_colunas]) {
    int rm = m[l][c];
    if(l > 0){
        if(m[l-1][c] == rm){
            remover_numeros_matriz(l-1, c, n_linhas, n_colunas, m);
        }
    }
    if(l < n_linhas-1){
        if(m[l+1][c] == rm){
            remover_numeros_matriz(l+1, c, n_linhas, n_colunas, m);
        }
    }
    if(c > 0){
        if(m[l][c-1] == rm){
            remover_numeros_matriz(l, c-1, n_linhas, n_colunas, m);
        }
    }
    if(c < n_colunas-1){
        if(m[l][c+1] == rm){
            remover_numeros_matriz(l, c+1, n_linhas, n_colunas, m);
        }
    }
    m[l][c] = 0;
}