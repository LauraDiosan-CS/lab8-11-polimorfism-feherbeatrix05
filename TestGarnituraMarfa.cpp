#include "TestGarnituraMarfa.h"
#include <assert.h>
#include<iostream>
#include<fstream>
#include<string.h>

void TestGarnituraMarfa::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetIncarcatura();
	this->testSetIncarcatura();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}

void TestGarnituraMarfa::testImplicitConstructor()
{
	GarnituraMarfa g;
	assert(g.getNumeModel().empty());
	assert(g.getProducator().empty());
	assert(g.getNrVagoane() == 0);
	assert(g.getNrGarnitDisp() == 0);
	assert(g.getNrGarnitRez() == 0);
}

void TestGarnituraMarfa::testConstructorWithParameters()
{
	GarnituraMarfa g("model1", "macro", 4, 20, 13,"nisip");
	assert(g.getNumeModel() == "model1");
	assert(g.getProducator() == "macro");
	assert(g.getNrVagoane() == 4);
	assert(g.getNrGarnitDisp() == 20);
	assert(g.getNrGarnitRez() == 13);
}
void TestGarnituraMarfa::testCopyConstructor()
{
	GarnituraMarfa g1("model1", "macro", 4, 20, 13 ,"nisip");
	GarnituraMarfa g2(g1);
	assert(g2.getNumeModel() == g1.getNumeModel());
	assert(g2.getProducator() == g1.getProducator());
	assert(g2.getNrVagoane() == g1.getNrVagoane());
	assert(g2.getNrGarnitDisp() == g1.getNrGarnitDisp());
	assert(g2.getNrGarnitRez() == g1.getNrGarnitRez());
}

void TestGarnituraMarfa::testClone()
{
	GarnituraMarfa g("model1", "macro", 4, 20, 13,"nisip");
	GarnituraMarfa* gClone =(GarnituraMarfa*) g.clone();
	assert(g == *gClone);
	assert(&g != gClone);
}
void TestGarnituraMarfa::testGetIncarcatura()
{
	GarnituraMarfa g("model1", "macro", 4, 20, 13,"nisip");
	assert(g.getIncarcatura() == "nisip");
}

void TestGarnituraMarfa::testSetIncarcatura()
{
	GarnituraMarfa g;
	g.setIncarcatura("nisip");
	assert(g.getIncarcatura() == "nisip");
}
void TestGarnituraMarfa::testAssignmentOperator()
{
	GarnituraMarfa g1("model1", "macro", 4, 20, 13,"nisip");
	GarnituraMarfa g2;
	g2 = g1;
	assert(g2.getNumeModel() == g1.getNumeModel());
	assert(g2.getProducator() == g1.getProducator());
	assert(g2.getNrVagoane() == g1.getNrVagoane());
	assert(g2.getNrGarnitDisp() == g1.getNrGarnitDisp());
	assert(g2.getNrGarnitRez() == g1.getNrGarnitRez());

}
void TestGarnituraMarfa::testEqualityOperator()
{
	GarnituraMarfa g1("model1", "macro", 4, 20, 13,"nisip");
	GarnituraMarfa g2 = g1;
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

void TestGarnituraMarfa::testToString()
{
	GarnituraMarfa g("model1", "macro", 4, 20, 13,"nisip");
	assert(g.toString(" ") == "GM model1 macro 4 20 13 nisip");
	assert(g.toString(",") == "GM,model1,macro,4,20,13,nisip");
}

