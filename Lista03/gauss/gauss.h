#ifndef GAUSS_HPP
#define GAUSS_HPP

#include "../matriz/matriz.h"

Vector gaussElimination(Matriz A, Vector b);
Vector gaussEliminationPivoting(Matriz A, Vector b);

#endif // GAUSS_HPP