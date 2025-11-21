#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

// Ring abstract class, with underlying set T
template <typename T>
class Semiring {
protected:
    T add_identity;
    T mult_identity;
    function<T(T,T)> add;
    function<T(T,T)> mult;
public:
    virtual add()
};

template <Semiring R:>
class SemiringObject {
    
}

template <typename T>
struct Ring {
    T data;
    function<T(T,T)> add;
    function<T(T,T)> mult;

    Ring(T data, function<T(T,T)> a)

    Ring operator+(const Matrix& other) const {

    }
}

template <typename T>
struct Matrix {
    int n;
    vector<vector<T>> data;
    Matrix(int n) : n(n), data(n, vector<T>(n)) {}
    
    Matrix operator+(const Matrix& other) const {
        Matrix out(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return out;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix out(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    out[i][j] = out[i][j] + data[i][k] * data[k][j];
                }
            }
        }
    }
    
};

template <typename T>
Matrix<T> id(int n) {
    Matrix<T> out(n);
    for (int i = 0; i < n; i++) {
        
    }
}

template <typename T>
T pow(T& base, int exp) {
    T out = id(base.n);
    T cur =
    while (exp) {
        if (exp & 1) {
            out = base * out;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    return 0;
}
