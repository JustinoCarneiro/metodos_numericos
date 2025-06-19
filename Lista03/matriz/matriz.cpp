#include "matriz.h"

using namespace std;

void printVector(const Vector& vec, const string& title) {
    cout << title << " [ ";
    for (const double& val : vec) {
        cout << fixed << setprecision(4) << val << " ";
    }
    cout << "]" << endl;
}

void printMatriz(const Matriz& mat, const string& title) {
    cout << title << endl;
    for (const auto& row : mat) {
        cout << "| ";
        for (const double& val : row) {
            cout << fixed << setprecision(4) << setw(10) << val << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}