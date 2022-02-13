/* LINEAR SYSTEMS IN C++

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: February 13th, 2022 */

#include <iostream>
#include <iomanip>

#include "LinearSystems.hpp"

using namespace std;

void print(int &n, double **matrix, double *vector, double *solution){
    
    for(unsigned i = 0; i < n; i++){

        for(unsigned j = 0; j < n; j++){

            if(j == 0) cout << setprecision(3) << fixed << "\n    |";

            if(j != n - 1) cout << matrix[i][j] << "  ";

            else{

                if(i == n / 2 + n % 2 - 1) 
                    
                    cout << matrix[i][j] << "|  " << "|x" << setprecision(0) << fixed << i + 1 
                         << "| = |" << setprecision(3) << fixed << vector[i] << "|" << endl;

                else 
                    cout << matrix[i][j] << "|  " << "|x" << setprecision(0) << fixed << i + 1 
                         << "|   |" << setprecision(3) << fixed << vector[i] << "|" << endl;

            }

        }

    }

    cout << endl;
    cout << setprecision(3) << fixed << "vetor x:    ";

    for(unsigned i = 0; i < n; i++){

        cout << solution[i] << "  ";

    }

    cout << endl << endl;
    
}

void sucessives_substitutions(int &n, double **lower, double *vector){

    cout << "\nSistema triangular inferior:" << endl;

    double solution[n];
    double soma;

    solution[0] = vector[0] / lower[0][0];

    for(unsigned i = 1; i < n; i++){

        soma = 0;

        for(unsigned j = 0; j < i; j++){

            soma += lower[i][j] * solution[j];

        }

        solution[i] = (vector[i] - soma) / lower[i][i];

    }

    print(n, lower, vector, solution);

}

void retroactives_substitutions(int &n, double **upper, double *vector){

    cout << "\nSistema triangular superior:\n" << endl;

    double solution[n];
    double soma;

    solution[n - 1] = vector[n - 1] / upper[n - 1][n - 1];

    for(int i = n - 2; i >= 0; i--){

        soma = 0;

        for(unsigned j = i + 1; j < n; j++){

            soma += upper[i][j] * solution[j];

        }

        solution[i] = (vector[i] - soma) / upper[i][i];

    }

    print(n, upper, vector, solution);

}
