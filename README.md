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

### 3. Inclure les bibliothèques

Ayant besoin d'écrire dans le terminal, de manipuler des chaines de caractères et d'allouer des espaces dynamiques, nous importons les bibliothèques :
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

### 4. Les sous-programmes

#### 4.A) La procédure initialisation du graphe
```c
void iniGraphe(Graphe *graphe, FILE *file);
```

Sert à :
- lire l'ordre dans le document *data.txt* (qu'on appelle *file* dans le code) et le mettre dans la variable ordre de la structure ***Graphe***
- allouer dynamiquement un espace dynamique pour la matrice d'ordre "ordre" (ici 7)
- remplir la matrice avec les données du fichier
- allouer dynamiquement un espace dynamique pour le tableau de sommets

#### 4.B) La fonction initialisation d'un sommet
```c
Sommet iniSommet(int num,char *nom);
```

Sert à :
- attribuer un nom au sommet
- attribuer un numéro au sommet

#### 4.C) La procédure initialisation du tableau de sommets
```c
void iniTabSommets(Graphe *graphe, FILE *file);
```

Sert à :
- parcourir le tableau de sommets créé préalablement
- lire les noms dans le fichier texte
- employer la fonction ```iniSommet``` pour les attribuer aux sommets

### 5. Le main

- On ouvre le fichier
- On crée notre graphe de type *Graphe*
- On appelle les fonctions ```iniGraphe``` puis ```iniTabSommets```
- On utilise une double itération (2 boucles for) pour parcourir la matrice et on écrit "intel est influencé" lorsque l'on tombe sur un 1
- Et enfin, on libère l'espace alloué :)
- Avant de fermer le fichier
____
## Notes en plus

###### Pour allouer dynamiquement un espace dynamique d'une matrice :

- 1. Allouer un espace dynamique pour un tableau de "ordre" cases. On obtient :

|0|1|2|3|4|5|6|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|


- 2. On alloue ensuite à nouveau un espace dynamique pour un tableau de "ordre" cases, mais cette fois-ci pour chaque case du tableau différent.

|00|01|02|03|04|05|06|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|10|11|12|13|14|15|16|
|20|21|22|23|24|25|26|
|30|31|32|33|34|35|36|
|40|41|42|43|44|45|46|
|50|51|52|53|54|55|56|
|60|61|62|63|64|65|66|
