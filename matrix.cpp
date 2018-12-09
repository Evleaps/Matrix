#include "matrix.h"
#include <iostream>

using namespace std;

/**
 * Create empty matrix
 */
Mat::Mat() {
    vec.resize(0, vector<double>(0));
}

/**
 * Create matrix columns * rows
 */
Mat::Mat(int columns, int rows) {
    vec.resize(columns, vector<double>(rows));
}

/**
 * Create matrix 1 * numeric_vector.size, and fill it values from vector
 */
Mat::Mat(const vector<double> numeric_vector) {
    for (double i : numeric_vector) {
        vector<double> tmp = {i};
        vec.push_back(tmp);
    }
}

/**
 * Create matrix 1 * rows, and fill it values from array.
 * Note: If rows more than numeric_arr.size, matrix will be filled random values.
 * Please, see confluence.
 *
 * @Link https://github.com/sovrasov/C-course-practice/blob/master/laboratory_works/matrix_class.md
 */
Mat::Mat(const double *numeric_arr, int rows) {
    for (int i = 0; i < rows; ++i) {
        vector<double> tmp = {numeric_arr[i]};
        vec.push_back(tmp);
    }
}

/**
 * Create matrix of copy other Matrix from constructor, but they have different links
 */
Mat::Mat(const Mat& other) {
    vec.clear();
    vector<vector<double>> vectorTemp(other.getVector());
    vec.swap(vectorTemp);
}

/**
 * Create matrix as vec from constructor
 */
Mat::Mat(vector<vector<double>> vec) {
    this->vec.clear();
    this->vec.swap(vec);
}

/**
 * Return size of matrix, {columns, rows}
 */
pair<int, int> Mat::size() const {
    if (!vec.empty()) {
        return make_pair(vec.size(), vec[0].size());
    }
    return make_pair(0,0);
}

/**
 * Print a matrix
 */
void Mat::print() const {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j];
        }
        cout << endl;
    }
}

/**
 * Return link of value with i,j index. Where i is column, j is row.
 */
const double& Mat::get(int i, int j) {
    return vec[i][j];
}

/**
 * To fill current matrix 0 or 1
 */
void Mat::uniform_() {
    int value = 0;
    if (!vec.empty()) {
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = 0; j < vec[i].size(); ++j) {
                vec[i][j] = value;
                value = (value == 0) ? value + 1 : value - 1;
            }
        }
    }
}

/**
 * Return vector of vectors with value of matrix
 */
vector<vector<double>> Mat::getVector() const {
    return vec;
}

Mat::~Mat() {
    vec.clear();
    cout << "vector was cleared" << endl;
}

Mat& Mat::operator=(const Mat& other) {
    vec.clear();
    vector<vector<double>> vectorTemp(other.getVector());
    vec.swap(vectorTemp);
    return *this;
}

/**
 * @return sum of matrix
 */
Mat operator+(const Mat &lhs, const Mat &rhs) {

    if (lhs.size() != rhs.size()) return Mat();

    vector<vector<double>> result;
    result.resize(lhs.size().first, vector<double>(lhs.size().second));

    for (int i = 0; i < lhs.getVector().size(); ++i) {
        for (int j = 0; j < lhs.getVector()[i].size(); ++j) {
            result[i][j] = lhs.getVector()[i][j] + rhs.getVector()[i][j] ;
        }
    }

    return Mat(result);
}

/**
 * @return matrix subtraction
 */
Mat operator-(const Mat &lhs, const Mat &rhs) {

    if (lhs.size() != rhs.size()) return Mat();

    vector<vector<double>> result;
    result.resize(lhs.size().first, vector<double>(lhs.size().second));

    for (int i = 0; i < lhs.getVector().size(); ++i) {
        for (int j = 0; j < lhs.getVector()[i].size(); ++j) {
            result[i][j] = lhs.getVector()[i][j] - rhs.getVector()[i][j] ;
        }
    }

    return Mat(result);
}

/**
 * Multiplies 2 matrices
 */
Mat operator*(const Mat& lhs, const Mat& rhs) {
    if (lhs.getVector().empty()) return Mat();

    vector<vector<double>> result;
    result.resize(lhs.size().first, vector<double>(lhs.size().second));

    for (int i = 0; i < lhs.getVector().size(); ++i) {
        for (int j = 0; j < lhs.getVector()[i].size(); ++j) {
            result[i][j] = lhs.getVector()[i][j] * rhs.getVector()[j][i] ;
        }
    }

    return Mat(result);
}


/**
 * Multiplies matrix on constant
 */
Mat operator*(const Mat& lhs, const double alpha) {
    if (lhs.getVector().empty()) return Mat();

    vector<vector<double>> result;
    result.resize(lhs.size().first, vector<double>(lhs.size().second));

    for (int i = 0; i < lhs.getVector().size(); ++i) {
        for (int j = 0; j < lhs.getVector()[i].size(); ++j) {
            result[i][j] = lhs.getVector()[i][j] * alpha ;
        }
    }

    return Mat(result);
}

/**
 * Compare value of matrices
 *
 * @return true if values of matrices are equal
 */
bool operator== (const Mat &lhs, const Mat &rhs) {
    if (!lhs.getVector().empty() && !rhs.getVector().empty()) {
        if (lhs.getVector() == rhs.getVector()) {
            return true;
        }
    }
    return false;
}

/**
 * Compare value of matrices
 *
 * @return true if values of matrices are different
 */
bool operator!= (const Mat &lhs, const Mat &rhs) {
    if (!lhs.getVector().empty() && !rhs.getVector().empty()) {
        if (lhs.getVector() != rhs.getVector()) {
            return true;
        }
    }
    return false;
}

/**
 * Output matrix to stream.
 */
ostream& operator<<(ostream& os, const Mat& obj) {
    for (int i = 0; i < obj.size().first; ++i) {
        for (int j = 0; j < obj.size().second; ++j) {
            os<<obj.getVector()[i][j]<<" ";
        }
        os<<endl;
    }
    return os;
}
