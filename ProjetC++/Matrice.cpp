//
// Created by Quentin Gyselinck on 02/06/2020.
//

#include "Matrice.h"
#include "Vecteur.h"
#include <iostream>
#include <cmath>

using namespace std;

void Matrice::affiche() const {
    for (int j = 0; j < dims[1]; j++){
        cout << endl;
        for (int i = 0; i < dims[0]; i++){
            cout << mat[i][j];
        }
    }
}

Matrice::Matrice(int i, int j){
    int dims [] = {i,j};
    if (i<= 0 || j <= 0){
        cout << "Taille négative ou nulle";
    }
    else {
        mat = new Vecteur[dims[1]];
        for (int l = 0; l < dims[1]; l++){
            mat[l] = *new Vecteur(dims[0]);
        }
    }

}

// pr tester et que affiche marche il faut définir la recherche mat[][]
Vecteur& Matrice::operator[](int i) const{
    if (i<0 || i >= dims[1] ){
        cout<< " La recherche ne correspond pas a la matrice, indice : "<< i << endl;
        Vecteur v = Vecteur(1);
        return v;

        // encore pr empêcher warning, mais attention si on se trompe on nous retourne un vecteur avec un 0 pas bien encore
    }
    else {
        return mat[i];
    }

}