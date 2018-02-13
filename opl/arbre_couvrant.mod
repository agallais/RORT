# modele de sac a dos
# donnees
param n integer >= 0; #nombre de sommets
set N := 1..n;
param G{N, N} binary;
# nombre de partitions
param p integer >= 0;
set P := 1..p;
# ensemble des combinaisons
param comb{P, N} binary;

#variables
var x{i in 1..(n - 1), j in 1..(n - i)} binary;
#pour indiquer si le noeud est un noeud de branchement ou non
var y{i in 1..n} binary;

#objectif
minimize taille : sum{i in 1..n} y[i];

#contraintes
# Pas de boucles
subject to boucles{k in P} : sum{i in 1..(n - 1), j in 1..(n - i)} (comb[k, i]*(1 - comb[k, i + j]) + comb[k, i + j]*(1 - comb[k, i]))*x[i, j] >= 1;
# Que des arêtes existantes
subject to aretes{i in 1..(n - 1), j in 1..(n - i)} : x[i, j] <= G[i, i + j];
# Noeuds de branchement
subject to noeuds{i in 1..n} : n * y[i] + 2 >= sum{j in 1..(n - i)}(x[i, j]) + sum{j in 1..(i-1)}(x[j, i - j]);

###sub model
param edges{i in 1..(n - 1), j in 1..(n - i)};

var subSet{N} binary;

minimize sub : 
	sum{i in 1..(n - 1), j in 1..(n - i)} (subSet[i] * (1 - subSet[i + j]) + subSet[i + j]*(1 - subSet[i]))*edges[i, j];

subject to
	minSize                                  : sum{i in N} subSet[i] >= 1;
	maxSize                                  : sum{i in N} subSet[i] <= n - 1;