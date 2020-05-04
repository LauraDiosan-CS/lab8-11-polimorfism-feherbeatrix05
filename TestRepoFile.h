#pragma once
#include "RepoFile.h"
#include<vector>

class TestRepoFile {
private:
    const string fileNameInTXT = "TestGarnituraIn.txt";
    const string fileNameOutTXT = "TestGarnituraOut.txt";
    const string fileNameInCSV = "TestGarnituraIn.csv";
    const string fileNameOutCSV = "TestGarnituraOut.csv";

    vector<Garnitura*> garnituriIn;

    void testGetSize();
    void testGetAll();
    void testGetGarnitura();
    void testAddGarnitura();
    void testUpdateGarnitura();
    void testDeleteGarnitura();

    void testLoadFromFileTXT();
    void testLoadFromFileCSV();
    void testSavetoFileTXT();
    void testSaveToFileCSV();
public:
    TestRepoFile();
    ~TestRepoFile();
    void testAll();
};
