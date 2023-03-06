#include <iostream>

using namespace std;

class Matrix {
private:
    int _matrix[2][2];
public:
    Matrix() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                this->_matrix[i][j] = 0;
            }
        }
    }

    Matrix(int matrix[2][2]) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                this->_matrix[i][j] = matrix[i][j];
            }
        }
    }

    Matrix operator+(int t) {
        int array2d[2][2] = {{1, 0},
                             {0, 1}};
        Matrix indentityMatrix(array2d);
        Matrix tempRes = indentityMatrix * t; // 4 0 0 4
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                this->_matrix[i][j] += tempRes._matrix[i][j];
            }
        }
        return this->_matrix;
    }

    Matrix operator*(int t) {
        Matrix Res;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                Res._matrix[i][j] = this->_matrix[i][j] * t;
            }
        }
        return Res;
    }

    Matrix operator+(Matrix matrix) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                this->_matrix[i][j] += matrix._matrix[i][j];
            }
        }
        return this->_matrix;
    }

    Matrix transpose() {
        Matrix m;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
               m._matrix[j][i] = this->_matrix[i][j];
            }
        }
        return m;
    }


    void print() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                std::cout << this->_matrix[i][j] << std::endl;
            }
        }
    }
};

int main() {
//    int array2d[2][2] = {{1, 1},
//                         {1, 1}};
//    int t = 4;
//    Matrix matrix(array2d);
//    Matrix matrix1 = matrix + t;
    // 5 1 1 5


//    int array2d[2][2] = {{1, 1},
//                         {1, 1}};
//
//    int array2dt[2][2] = {{2, 2},
//                         {2, 2}};
//    Matrix matrix1(array2d);
//    Matrix matrix2(array2dt);
//    Matrix matrix3 = matrix1 + matrix2;
//

//    matrix3.print();
    // 3 3 3 3

    int array2d[2][2] = {{1, 2},
                         {3, 4}};
    Matrix matrix(array2d);
    Matrix transposedMatrix = matrix.transpose();
    transposedMatrix.print();

    return 0;
}
