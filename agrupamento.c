#include "agrupamento.h"


void preencheVetorAgrupamentos(double** matriz, int numPontos, int k, int* v){
    int menor = matriz[1][0];
    int p1, p2; 
    int q = 0;
    while(q < numPontos - k - 1){ // numPontos - k - 1 = numero de agrupamentos
        // Encontra a menor aresta da matriz
        for(int j = 1;j < numPontos;j++){                      
            for(int l = 1;l < j - 1;l++){              
                if(matriz[j][l] < menor && matriz[j][l] != 0){
                    menor = matriz[j][l];
                    p1 = j;
                    p2 = l;
                }
            }
        }
        
       // Verifica se p2 já está no agrupamento de p1
        if(v[p1] != v[p2]){
            for(int j = 0;j < numPontos;j++){ // Caso não esteja substitui todo o agrupamento de p2 pelo de p1
                if(v[j] == v[p2]){ 
                    v[j] = v[p1];
                }
            }
            q++;
        }
        matriz[p1][p2] = 0;
        menor = 2147483647;
    }
}