# Théorie des graphes - TP1 : Exercice 5

![image](https://github.com/thomasmargotteau/TDG_TP1/assets/117742441/4c6eff10-52d2-4d75-9020-5c178146c583)

## Points clés de l'exercice 

### 1. Récupérer les données d'un fichier texte

Il contient :
- L'ordre de la matrice d'adjacence de l'exercice
- La matrice d'adjacence
- Les noms des sommets

On utilisera :
- Pour ouvrir le document en mode lecture (read) 
  ```FILE *file=fopen("CheminDaccesdufichier","r");```
- Pour recuperer les valeurs
```fscanf(nameOfFile,"%formatDuCaractereOuDeLaChaine",&variableDansLaquelleOnStocke);```
- Pour fermer le document
  ```fclose(file);```

### 2. Créer les structures

- Structure Sommet contenant un nom et un numéro
```c
typedef struct {
    char *nom;
    int num;
}Sommet;
```
- Structure Graphe contenant un ordre (=nombre de sommets), une matrice d'adjacence (à préparer à l'avance) et un tableau de type *Sommet* (pour y accéder plus facilement)
```c
typedef struct {
    int ordre;
    int **matrice;
    Sommet *tabSommets;
}Graphe;
```

### 3.
