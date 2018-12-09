#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <utility>
#include <vector>
#include <ostream>

using namespace std;

class Mat {

public:
    Mat();
    Mat(int columns, int rows);
    Mat(const vector<double> numeric_vector);
    Mat(const double* numeric_arr, int rows);
    Mat(const Mat& other);
    Mat(vector<vector<double>> vec);

    pair<int, int> size() const;
    void print() const;
    vector<vector<double>> getVector() const;
    const double& get(int i, int j);
    void uniform_();

    Mat& operator=(const Mat& other);

    ~Mat();

private:
    vector<vector<double>> vec;
};

Mat operator*(const Mat& lhs, const double alpha);
Mat operator*(const Mat& lhs, const Mat& rhs);
Mat operator-(const Mat& lhs, const Mat& rhs);
Mat operator+ (const Mat& lhs, const Mat& rhs);
bool operator== (const Mat &lhs, const Mat &rhs);
bool operator!= (const Mat &lhs, const Mat &rhs);
ostream& operator<<(ostream& os, const Mat& obj);



#endif //MATRIX_MATRIX_H
