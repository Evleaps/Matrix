#include <iostream>
#include "tests_of_class.h"

TestMat::TestMat() {}

void TestMat::run() {

    cout << "---------  Mat tests  ---------" << endl;

    Mat *matrix;

    matrix = new Mat();
    cout << "matrix.size(): " << matrix->size().first << "x" << matrix->size().second << endl;
    matrix->print();
    delete matrix;

    cout << "---------------------------" << endl;

    matrix = new Mat(2,3);
    cout << "matrix.size(): " << matrix->size().first << "x" << matrix->size().second << endl;
    matrix->print();
    delete matrix;

    cout << "---------------------------" << endl;

    const vector<double> testVector = {1,3,56,4};
    matrix = new Mat(testVector);
    cout << "matrix.size(): " << matrix->size().first << "x" << matrix->size().second << endl;
    matrix->print();
    delete matrix;

    cout << "---------------------------" << endl;

    const double testArr[] = {3,2,1,0};
    matrix = new Mat(testArr, 9);
    cout << "matrix.size(): " << matrix->size().first << "x" << matrix->size().second << endl;
    matrix->print();
    delete matrix;

    cout << "---------------------------" << endl;

    std::vector<double> vector = {1,2,3,4};
    Mat *testMatrix = new Mat(vector);
    matrix = new Mat(*testMatrix);

    cout << "matrix.size(): " << matrix->size().first << "x" << matrix->size().second << endl;

    if (equal(testMatrix->getVector().begin(), testMatrix->getVector().end(), matrix->getVector().begin())) {
        cout << "matrices have equal links, "<< endl;
    } else {
        cout << "matrices have different links, " << endl;
    }

    if (testMatrix->getVector() == matrix->getVector()) {
        cout << "matrices have equal values"<< endl;
    } else {
        cout << "matrices have different values" << endl;
    }
    delete matrix;

    cout << "---------------------------" << endl;

    matrix = new Mat(3,3);
    matrix->uniform_();
    double val = matrix->get(1, 0);
    cout << "matrix.size(): " << matrix->size().first << "x" << matrix->size().second << endl;
    cout << "val: " << val << endl;
    matrix->print();

    delete matrix;

    cout << "---------------------------" << endl;

    matrix = new Mat(9,9);
    matrix->uniform_();
    cout << "matrix.size(): " << matrix->size().first << "x" << matrix->size().second << endl;
    matrix->print();
    delete matrix;
}
