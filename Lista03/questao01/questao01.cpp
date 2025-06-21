#include "../matriz/matriz.h"
#include "../gauss/gauss.h"
#include "../gauss_pivoteamento/gauss_pivoteamento.h"

using namespace std;

int main() {
    Matriz A = {{20, 7, 9}, {7, 30, 8}, {9, 8, 30}};
    Vector b = {16, 38, 38};

    cout << "====== QUESTAO 1: ELIMINACAO DE GAUSS ======" << endl;
    printMatriz(A, "Matriz A inicial:");

    Vector sol_gauss = gaussElimination(A, b);
    printVector(sol_gauss, "a) Solucao Gauss sem pivoteamento:");

    Vector sol_gauss_pivo = gaussEliminationPivo(A, b);
    printVector(sol_gauss_pivo, "b) Solucao Gauss com pivoteamento:");

    cout << endl;
    
    return 0;
}