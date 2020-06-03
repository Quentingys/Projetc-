//
// Created by Quentin Gyselinck on 02/06/2020.
//

#ifndef UNTITLED9_MATRICE_H
#define UNTITLED9_MATRICE_H
#include "Vecteur.h"


class Matrice {
public:
    void affiche() const; //affiches les elem d'une matrice

    //Constructeurs
    Matrice(int i, int j);


    //Opérateurs
    Vecteur& operator[](int) const;




private:
    //attribus de la classe matrice
    Vecteur *mat;
    int dims[];



};


#endif //UNTITLED9_MATRICE_H
