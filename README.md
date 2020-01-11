# Projet BLASter

## Objectif

L’objectif du projet est de développer un compilateur source à source (c’est à dire lisant
un code source et produisant un nouveau code source) permettant d’identifier dans un code les
sous parties correspondant à des fonctions connues disponibles dans des bibliothèques, et de les
remplacer par le bon appel à bibliothèque. Votre compilateur prendra en entrée deux fichiers :
d’une part le code source à modifier, et d’autre part un fichier contenant les spécifications des
fonctions de bibliothèques connues. Il produira en sortie le nouveau fichier C.


## Authors : Team "Clezga"
- MOUSSAOUI Abderahmane SDSC
- BEGRICHE Massinissa SIRIS

## Spécification Générale :

- Notre compilateur supporte un seul type : **int**
- Les structures de contrôle acceptées sont : **if**, **if_else**, **for**, **while**
- Les opérateurs acceptés sont : **+**, **-**, **\***, **/**, **++**, **- -**
- Les variables sont **locales** et **globales**
- Il est possible de définir des **fonctions** simple ou *récursives*


## Spécification détaillée


|  Opérateurs/Instructions  | Support |
|---------------------------|---------|
| expr + expr               |    y    |
| expr - expr               |    y    |
| expr * expr               |    y    |
| expr / expr               |    y    |
| - expr                    |    y    |
| ( expr )                  |    y    |
| id == id                  |    y    |
| id != id                  |    y    |
| id < id                   |    y    |
| id > id                   |    y    |
| id <= id                  |    y    |
| id >= id                  |    y    |
| id++                      |    y    |
| id--                      |    y    |
| ++id                      |    y    |
| --id                      |    y    |
| cond && cond              |    y    |
| cond \|\| cond            |    y    |
| ! cond                    |    y    |
| if (cond) {...}           |    y    |
| if (cond) {...} else {...}|    y    |
| while (cond) {...}        |    y    |
| for (init; cond; it) {...}|    y    |
| printf("chaine")          |    y    |
| tab[n] = {.,.,..}         |    y    |
| tab[1]...[n]              |    y    |
| tab[1][n]= tab[1][n]      |    y    |
| id = tab[1]...[n]         |    y    |
| int f(i,...,n) {...}      |    y    |
