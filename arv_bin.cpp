#include <bits/stdc++.h>

using namespace std;
 #include <stdio.h>
#include <stdlib.h>

struct Arv{
    int info;
    struct Arv* esq;
    struct Arv* dir;
};

Arv* arv_cria (int n, Arv* sae, Arv* sad){
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->info = n;
    p->esq = sae;
    p->dir = sad;
    return p;
}

Arv* arv_criavazia(void){
    return NULL;
}
int arv_vazia (Arv* a){
    return a==NULL;
}
Arv* arv_libera(Arv* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq); /* libera sae */
        arv_libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}




int altura_arvore(Arv* arv){
    int altura, aux;
    
    if(arv == NULL){
        return -1;
    }
    altura = 0;
    aux = 0;
    aux = altura_arvore(arv->esq);
    if(aux > altura){
        altura = aux;
    }
    aux = altura_arvore(arv->dir);
    if(aux > altura){
        altura = aux;
    }
    return altura + 1;
}

// O custo de um caminho em uma árvore é a soma das chaves dos nós participantes nesse caminho. 
// Considere uma árvore binária de chaves inteiras. Escreva uma função que retorne o custo do caminho de maior valor da raiz para um nó folha.
int custo_maior_caminho(Arv* arv){
    int custo, aux;
    
    if(arv == NULL){
        return 0;
    }
    custo = arv->info;
    aux = max(custo_maior_caminho(arv->esq), custo_maior_caminho(arv->dir));

    return custo + aux;
}
int main(){
    // representação em vetor da arvore binária do exemplo da figura 1
    // char arv[] = {34, 24, 17, 11, 19, 7, 9, 5}
    //              34 (24(11(5,()), 19) ,17(7, 9))
    // representação em vetor do exemplo da figura 2
    // char arv[] = {4, 4, 3, 3, 3, 1, 1, 1, 1, 1}
                   //1  2  3  4  5  6  7  8  9  10

    Arv * arv1 = arv_cria(34, arv_cria(24, arv_cria(11, arv_cria(5, NULL, NULL), NULL), arv_cria(19, NULL, NULL)), arv_cria(17, arv_cria(7, NULL, NULL), arv_cria(9, NULL, NULL)));

    Arv * arv2 = arv_cria(4, arv_cria(4, arv_cria(3, arv_cria(1, NULL, NULL), arv_cria(1, NULL, NULL)), arv_cria(3, arv_cria(1, NULL, NULL), NULL)), arv_cria(3, arv_cria(1, NULL, NULL), arv_cria(1, NULL, NULL)));

    cout << "Arvore 1:\n";
    cout << "altura: " << altura_arvore(arv1) - 1 << "\n";
    cout << "soma dos pesos do maior caminho = " << custo_maior_caminho(arv1) << "\n";

    cout << "Arvore 2:\n";
    cout << "altura: " << altura_arvore(arv2) - 1 << "\n";
    cout << "soma dos pesos do maior caminho = " << custo_maior_caminho(arv2) << "\n";
    return 0;

}