#include "TestGarnituraPersoane.h"
#include <assert.h>
#include<iostream>
#include<fstream>
#include<string.h>

void TestGarnituraPersoane::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetNrLoc();
	this->testSetNrLoc();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}

void TestGarnituraPersoane::testImplicitConstructor()
{
	GarnituraPersoane g;
	assert(g.getNumeModel().empty());
	assert(g.getProducator().empty());
	assert(g.getNrVagoane() == 0);
	assert(g.getNrGarnitDisp() == 0);
	assert(g.getNrGarnitRez() == 0);
}

void TestGarnituraPersoane::testConstructorWithParameters()
{
	GarnituraPersoane g("model1", "macro", 4, 20, 13, 23);
	assert(g.getNumeModel() == "model1");
	assert(g.getProducator() == "macro");
	assert(g.getNrVagoane() == 4);
	assert(g.getNrGarnitDisp() == 20);
	assert(g.getNrGarnitRez() == 13);
}
void TestGarnituraPersoane::testCopyConstructor()
{
	GarnituraPersoane g1("model1", "macro", 4, 20, 13, 23);
	GarnituraPersoane g2(g1);
	assert(g2.getNumeModel() == g1.getNumeModel());
	assert(g2.getProducator() == g1.getProducator());
	assert(g2.getNrVagoane() == g1.getNrVagoane());
	assert(g2.getNrGarnitDisp() == g1.getNrGarnitDisp());
	assert(g2.getNrGarnitRez() == g1.getNrGarnitRez());
}

void TestGarnituraPersoane::testClone()
{
	GarnituraPersoane g("model1", "macro", 4, 20, 13, 23);
	GarnituraPersoane* gClone = (GarnituraPersoane*)g.clone();
	assert(g == *gClone);
	assert(&g != gClone);
}
void TestGarnituraPersoane::testGetNrLoc()
{
	GarnituraPersoane g("model1", "macro", 4, 20, 13, 23);
	assert(g.getNrLoc() == 23);
}

void TestGarnituraPersoane::testSetNrLoc()
{
	GarnituraPersoane g;
	g.setNrLoc(23);
	assert(g.getNrLoc() == 23);
}

void TestGarnituraPersoane::testAssignmentOperator()
{
	GarnituraPersoane g1("model1", "macro", 4, 20, 13, 23);
	GarnituraPersoane g2;
	g2 = g1;
	assert(g2.getNumeModel() == g1.getNumeModel());
	assert(g2.getProducator() == g1.getProducator());
	assert(g2.getNrVagoane() == g1.getNrVagoane());
	assert(g2.getNrGarnitDisp() == g1.getNrGarnitDisp());
	assert(g2.getNrGarnitRez() == g1.getNrGarnitRez());

}
void TestGarnituraPersoane::testEqualityOperator()
{
	GarnituraPersoane g1("model1", "macro", 4, 20, 13, 23);
	GarnituraPersoane g2 = g1;
	assert(g1 == g2);
	g2.setNumeModel("model1");
	assert((g1 == g2));
	g2.setNumeModel(g1.getNumeModel());
	assert(g1 == g2);
	g2.setProducator("macro");
	assert((g1 == g2));
	g2.setProducator(g1.getProducator());
	assert(g1 == g2);
	g2.setNrVagoane(4);
	assert((g1 == g2));
	g2.setNrVagoane(g1.getNrVagoane());
	assert(g1 == g2);
	g2.setNrGarnitDisp(20);
	assert((g1 == g2));
	g2.setNrGarnitDisp(g1.getNrGarnitDisp());
	assert(g1 == g2);
	g2.setNrGarnitRez(13);
	assert((g1 == g2));
	g2.setNrGarnitRez(g1.getNrGarnitRez());
	assert(g1 == g2);
}

void TestGarnituraPersoane::testToString()
{
	GarnituraPersoane g("model1", "macro", 4, 20, 13, 23);
	assert(g.toString(" ") == "GP model1 macro 4 20 13 23");
	assert(g.toString(",") == "GP,model1,macro,4,20,13,23");
}


