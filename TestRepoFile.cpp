#include<assert.h>
#include<fstream>
#include<iostream>
#include<string.h>
#include "TestRepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "GarnituraMarfa.h"
#include "GarnituraPersoane.h"

void TestRepoFile::testGetSize()
{
	RepoFile* repoFile = new RepoFileTXT();
	assert(repoFile->getSize() == 0);
	repoFile->addGarnitura(new Garnitura());
	assert(repoFile->getSize() == 1);
}

void TestRepoFile::testGetAll()
{
	RepoFile* repoFile = new RepoFileTXT();
	GarnituraMarfa* g1 = new GarnituraMarfa("model1", "macro", 4, 20, 13,"nisip");
	GarnituraPersoane* g2 = new GarnituraPersoane("model2","mini",5 ,20, 12, 23);
	repoFile->addGarnitura(g1);
	repoFile->addGarnitura(g2);
	vector<Garnitura*> garnituri = repoFile->getAll();
	assert(*garnituri[0] == *g1->clone());
	assert(*garnituri[1] == *g2->clone());
}

void TestRepoFile::testGetGarnitura()
{
	RepoFile* repoFile = new RepoFileTXT();
	GarnituraMarfa* g = new GarnituraMarfa("model1", "macro", 4, 20, 13, "nisip");
	repoFile->addGarnitura(g);
	assert(*repoFile->getGarnitura(0) == *g->clone());
	assert(*repoFile->getGarnitura(-1) == *(new Garnitura()));
	assert(*repoFile->getGarnitura(1) == *(new Garnitura()));
}

void TestRepoFile::testAddGarnitura()
{
	RepoFile* repoFile = new RepoFileTXT();
	GarnituraMarfa* g = new GarnituraMarfa("model1","macro",4,20,13,"nisip");
	repoFile->addGarnitura(g);
	assert(*repoFile->getGarnitura(0) == *g->clone());
}

void TestRepoFile::testUpdateGarnitura()
{
	RepoFile* repoFile = new RepoFileTXT();
	GarnituraMarfa* g1 = new GarnituraMarfa("model1", "macro", 4, 20, 13, "nisip");
	repoFile->addGarnitura(g1);
	GarnituraMarfa* g2 = new GarnituraMarfa("model5", "micro", 4, 20, 14, "balast");
	GarnituraMarfa* g3 = new GarnituraMarfa("model3", "macro", 4, 20, 14, "nisip");
	repoFile->updateGarnitura(g3, g2);
	assert(*repoFile->getGarnitura(0) == *g1);
	repoFile->updateGarnitura(g1, g2);
	assert(*repoFile->getGarnitura(0) == *g2);
}

void TestRepoFile::testDeleteGarnitura()
{
	RepoFile* repoFile = new RepoFileTXT();
	GarnituraMarfa* g1 = new GarnituraMarfa("model1", "macro", 4, 20, 13, "nisip");
	repoFile->addGarnitura(g1);
	GarnituraMarfa* g2 = new GarnituraMarfa("model5", "micro", 4, 20, 14, "balast");
	repoFile->deleteGarnitura(g2);
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getGarnitura(0) == *g1);
	repoFile->deleteGarnitura(g1);
	assert(repoFile->getSize() == 0);
}

void TestRepoFile::testLoadFromFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->garnituriIn.size());

	assert(*repoFile->getGarnitura(0) == *this->garnituriIn[0]);
	assert(*repoFile->getGarnitura(1) == *this->garnituriIn[1]);



}

void TestRepoFile::testLoadFromFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->garnituriIn.size());
	assert(*repoFile->getGarnitura(0) == *this->garnituriIn[0]);
	assert(*repoFile->getGarnitura(1) == *this->garnituriIn[1]);
}


void TestRepoFile::testSavetoFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutTXT);
	GarnituraMarfa* newGarnitura = new GarnituraMarfa("model3", "macro", 4, 20, 14, "nisip");
	repoFile->addGarnitura(newGarnitura);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->garnituriIn.size() + 1);
	vector<Garnitura*> garnituri = repoFile->getAll();
	for (int i = 0; i < repoFile->getSize() - 1; i++)
	{
		assert(*garnituri[i] == *this->garnituriIn[i]);
	}
	assert(*garnituri[garnituri.size() - 1] == *newGarnitura);
}

void TestRepoFile::testSaveToFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutCSV);
	GarnituraMarfa* newGarnitura = new GarnituraMarfa("model3", "macro", 4, 20, 14, "nisip");
	repoFile->addGarnitura(newGarnitura);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->garnituriIn.size() + 1);
	vector<Garnitura*> garnituri = repoFile->getAll();
	for (int i = 0; i < repoFile->getSize() - 1; i++)
	{
		assert(*garnituri[i] == *this->garnituriIn[i]);
	}
	assert(*garnituri[garnituri.size() - 1] == *newGarnitura);
}

TestRepoFile::TestRepoFile()
{
	GarnituraMarfa* g1 = new GarnituraMarfa("model1", "macro", 4, 20, 13, "nisip");
	GarnituraPersoane* g2 = new GarnituraPersoane("model2", "mini", 5, 20, 12, 23);
	this->garnituriIn.push_back(g1);
	this->garnituriIn.push_back(g2);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testGetSize();
	this->testGetAll();
	this->testGetGarnitura();
	this->testAddGarnitura();
	this->testUpdateGarnitura();
	this->testDeleteGarnitura();
	this->testLoadFromFileTXT();
	this->testLoadFromFileCSV();
	this->testSavetoFileTXT();
	this->testSaveToFileCSV();
}
