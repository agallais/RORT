#include "instance.h"
#include "solve.h"

int main(int argc, char *argv[]) {

	string filename = string(argv[1]);
	Instance test(filename);

	for(int i = 0; i < test.liste_aretes.size(); i++)
		cout << test.liste_aretes[i].first << " " << test.liste_aretes[i].second << endl;


		// Let's try something

		// First we try to figure out the nodes that will necessarily have more than three neighbors

		vector<pair<int, int>> listeDesSommets = test.liste_sommets_isoles();

		for(int i = 0; i < listeDesSommets.size(); i++){
			cout << listeDesSommets[i].first<< " "<< listeDesSommets[i].second << endl;
		}

		//Now we had those because we don't really have a choice

		int n = test.liste_aretes.size();
		Solve sol;
		sol.solution(test);
		for(int i = 0; i <listeDesSommets.size(); i++){
			sol.add(listeDesSommets[i]);
		}

/*
	Solve sol;
	sol.genere_sol(test);
	
	vector<vector<int>> sol_stup = sol.krusky;
*/


	return (0);
}
