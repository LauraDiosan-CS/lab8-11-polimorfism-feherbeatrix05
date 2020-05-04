#include "RepoFileCSV.h"
#include <fstream>
#include "garnituraMarfa.h"
#include "garnituraPersoane.h"
#include <string>

RepoFileCSV::RepoFileCSV() : RepoFile()
{
}

RepoFileCSV::RepoFileCSV(string fileName) : RepoFile(fileName)
{
}

RepoFileCSV::~RepoFileCSV()
{
}

void RepoFileCSV::loadFromFile()
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->garnituri.clear();
		string linie;
		string delim = ",";
		while (getline(f, linie))
		{
			if (linie.substr(0, 2) == "GM")
			{
				linie = linie.erase(0, 3);

				int pos = linie.find(delim);
				string numeModel = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string producator = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double nrVagoane = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double nrGarnitDisp = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double nrGarnitRez = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string incarcatura = linie.substr(0, pos);

				GarnituraMarfa* gm = new GarnituraMarfa(numeModel, producator, nrVagoane, nrGarnitDisp, nrGarnitRez, incarcatura);
				this->garnituri.push_back(gm);
			}
			else if (linie.substr(0, 2) == "GP")
			{
				linie = linie.erase(0, 3);

				int pos = linie.find(delim);
				string numeModel = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string producator = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double nrVagoane = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double nrGarnitDisp = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double nrGarnitRez = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double nrLoc = stod(linie.substr(0, pos));

				GarnituraPersoane* gp = new GarnituraPersoane(numeModel, producator, nrVagoane, nrGarnitDisp, nrGarnitRez, nrLoc);
				this->garnituri.push_back(gp);
			}
		}
		f.close();
	}
}

void RepoFileCSV::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Garnitura* elem : this->garnituri)
		{
			f << elem->toString(",") << endl;
		}
	}
}