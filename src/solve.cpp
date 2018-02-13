#include "solve.h"

bool Solve::pas_un_cycle(pair<int, int>& a_tester){
	vector<int> sommets_testes = vector<int>(krusky.size(), -1);
	vector<int> sommets_courants = vector<int>();
	sommets_courants.push_back(a_tester.first);
	int sommet_courant;
	bool success = true;

	while(sommets_courants.size() > 0 && success){
		sommet_courant = sommets_courants.back();
		sommets_courants.pop_back();

		//On parcourt pour verifier les cycles
		for(int i = 0; i < krusky.size(); i++){
			// Soit relie par une arete
			if(krusky[sommet_courant][i] == 1 || krusky[i][sommet_courant] == 1){

				if((sommets_testes[i] != -1 || i == a_tester.first) && sommets_testes[sommet_courant] != i){ //a deja ete visite, mais pas de i
						success = false;
						break;
				}

				// Sinon, si pas deja teste (pour eviter les allers-retours, on continue le parcours
				if(i != a_tester.first && sommets_testes[i] == -1){
					sommets_testes[i] = sommet_courant;
					sommets_courants.push_back(i);
				}
			}
		}
	}

	return success;
}

void Solve::genere_sol(Instance& inst) {
	krusky = vector<vector<int>>(inst.n, vector<int>(inst.n, 0));
	int nb_aretes = 0;

	for(int i = 0; i < inst.liste_aretes.size(); i++){
		if(nb_aretes == inst.n - 1){
			break;
		}
		else{
			pair<int, int> a_tester = inst.liste_aretes[i];
			krusky[a_tester.first][a_tester.second] = 1;
			krusky[a_tester.second][a_tester.first] = 1;
			// Si on ne forme pas un nouveau cycle on garde l'arete
			if(pas_un_cycle(a_tester)){
				nb_aretes++;
				cout << "Arete choisie " << a_tester.first + 1 << " " << a_tester.second + 1 << endl;
			}
			// Sinon on l'enleve
			else{
				krusky[a_tester.first][a_tester.second] = 0;
				krusky[a_tester.second][a_tester.first] = 0;
			}
		}
	}
	return;
}


void Solve::solution(Instance& inst){
krusky = vector<vector<int>>(inst.n, vector<int>(inst.n,0));
return;
}

void Solve::add(pair<int,int> arete){
	this->krusky[arete.first][arete.second] = 1;
	this->krusky[arete.second][arete.first] = 1;
};
