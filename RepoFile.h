#pragma once
#include "garnitura.h"
#include<vector>

using namespace std;
class RepoFile{
protected:
	vector<Garnitura*> garnituri;
	string fileName;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);

	vector<Garnitura*> getAll();
	int getSize();
	Garnitura* getGarnitura(int pos);
	void addGarnitura(Garnitura* g);
	void updateGarnitura(Garnitura* gVechi, Garnitura* gNou);
	void deleteGarnitura(Garnitura* g);

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};