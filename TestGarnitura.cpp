#include "TestGarnitura.h"
#include <assert.h>
#include<iostream>
#include<fstream>
#include<string.h>

TestGarnitura::TestGarnitura() {

}

TestGarnitura::~TestGarnitura() {

}
void TestGarnitura::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testGetNumeModel();
	this->testSetNumeModel();
	this->testGetProducator();
	this->testSetProducator();
	this->testGetNrVagoane();
	this->testSetNrVagoane();
	this->testGetNrGarnitDisp();
	this->testSetNrGarnitDisp();
	this->testGetNrGarnitRez();
	this->testSetNrGarnitRez();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}

void TestGarnitura::testImplicitConstructor()
{
	Garnitura g;
	assert(g.getNumeModel().empty());
	assert(g.getProducator().empty());
	assert(g.getNrVagoane() == 0);
	assert(g.getNrGarnitDisp() == 0);
	assert(g.getNrGarnitRez() == 0);
}

void TestGarnitura::testConstructorWithParameters()
{
	Garnitura g("model1", "macro", 4, 20, 13);
	assert(g.getNumeModel() == "model1");
	assert(g.getProducator() == "macro");
	assert(g.getNrVagoane() == 4);
	assert(g.getNrGarnitDisp() == 20);
	assert(g.getNrGarnitRez() == 13);
}

void TestGarnitura::testCopyConstructor()
{
	Garnitura g1("model1", "macro", 4 ,20, 13);
	Garnitura g2(g1);
	assert(g2.getNumeModel() == g1.getNumeModel());
	assert(g2.getProducator() == g1.getProducator());
	assert(g2.getNrVagoane() == g1.getNrVagoane());
	assert(g2.getNrGarnitDisp() == g1.getNrGarnitDisp());
	assert(g2.getNrGarnitRez() == g1.getNrGarnitRez());
}

void TestGarnitura::testClone()
{
	Garnitura g("model1", "macro", 4, 20, 13);
	Garnitura* gClone = g.clone();
	assert(g == *gClone);
	assert(&g != gClone);
}

void TestGarnitura::testGetNumeModel()
{
	Garnitura g("model1", "macro", 4, 20, 13);
	assert(g.getNumeModel() == "model1");
}

void TestGarnitura::testSetNumeModel()
{
	Garnitura g;
	g.setNumeModel("model1");
	assert(g.getNumeModel() == "model1");
}

void TestGarnitura::testGetProducator()
{
	Garnitura g("model1", "macro", 4, 20, 13);
	assert(g.getProducator() == "macro");
}

void TestGarnitura::testSetProducator()
{
	Garnitura g;
	g.setProducator("macro");
	assert(g.getProducator() == "macro");
}
void TestGarnitura::testGetNrVagoane()
{
	Garnitura g("model1", "macro", 4, 20, 13);
	assert(g.getNrVagoane() == 4);
}

void TestGarnitura::testSetNrVagoane()
{
	Garnitura g;
	g.setNrVagoane(4);
	assert(g.getNrVagoane() == 4);

}

void TestGarnitura::testGetNrGarnitDisp()
{
	Garnitura g("model1", "macro", 4, 20, 13);
	assert(g.getNrGarnitDisp() == 20);
}

void TestGarnitura::testSetNrGarnitDisp()
{
	Garnitura g;
	g.setNrGarnitDisp(20);
	assert(g.getNrGarnitDisp() == 20);
}

void TestGarnitura::testGetNrGarnitRez()
{
	Garnitura g("model1", "macro", 4, 20, 13);
	assert(g.getNrGarnitRez() == 13);
}

void TestGarnitura::testSetNrGarnitRez()
{
	Garnitura g;
	g.setNrGarnitRez(13);
	assert(g.getNrGarnitRez() == 13);
}




void TestGarnitura::testAssignmentOperator()
{
	Garnitura g1("model1", "macro", 4, 20, 13);
	Garnitura g2;
	g2 = g1;
	assert(g2.getNumeModel() == g1.getNumeModel());
	assert(g2.getProducator() == g1.getProducator());
	assert(g2.getNrVagoane() == g1.getNrVagoane());
	assert(g2.getNrGarnitDisp() == g1.getNrGarnitDisp());
	assert(g2.getNrGarnitRez() == g1.getNrGarnitRez());

}

void TestGarnitura::testEqualityOperator()
{
	Garnitura g1("model1", "macro", 4, 20, 13);
	Garnitura g2 = g1;
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

void TestGarnitura::testToString()
{
	Garnitura g("model1", "macro", 4, 20, 13);
	assert(g.toString(" ") == "model1 macro 4 20 13");
	assert(g.toString(",") == "model1,macro,4,20,13");
}
