#include "mst.h"

struct mst{
    char* id;
    double aresta;
    Mst* prox;
}

Mst* criaVertice(Ponto* p){
    Mst* m = (Mst*)malloc(sizeof(Mst));
    m->id = p->id;
    m->aresta = NULL;
    m->vertice = NULL;

    DestroiPonto(p);
    return m;
}

Mst* criaAresta(double** Matriz,int numPontos){ // PROBLEMA PONTOS != MST
    int first = 1;

    for(int j = 0; j < numPontos; j++){
        for(int k = 0; k < numPontos; k++){
            if(j==k || matriz[j][k] == NULL){ // Se for a mesma posição ou não existir distância entre os pontos
                continue;
            }
            if(first){ // Verifica se é o primeira distancia a ser analisada
                this->aresta = matriz[j][k];  // Se for, atribui a menor distancia
                this->prox = pontos[k]; // Atribui o ponto que possui a menor distancia
                first = 0;
            }
            if(matriz[j][k] < pontos[j]->menorDist){
                pontos[j]->menorDist = matriz[j][k]; // Atualiza a menor distancia
                pontos[j]->prox = pontos[k]; // Atualiza o ponto que possui a menor distancia
            }
            
        }
    }
}

void liberaVertice(Mst* m){
    free(m->id);
    free(m->vertice);
    free(m);
}

