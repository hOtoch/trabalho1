#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"


typdef struct mst Mst;

Mst* criaVertice(Ponto* p);
void liberaVertice(Mst* m);
Mst* criaAresta(double** Matriz,int numPontos);