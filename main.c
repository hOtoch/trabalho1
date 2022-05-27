//
// Created by hugoo on 27/05/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ponto.h"
#include "agrupamento.h"


int main(int argc, char* argv[]){

    FILE * fp;
    char* entrada = argv[1];
    int i = 0;
    int sizePontos = 10;

    fp = fopen(entrada, "r");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

   

    // Leitura dos pontos
    Ponto **pontos = (Ponto**)malloc(sizePontos * sizeof(Ponto*));
    while(!feof(fp)){
        //printf("TESTE %d\n",i);
        if(i== sizePontos-1){
            sizePontos *= 2;
            pontos = (Ponto**)realloc(pontos, sizePontos * sizeof(Ponto*));
        }
        pontos[i] = readLine(fp);

        i++;
    }

    
    int numPontos = i;


    // // Calculando a matriz das distâncias entre os pontos
     double matriz[numPontos][numPontos];

    for(int j = 0; j < i; j++){
        for(int k = 0; k < j-1; k++){
            matriz[j][k] = distanciaPontos(pontos[j], pontos[k]);
        }
    }
    
    int k = atoi(argv[2]);
   

    int v[numPontos];
    for(int j = 0;j < numPontos;j++){
        v[j] = -1;
    }

    double menor = 2147483647.0;
   
    int p1, p2;
    int q = 0;
    int aux;
    while(q < numPontos - k ){ // numPontos - k= numero de agrupamentos
        //Encontra a menor aresta da matriz
        for(int j = 1;j < numPontos;j++){      
            for(int l = 0;l < j - 1;l++){
                if(matriz[j][l] < menor && matriz[j][l] != 0){
                    menor = matriz[j][l];
                    p1 = j;
                    p2 = l;
                }               
            }       
        }

        //printf("%d - %d %d\n\n",q, p1, p2);
        

        // Caso os dois pontos não estejam em um agrupamento
        if(v[p1] == -1 && v[p2] == -1){
            v[p1] = p1;
            v[p2] = p1;
            q++;
            matriz[p1][p2] = 0;
            menor = 2147483647.0;
            continue;
        }

        // Caso o ponto p1 não esteja em um agrupamento
        if(v[p1] == -1){
            v[p1] = v[p2];
            q++;
            matriz[p1][p2] = 0;
            menor = 2147483647.0;
            continue;
        }

        // Caso o ponto p2 não esteja em um agrupamento
        if(v[p2] == -1){
            v[p2] = v[p1];
            q++;
            matriz[p1][p2] = 0;
            menor = 2147483647.0;
            continue;
        }

        // Caso os dois pontos já estejam no mesmo agrupamento
        if(v[p1] == v[p2]){
            matriz[p1][p2] = 0;
            menor = 2147483647.0;
            continue;
        }
        
        if(v[p1] != v[p2]){ 
            aux = v[p1];     
            for(int j = 0;j < numPontos;j++){ // Caso não esteja substitui todo o agrupamento de p2 pelo de p1 
                if(v[j] == aux){
                    v[j] = v[p2];
                }
            }
            q++;
        }
        matriz[p1][p2] = 0;
        menor = 2147483647.0;

    }

    // for(int j = 0; j < numPontos; j++){
    //     printf("%s - %d\n",getIdPonto(pontos[j]),v[j]);
    // }

    //preencheVetorAgrupamentos(matriz, numPontos, k, v); // Preenche o vetor v com os agrupamentos


    int *grupos;
    grupos = (int*)malloc(k * sizeof(int));
    grupos[0] = v[0];
   
    for(int j = 1;j < k;j++){ // roda no número de grupos // PROBLEMA AQUI!

        for(int l = 0;l < numPontos;l++){ // roda no vetor v[]

            for(int p = 0; p < j;p++){ // verifica no vetor de grupos
                if(v[l] == grupos[p]) break; // se o ponto já está no grupo, pula para o próximo ponto

                if(p == j-1){ // se o grupo j não foi criado, cria-se
                    grupos[j] = v[l];
                    l = numPontos;
                }

            }

        }
    }

    // imprime os pontos em saida.txt
    FILE * fp2;
    char* saida = argv[3];
    fp2 = fopen(saida, "w");
    int first = 1;
    for(int j =0 ;j < k; j++){
        for(int l = 0;l < numPontos;l++){
            if(first && v[l] == grupos[j]){
                fprintf(fp2,"%s",getIdPonto(pontos[l]));
                first = 0;
                continue;
            }
            if(v[l] == grupos[j]){
                fprintf(fp2,", %s", getIdPonto(pontos[l]));

            }
        }
        first = 1;
        fprintf(fp2,"\n");
    }
    free(grupos);

    // Liberação dos pontos
    for(int j = 0;j < i;j++){
        DestroiPonto(pontos[j]);
    }

    free(pontos);

    fclose(fp);

    return 0;
}





