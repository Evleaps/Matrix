#include <iostream>
#include "matrix.h"
#include "tests/tests_of_class.h"
#include "tests/test_of_extension.h"

/**
 * It is API init different matrices and have a few methods of calculate
 * values of matrices. It job is homework of Lobachevsky University
 *
 * Also, API have tests, please open console.
 *
 * @date 09.12.2018
 * @author Aymaletdinov Roman
 * @author Sovrasov Vladislav
 * @link confluence: https://github.com/sovrasov/C-course-practice/blob/master/laboratory_works/matrix_class.md
 */

int main() {

    TestMat testMat;
    testMat.run();

    TestExtension extension;
    extension.run();

    return 0;
}