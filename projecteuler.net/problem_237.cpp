#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define MOD (int)1e8

template<typename T>
struct Matrix {
    vector<vector<T>> mat;

    // Constructor to initialize matrix with given dimensions
    Matrix(int n, int m) {
        mat = vector<vector<T>>(n, vector<T>(m));
    }

    // Constructor to initialize matrix with a given 2D vector
    Matrix(vector<vector<T>> a) {
        mat = a;
    }

    // Overload operator[] to return a reference to the row
    vector<T>& operator[](int index) {
        return mat[index];
    }

    // Const version of operator[] for read-only access
    const vector<T>& operator[](int index) const {
        return mat[index];
    }

    // Overload operator+ to add two matrices
    Matrix<T> operator+(const Matrix<T>& other) const {
        int n = mat.size();
        int m = mat[0].size();
        Matrix<T> result(n, m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[i][j] = mat[i][j] + other[i][j];
            }
        }
        return result;
    }

    // Overload operator- to subtract two matrices
    Matrix<T> operator-(const Matrix<T>& other) const {
        int n = mat.size();
        int m = mat[0].size();
        Matrix<T> result(n, m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[i][j] = mat[i][j] - other[i][j];
            }
        }
        return result;
    }

    // Overload operator* to multiply two matrices
    Matrix<T> operator*(const Matrix<T>& other) const {
        int n = mat.size();
        int k = mat[0].size();
        int m = other.mat[0].size();
        Matrix<T> result(n, m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int l = 0; l < k; ++l) {
                    result[i][j] += (mat[i][l] * other[l][j]);
                    result[i][j] %= MOD;
                }
            }
        }
        return result;
    }

    // Overload operator/ to divide a matrix by a scalar
    Matrix<T> operator/(T scalar) const {
        int n = mat.size();
        int m = mat[0].size();
        Matrix<T> result(n, m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[i][j] = mat[i][j] / scalar;
            }
        }
        return result;
    }

    // Overload operator^ to raise a matrix to a power (exponentiation)
    Matrix<T> operator^(ll exponent) const {
        int n = mat.size();
        int m = mat[0].size();
        Matrix<T> result(n, m);

        // Initialize result matrix as identity matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[i][j] = (i == j) ? 1 : 0;
            }
        }

        Matrix<T> base = *this;  // Start with the original matrix as base

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = result * base;  // Multiply result by base when exponent is odd
            }
            base = (base * base);
            exponent >>= 1;
        }

        return result;
    }

    // Function to compute the transpose of the matrix
    Matrix<T> transpose() const {
        int n = mat.size();
        int m = mat[0].size();
        Matrix<T> result(m, n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[j][i] = mat[i][j];
            }
        }
        return result;
    }

    // Function to compute the determinant of the matrix (only for 2x2 and 3x3 matrices)
    T determinant() const {
        int n = mat.size();
        int m = mat[0].size();

        if (n != m) {
            throw invalid_argument("Matrix must be square to compute determinant.");
        }

        if (n == 2) {
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        } else if (n == 3) {
            return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
                 - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
                 + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
        } else {
            throw invalid_argument("Determinant computation only supported for 2x2 and 3x3 matrices.");
        }
    }

    // Function to compute the inverse of the matrix (only for 2x2 and 3x3 matrices)
    Matrix<T> inverse() const {
        int n = mat.size();
        int m = mat[0].size();

        if (n != m) {
            throw invalid_argument("Matrix must be square to compute inverse.");
        }

        if (n == 2) {
            T det = determinant();
            if (det == 0) {
                throw invalid_argument("Matrix is singular, cannot invert.");
            }
            Matrix<T> result({{mat[1][1], -mat[0][1]}, {-mat[1][0], mat[0][0]}});
            return result / det;
        } else if (n == 3) {
            T det = determinant();
            if (det == 0) {
                throw invalid_argument("Matrix is singular, cannot invert.");
            }
            Matrix<T> result({
                {mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1], mat[0][2] * mat[2][1] - mat[0][1] * mat[2][2], mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]},
                {mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2], mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0], mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2]},
                {mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0], mat[0][1] * mat[2][0] - mat[0][0] * mat[2][1], mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]}
            });
            return result / det;
        } else {
            throw invalid_argument("Inverse computation only supported for 2x2 and 3x3 matrices.");
        }
    }

    // Function to compute the trace of the matrix (sum of diagonal elements)
    T trace() const {
        int n = mat.size();
        T sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += mat[i][i];
        }
        return sum;
    }

    // Function to print the matrix
    void print() const {
        for (const auto& row : mat) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

signed main() {
    Matrix<ll> a = Matrix<ll>({{2, 2, -2, 1},
                              {1, 0,  0, 0},
                              {0, 1,  0, 0},
                              {0, 0,  1, 0}});
    Matrix<ll> b = Matrix<ll> ({{8}, {4}, {1}, {1}});
    ll p = 1e12;
    auto res = (a^(p-4));
    res = res*b;
    cout << res[0][0];
}   