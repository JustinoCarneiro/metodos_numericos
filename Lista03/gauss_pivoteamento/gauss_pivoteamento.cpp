#include "gauss_pivoteamento.h"
#include <cmath>
#include <algorithm>
#include "../pivoteamento/pivoteamento.h"

using namespace std;

Vector gaussEliminationPivo(Matriz U, Vector b) {
    int n = U.size();
    Matriz l(n, Vector(n, 0.0));

    for (int i = 0; i < n; ++i) {
        l[i][i] = 1.0;
    }

    for(int i=0; i<n; i++){
        pivoteamento(U, b, i);

        for(int j=i+1; j<n; j++){
            l[j][i] = -(U[j][i]/U[i][i]);

            for(int k=0; k<n; k++){
                U[j][k] = U[j][k] + l[j][i]*U[i][k];
            }
            b[j] = b[j] + l[j][i]*b[i];
        }
    }

    printMatriz(l, "Matriz de multiplicadores:");
    printMatriz(U, "Matriz A após eliminição de Gauss:");
    printVector(b, "Vetor B após eliminação de Gauss:");

    Vector x(n, 0.0);

    for(int i=n-1; i>=0; i--){
        double sum = 0.0;
        for(int j=0; j<n; j++){
            if (i!=j){
                sum += x[j]*U[i][j];
            }
        }
        x[i] = (b[i] - sum)/U[i][i];
    }

    return x;
}

//Denominei as matrizes como "l" e "u", pois serão utilizadas também no método LU