#include "instance.h"
#include "solve.h"

int main(int argc, char *argv[]) {
	cout<<"Hello"<< endl;
	string filename = string(argv[1]);
	Instance test(filename);
	cout<< "Hello" << endl;
	for(int i = 0; i < test.liste_aretes.size(); i++)
		cout << test.liste_aretes[i].first << " " << test.liste_aretes[i].second << endl;


		// Let's try something

		// First we try to figure out the nodes that will necessarily have more than three neighbors

		cout<<"Hello"<< endl;
		vector<pair<int, int>> listeDesSommets = test.liste_sommets_isoles();

		for(int i = 0; i < listeDesSommets.size(); i++){

			cout << listeDesSommets[i].first<< " "<< listeDesSommets[i].second << endl;
		}

/*
	Solve sol;
	sol.genere_sol(test);





	vector<vector<int>> sol_stup = sol.krusky;
*/


	return (0);
}
