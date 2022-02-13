/* LINEAR SYSTEMS IN C++

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: February 13th, 2022 */

#include <iostream>

#include "LinearSystems.hpp"

using namespace std;

int main(){

    int ordem;

    cin >> ordem;

    double **matrix;

    matrix = new double *[ordem];

    for(unsigned i = 0; i < ordem; i++){

        matrix[i] = new double[ordem];

    }

    double vector[ordem];

    for(unsigned i = 0; i < ordem; i++){

        for(unsigned j = 0; j < ordem; j++){

            cin >> matrix[i][j];

        }

    }

    for(unsigned i = 0; i < ordem; i++){

        cin >> vector[i];

    }

    if(matrix[0][ordem - 1] != 0){

        retroactives_substitutions(ordem, matrix, vector);

    }

    else{

        sucessives_substitutions(ordem, matrix, vector);

    }

    for(unsigned i = 0; i < ordem; i++){

        delete(matrix[i]);

    }

    delete(matrix);

    return 0;

}