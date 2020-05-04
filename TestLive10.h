#pragma once
#include "RepoFile.h"

class TestLive {
private:
    const string fileNameInCSV = "TestGarnituraIn.csv";
    void test();

public:
    TestLive();
    ~TestLive();
    void testAll();
};