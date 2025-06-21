#include "pivoteamento.h"


void pivoteamento(Matriz& A, Vector& b, int k){
    int n = A.size();

    for(int i=0; i<n; i++){
        double max = A[i][k];
        if(max>A[k][k]){
            for(int j=0; j<n; j++){
                double aux = A[k][j];
                A[k][j] = A[i][j];
                A[i][j] = aux;
            }
            
            double aux_b = b[i];
            b[i] = b[k];
            b[k] = aux_b;
        }
    }
}
