#ifndef TDG_TP1_ID_H
#define TDG_TP1_ID_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_TAB_NOM 30
typedef struct {
    char *nom;
    int num;
}Sommet;

typedef struct{
    int ordre;
    int **matrice;
    Sommet *tabSommets;
}Graphe;

Sommet iniSommet(int num,char *nom);
void iniGraphe(Graphe *graphe, FILE *file);
void iniTabSommets(Graphe *graphe, FILE *file);

#endif //TDG_TP1_ID_H
