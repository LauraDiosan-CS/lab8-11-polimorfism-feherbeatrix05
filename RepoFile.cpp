#include<iostream>
#include<string>
#include "RepoFile.h"

RepoFile::RepoFile()
{
	//string filename = "TestGarnituraIn.txt";

}

RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}

RepoFile::~RepoFile()
{
}

void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

vector<Garnitura*> RepoFile::getAll()
{
	return this->garnituri;
}

int RepoFile::getSize()
{
	return this->garnituri.size();
}

Garnitura* RepoFile::getGarnitura(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->garnituri[pos]->clone();
	}
	return new Garnitura();
}
void RepoFile::addGarnitura(Garnitura* g)
{
	this->garnituri.push_back(g->clone());
	this->saveToFile();
}

void RepoFile::updateGarnitura(Garnitura* gVechi, Garnitura* gNou)
{
	for (int i = 0; i<this->garnituri.size(); i++)
	{
		if (*(this->getGarnitura(i)) == *gVechi)
		{
			delete this->garnituri[i];
			this->garnituri[i] = gNou->clone();
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::deleteGarnitura(Garnitura* g)
{
	for (int i = 0; i<this->garnituri.size(); i++)
	{
		
		if (**(this->garnituri.begin() + i) == *g)
		{
			delete this->garnituri[i];
		
			this->garnituri.erase(this->garnituri.begin() + i);
			this->saveToFile();
			return;
		}
	}
}
