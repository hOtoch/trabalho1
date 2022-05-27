#include "Ponto.h"

struct ponto{
    char* id;
    double* coord;
    int numCoord;
};

int TamanhoPalavra(char* c){
    int i = 0;
    while(c[i] != '\0'){
        i++;
    }
    return i + 1;
}

Ponto* readLine (FILE *fp){   

    size_t len = 0;
    char *linha = NULL;
    int i = 0,sizeCoord = 2;

    Ponto *p = InicializaPonto(); // Aloca um ponto

    getline(&linha, &len, fp);
    char *token = strtok(linha, ",");
    
    int t = TamanhoPalavra(token);
    p->id = (char*)malloc(t * sizeof(char));
    strcpy(p->id, token);

    p->coord = (double*)malloc(sizeCoord * sizeof(double));
    token = strtok(NULL, ",");
    

    while(token != NULL){        
        if(i == sizeCoord-1){
            sizeCoord *= 2; // dobra o tamanho do vetor de coordenadas
            p->coord = (double*) realloc(p->coord, sizeCoord *sizeof(double)); // realoca o vetor de coordenadas
        }
        p->coord[i] = atof(token);
        
        token = strtok(NULL, ",");  
        i++;
    }
    
    free(linha);

    p->numCoord = i; // numero de coordenadas de cada ponto
    return p;

}

Ponto* InicializaPonto(){
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));
    p->id = NULL;
    p->coord = NULL;
    p->numCoord = 2;
    return p;
    
}

void DestroiPonto(Ponto *p){
    free(p->id);
    free(p->coord);
    free(p);
}

char* getIdPonto(Ponto *p){
    return p->id;
}

double distanciaPontos(Ponto *p1, Ponto *p2){
    double dist,distTotal = 0;
    for(int i=0;i< p1->numCoord;i++){
        dist = pow(p1->coord[i] - p2->coord[i],2);
        distTotal += dist;
    }
    distTotal = sqrt(distTotal);
    return distTotal;
}

void imprimeCoordPonto(Ponto *p){
    for(int i=0;i< p->numCoord;i++){
        printf("%f ", p->coord[i]);
    }
    printf("\n");
}