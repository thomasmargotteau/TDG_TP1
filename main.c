#include "id.h"

Sommet iniSommet(int num,char *nom){
    Sommet s={};
    int taille=strlen(nom); // on recupere le nombre de caracteres du nom
    s.num=num;
    s.nom=malloc(taille * sizeof(char)); // on alloue un espace de "taille" caracteres
    strcpy(s.nom,nom); // on rentre la chaine de caracteres dans le sommet
    return s;
}

void iniGraphe(Graphe *graphe, FILE *file){
    int nb;
    fscanf(file,"%d",&nb); // on lit la premiere valeur du doc = ordre
    graphe->ordre=nb;
    graphe->matrice=calloc(graphe->ordre,sizeof(int)); // on cree une allocation dynimique dont les cases sont initialisees a 0 pour la premiere dimension de la matrice
    for (int i=0;i<graphe->ordre;i++) { // on fait la meme chose pour la deuxieme dimension de la matrice
        graphe->matrice[i] = calloc(graphe->ordre, sizeof(int));
    }
    for (int i=0;i<graphe->ordre;i++) {
        for (int j=0;j<graphe->ordre;j++) {
            fscanf(file, "%d", &nb); // on lit les chiffres de la matrice du document texte
            graphe->matrice[i][j] = nb; // on les ajoute dans le tableau
        }
    }
    graphe->tabSommets= calloc(graphe->ordre, sizeof(Sommet)); // on cree une allocation dynimique dont les cases sont initialisees a 0 pour le tableau de sommets
}

void iniTabSommets(Graphe *graphe, FILE *file){
    char nom[TAILLE_TAB_NOM]; // on cree une chaine de caractere qui contiendra momentanement les noms
    for (int i=0;i<graphe->ordre;i++) {
        fscanf(file,"%s",nom); // on lit les noms dans le fichier texte
        graphe->tabSommets[i] = iniSommet(i, nom); // on ajoute les noms + les numeros dans le tableau de sommets
        for(int j=0;j<TAILLE_TAB_NOM;j++) // on remet notre chaine de caractere a 0 pour pas melanger les caracteres
            nom[j]='\0';
    }
}

int main() {
    FILE *file= fopen("C:\\Users\\thoma\\CLionProjects\\TDG_TP1\\data.txt","r"); // on ouvre le fichier
    Graphe graphe={};
    iniGraphe(&graphe,file); // initialisation du graphe
    iniTabSommets(&graphe,file); // initialisation des sommets
    for (int i=0;i<graphe.ordre;i++) {
        //printf("\n");
        for (int j = 0; j < graphe.ordre; j++) {
            //printf("%d ", graphe.matrice[i][j]);
            if (graphe.matrice[i][j]==1) // Si la matrice d'adjacence nous donne 1, alors intel est influence par intel
                printf("%s est influence par %s\n",graphe.tabSommets[i].nom,graphe.tabSommets[j].nom);
        }
    }
    /*for (int i=0;i<graphe.ordre;i++) {
        printf("\n%s, sommet %d",graphe.tabSommets[i].nom, graphe.tabSommets[i].num);
    }*/
    for (int i=0;i<graphe.ordre;i++) { // liberation de la 2eme dimension de la matrice + des tableaux de sommets
        free(graphe.matrice[i]);
        free(graphe.tabSommets[i].nom);
    }
    free(graphe.matrice); // liberation de la 1ere dimension de la matrice
    fclose(file); // on ferme le fichier
    return 0;
}
