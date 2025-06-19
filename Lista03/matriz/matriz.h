#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using Matriz = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

void printVector(const Vector& vec, const std::string& title);
void printMatriz(const Matriz& mat, const std::string& title);

#endif