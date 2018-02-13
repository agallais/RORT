# modele de sac a dos
# donnees
param n integer >= 0; #nombre de sommets
set N := 1..n;
param G{N, N} binary;
# nombre de partitions
param p integer >= 0;
set P := 1..p;

#variables
var x{i in N, j in N} binary;
#pour indiquer si le noeud est un noeud de branchement ou non
var y{i in N} binary;
# modelisation polynomiale du flot
var u{i in N} integer;

#objectif
minimize taille : sum{i in N} y[i];

#contraintes
# Nombre total
subject to total : sum{i in N, j in N}(x[i, j]) == n - 1;
# Que des arêtes existantes
subject to aretes{i in N, j in N} : x[i, j] <= G[i, j];
# Noeuds de branchement
subject to noeuds{i in N} : n * y[i] + 2 >= sum{j in N}(x[i, j] + x[j, i]);

# Ce qui rentre + ce qui sort doit valoir au moins 1
subject to flux_tot{i in 1..n} : sum{j in 1..n}(x[i, j] + x[j, i]) >= 1; 
# Si rien ne rentre, rien ne ressort, sauf a la racine
subject to flux_bloq{i in 2..n} : sum{j in 1..n}(x[i, j] - n * x[j, i]) <= 0;
# ordre de visite
subSets {i in N, j in N} : u[j] >= u[i] + 1 - n * (1 - x[i, j]);