#ifndef MATRIX_TESTS_OF_CLASS_H
#define MATRIX_TESTS_OF_CLASS_H

#include <utility>
#include <vector>
#include "../matrix.h"

using namespace std;

class TestMat {

public:
    TestMat();

    void run();

private:
    Mat *matrix;
};

#endif //MATRIX_TESTS_OF_CLASS_H
