#include "instance.h"
#include <regex>

// Voir fichier instance.hpp pour les exemples de fichier d'instance et de solution
//
Instance::Instance() {
    this->n = 0;
    this->matrice_adj = vector<vector<int>>();
	this->liste_aretes = vector<pair<int, int>>();
}

/// Initialisation avec fichier d'entree
Instance::Instance(string const file_name) {
    this->file_name = file_name;
	this->read_file();
}

void Instance::read_file() {
	n = 0;
	int k = 0;
  cout << "It's me"<< endl;
	ifstream fid(this->file_name.c_str(), ios::in);
    if (!fid) {
        std::string msg = "impossible d'ouvrir \"" + file_name + "\"";
        cerr << msg << endl;
        exit(1);
    }

	matrice_adj.push_back(vector<int>());
    string oneLine;
	getline(fid, oneLine);
	oneLine.erase(remove(oneLine.begin(), oneLine.end(), ' '), oneLine.end());
	for (int i = 0 ; i < oneLine.length() ;i++){
		char car = oneLine.at(i);
		int val = atoi(&car);
		this->n++;
		this->matrice_adj[k].push_back(val);
		if(val == 1)
			this->liste_aretes.push_back(make_pair(k, i));
		cout << val << " ";
	}

    while (getline(fid, oneLine)) {
		oneLine.erase(remove(oneLine.begin(), oneLine.end(), ' '), oneLine.end());
		if(oneLine.length() == 1)
			break;
		k++;
		cout << endl;
		matrice_adj.push_back(vector<int>());
		//oneLine est la ligne que l'on veut actuellement lire
		for (int i = 0 ; i < oneLine.length() ;i++){
			char car = oneLine.at(i);
			int val = stoi(&car);
			this->matrice_adj[k].push_back(val);
			// Pour eviter les doublons
			if(val == 1 && k < i)
				this->liste_aretes.push_back(make_pair(k, i));
			cout << val << " ";
		}
    }

	cout << endl;
    fid.close();
}


vector<pair<int,int>> Instance::liste_sommets_isoles(){
  cout<< "Hello"<<endl;
  vector<pair<int,int>> listeSommets = vector<pair<int,int>>();

  for(int i = 0; i < this->n; i++){
    int nbVoisins = 0;
    int voisin = -1;
    for(int j= 0; j < this->n; j++){
      if(matrice_adj[i][j] == 1)
      {nbVoisins++;
      voisin = j;}
    }
    if(nbVoisins == 1){
      listeSommets.push_back(pair<int, int>(i,voisin));
    }
  }

return listeSommets;

}
