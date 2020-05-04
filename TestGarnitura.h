#pragma once
#include"garnitura.h"
#include"Util.h"

class TestGarnitura {

private:
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testClone();
	void testGetNumeModel();
	void testSetNumeModel();
	void testGetProducator();
	void testSetProducator();
	void testGetNrVagoane();
	void testSetNrVagoane();
	void testGetNrGarnitDisp();
	void testSetNrGarnitDisp();
	void testGetNrGarnitRez();
	void testSetNrGarnitRez();
	void testAssignmentOperator();
	void testEqualityOperator();
	void testToString();
public:
	void testAll();
	TestGarnitura();
	~TestGarnitura();

};