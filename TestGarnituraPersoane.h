#pragma once
#include"garnituraPersoane.h"
#include"Util.h"


class TestGarnituraPersoane {
private:
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testClone();
	void testGetNrLoc();
	void testSetNrLoc();
	void testAssignmentOperator();
	void testEqualityOperator();
	void testToString();
public:
	void testAll();
};