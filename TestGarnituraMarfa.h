#pragma once
#include"garnituraMarfa.h"
#include"Util.h"


class TestGarnituraMarfa {
private:
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testClone();
	void testGetIncarcatura();
	void testSetIncarcatura();
	void testAssignmentOperator();
	void testEqualityOperator();
	void testToString();
public:
	void testAll();
};
