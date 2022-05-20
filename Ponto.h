#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#ifndef AGRUPAMENTO_H
#define AGRUPAMENTO_H

typedef struct ponto Ponto;

Ponto* readLine (FILE *fp);
Ponto* InicializaPonto();
void DestroiPonto(Ponto *p);
char* getIdPonto(Ponto *p);
void imprimeCoordPonto(Ponto *p);
double distanciaPontos(Ponto *p1, Ponto *p2);

#endif