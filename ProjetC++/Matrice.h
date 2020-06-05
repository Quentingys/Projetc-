//
// Created by Quentin Gyselinck on 02/06/2020.
//

#ifndef UNTITLED9_MATRICE_H
#define UNTITLED9_MATRICE_H
#include "Vecteur.h"

class Vecteur;
class Matrice {
public:
    void affiche() const; //affiches les elem d'une matrice

    //Constructeurs
    Matrice();
    Matrice(int i, int j);
    Matrice(const Matrice& m);
    Matrice(Vecteur v); //Matrice carré a partir d'un vecteur
    Matrice(Vecteur * tabv, int taille);

    //Destructeur
    ~Matrice();


    //Opérateurs
    Vecteur& operator[](int) const ;
    Matrice& operator=(const Matrice&);
    Matrice operator+(const Matrice &);
    Matrice operator-(const Matrice &);
    Matrice operator*(const Matrice &); //Produit matriciel

    //Fonctions
    //Transposée
    Matrice transpose();
    //produit vecteur matrice
    Vecteur mvprod(Vecteur&);
    //Fonction submat
    Matrice submat(int l1, int l2, int c1, int c2);
    //Fonctions qui récupère la taille des colonnes et lignes d'une matrice : besoin pour la SVD
    int ltaille() const;
    int ctaille() const;


    //Fonctions amies
    friend float norm(const Matrice&);
    friend Matrice operator*(float, const Matrice& );




private:
    //attribus de la classe matrice

    int dims[2];
    Vecteur *mat;


};
Matrice outer(const Vecteur&, const Vecteur&);



#endif //UNTITLED9_MATRICE_H
