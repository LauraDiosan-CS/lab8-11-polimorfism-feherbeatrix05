#include <iostream>
#include "TestRepoFile.h"
#include <string>
#include "RepoFile.h"
#include "RepoFileCSV.h"
#include "TestGarnitura.h"
#include "TestGarnituraMarfa.h"
#include "TestGarnituraPersoane.h"
#include "TestLive10.h"

using namespace std;
int main()
{
	/*TestGarnitura testGarnitura;
	testGarnitura.testAll();
	TestGarnituraMarfa testGarnituraMarfa;
	testGarnituraMarfa.testAll();
	TestGarnituraPersoane testGarnituraPersoane;
	testGarnituraPersoane.testAll();

	TestRepoFile testRepoFile;
	testRepoFile.testAll();*/


	TestLive testLive;
	testLive.testAll();
	cout << "Toate testele functioneaza";



}