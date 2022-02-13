/* LINEAR SYSTEMS IN C++

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: February 13th, 2022 */

#ifndef LINEARSYSTEMS_H
#define LINEARSYSTEMS_H

void print(int &n, double **matrix, double *vector, double *solution);

void sucessives_substitutions(int &n, double **lower, double *vector);

void retroactives_substitutions(int &n, double **upper, double *vector);

#endif