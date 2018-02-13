#ifndef INSTANCE_H
#define INSTANCE_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Instance {

	public:
		// nom de l'instance (e.g. velib_1_s010_r2_k5..6_v11)
		string file_name;

		// Construteur par défaut
		Instance();
		// Constructeur acceptant un nom de fichier
		Instance(string);

		// Le destructeur
		virtual ~Instance() {};

		int n; //nombre de sommets
		vector<vector<int>> matrice_adj;
		vector<pair<int, int>> liste_aretes;

		vector<pair<int, int>> liste_sommets_isoles();


		void read_file();
};

#endif
//./
