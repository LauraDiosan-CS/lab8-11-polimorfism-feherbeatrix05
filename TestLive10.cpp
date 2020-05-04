#include<assert.h>
#include<fstream>
#include<iostream>
#include<string.h>
#include"RepoFile.h"
#include "TestLive10.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "GarnituraMarfa.h"
#include "GarnituraPersoane.h"

void TestLive::test()
{
	RepoFile* repo = new RepoFileCSV(this->fileNameInCSV);
	repo->loadFromFile();
	Garnitura* g1 = new GarnituraMarfa("KBT8", "Fleishmann", 8, 10, 20, "carbuni");
	Garnitura* g2 = new GarnituraPersoane("A0JK", "Neumann", 10, 4, 30,200);
	Garnitura* g3 = new GarnituraMarfa("B1xC", "Aron",11,9, 12, "benzina");
	Garnitura* g4 = new GarnituraPersoane("DIJ9", "Stora", 9, 5, 28,150);
	assert(repo->getSize() == 2);
	assert(*repo->getGarnitura(0) == *g1);
	assert(*repo->getGarnitura(1) == *g2);
	repo->addGarnitura(g3);
	assert(repo->getSize() == 3);
	cout << "Test " << endl;
	assert(*repo->getGarnitura(0) == *g1);
	assert(*repo->getGarnitura(1) == *g2);
	assert(*repo->getGarnitura(2) == *g3);
	repo->addGarnitura(g4);
	cout << "Test2" << endl;
	assert(repo->getSize() == 4);
	assert(*repo->getGarnitura(0) == *g1);
	assert(*repo->getGarnitura(1) == *g2);
	assert(*repo->getGarnitura(2) == *g3);
	assert(*repo->getGarnitura(3) == *g4);



}
TestLive::TestLive()
{
}
TestLive::~TestLive()
{
}

void TestLive::testAll()
{
	this->test();
	
}
