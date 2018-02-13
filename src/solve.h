#ifndef SOLVE_H
#define SOLVE_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "instance.h"

using namespace std;

class Solve {

	public:
		// nom de l'instance (e.g. velib_1_s010_r2_k5..6_v11)
		string file_name;

		// Construteur par défaut
		Solve(){};

		// Le destructeur
		virtual ~Solve() {};

		// Stockage de la solution
		vector<vector<int>> krusky;

		bool pas_un_cycle(pair<int, int>& a_tester);
		void genere_sol(Instance& inst);
};

#endif
//./
