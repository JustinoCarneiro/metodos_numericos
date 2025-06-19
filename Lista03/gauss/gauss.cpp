#include "gauss.h"
#include <cmath>
#include <algorithm>

using namespace std;

Vector gaussElimination(Matriz A, Vector b) {
    int n = A.size();

    for (int k = 0; k < n - 1; ++k) {
        for (int i = k + 1; i < n; ++i) {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= factor * A[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    Vector x(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }
    return x;
}

Vector gaussEliminationPivoting(Matriz A, Vector b) {
    int n = A.size();

    for (int k = 0; k < n - 1; ++k) {
        int max_row_index = k;
        for (int i = k + 1; i < n; ++i) {
            if (abs(A[i][k]) > abs(A[max_row_index][k])) {
                max_row_index = i;
            }
        }
        
        if (max_row_index != k) {
            swap(A[k], A[max_row_index]);
            swap(b[k], b[max_row_index]);
        }

        for (int i = k + 1; i < n; ++i) {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= factor * A[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    Vector x(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }
    return x;
}