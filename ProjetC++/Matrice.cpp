//
// Created by Quentin Gyselinck on 02/06/2020.
//

#include "Matrice.h"
#include "Vecteur.h"
#include <iostream>
#include <cmath>

using namespace std;

void Matrice::affiche() const {

    for (int i = 0; i < dims[0]; i++){
        cout << "[ ";
        for (int j = 0; j < dims[1]; j++){
            float a = mat[j][i];
            cout << a << " ";
        }

        cout << " ]" << endl;

    }
    cout << "Dimensions : " << dims[0] << " x " << dims[1] << endl << endl;

}
//Constructeur par défaut
Matrice :: Matrice (){
    mat = nullptr ;
}
//Constructeur avec des entiers
Matrice::Matrice(int i, int j){

    dims[0]=i;
    dims[1]=j;

    mat = new Vecteur [dims[1]];

    for (int l = 0; l < dims[1]; l++) {
        mat[l] = *new Vecteur(dims[0]);
    }
}

//Constructeur de recopie
Matrice::Matrice(const Matrice& m){
    dims[0]=m.dims[0];
    dims[1]=m.dims[1];
    mat = new Vecteur [dims[1]];
    for (int j = 0; j<dims[1]; j++){
        mat[j] = m.mat[j];
    }
}

//Constructeur à partir d'un vecteurs
Matrice::Matrice(Vecteur v) {
    dims[0] = v.taille();
    dims[1] = v.taille();
    mat = new Vecteur[dims[1]];

    for (int j = 0; j < dims[1]; j++) {
        mat[j] = *new Vecteur(dims[0]);
    }
    for (int j = 0; j < dims[1]; j++){
        mat[j][j] = v[j];

    }
}
//Constructeur à partir d'un tableau de vecteurs
Matrice::Matrice(Vecteur *tabv, int taille){
    dims[1] = taille;
    dims[0] = tabv[0].taille();
    mat = new Vecteur[dims[1]];
    for (int j = 0; j < dims[1]; j++){
        mat[j] = tabv[j];
    }
}


//Destructeur
Matrice::~Matrice(){
        delete [] mat;
}

//Opérateurs
Vecteur& Matrice::operator[](int i) const {
//    if (i<0 || i >= dims[1] ){
//      cout<< " La recherche ne correspond pas a la matrice, indice : "<< i << endl;

//        Vecteur v = Vecteur(1);
//        return v;
//    }

    // encore pr empêcher warning, mais attention si on se trompe on nous retourne un vecteur avec un 0 pas bien encore
//    else {
    return mat[i];
}

//}
//Surdéfinition de l'opérateur d'affectation
Matrice& Matrice::operator=(const Matrice& m) {
    if (this != &m){
        dims[0] = m.dims[0];
        dims[1] = m.dims[1];
        mat = new Vecteur[dims[1]];
        for (int j=0; j<dims[1]; j++){
            mat[j] = m.mat[j];
        }
    }
    return *this;
}

Matrice Matrice::operator+(const Matrice& m){
    if (dims[0] != m.dims[0] || dims[1] != m.dims[1]){
        cout << "Les matrices n'ont pas les mêmes dimensions" << endl;
        Matrice m1(1,1);
        return m1;
    }
    else {
        Matrice m1(dims[0], dims[1]);
        for (int j = 0; j < dims[1]; j++){
            m1[j] = mat[j] + m.mat[j];
        }
        return m1;
    }
}

Matrice Matrice::operator-(const Matrice& m){
    if (dims[0] != m.dims[0] || dims[1] != m.dims[1]){
        cout << "Les matrices n'ont pas les mêmes dimensions" << endl;
        Matrice m1(1,1);
        return m1;
    }
    else {
        Matrice m1(dims[0], dims[1]);
        for (int j = 0; j < dims[1]; j++){
            m1[j] = mat[j] - m.mat[j];
        }
        return m1;
    }
}

Matrice Matrice::operator*(const Matrice& m){
    if (dims[1] != m.dims[0]){
    cout << "Les dimensons des matrices ne sont pas adapté au produit matriciel" << endl;
       Matrice m1(1,1);
        return m1;
    }
    else {
        Matrice m1(dims[0],m.dims[1]);//matrice résultat
        Matrice m2 (mat, dims[1]);//matrice à gauche de l'opérateur
        Matrice m2T = m2.transpose();//transposé pour utiliser dot
        for (int i =0; i< dims[0];i++){
            for (int j=0; j< m.dims[1]; j++){
                m1[j][i] = dot(m2T[i],m[j]);
            }
        }
        return m1;
    }
}

//Transposé matrice, on s'en servira pour le produit matriciel
Matrice Matrice::transpose() {
    Vecteur *tabv = new Vecteur[dims[0]];
    for (int i=0; i<dims[0]; i++) {
        Vecteur v(dims[1]);
        for (int j = 0; j<dims[1]; j++) {
            v[j] = mat[j][i];
        }
        tabv[i] = v;
    }
    Matrice m(tabv,dims[0]);
    return m;
}

Vecteur Matrice::mvprod(Vecteur& v){
    if (v.taille() != dims[1]){
        cout << "La dimension du vecteur est différente de la dimension colonne de la matrice.";
        Vecteur v1(1);
        return v1;
    }
    else{
        int l = v.taille();
        Vecteur v1(l);
        for (int j=0; j<l; j++){
            v1[j] = dot(mat[j], v);
        }
        return v1;
    }
}

Matrice Matrice::submat(int l1, int l2, int c1, int c2){
    if (l1 > l2 || c1 > c2 || l2 > dims[0] || c2 > dims[1]){
        cout << "La sous matrice demandée est impossible à définir";
        Matrice m(1,1);
        return m;
    }
    else {
        int l = l2 - l1 + 1;
        int c = c2 - c1 + 1;
        Matrice m(l,c);
        for (int i = l1 - 1; i < l2; i++){
            for (int j = c1 - 1; j < c2; j++){
                m[j - c1 + 1][i - l1 + 1] = mat [j][i];
            }
        }
        return m;
    }
}


float norm(const Matrice& m) {
    float result = 0;
    int c = m.dims[1];
    int l = m.dims[0];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            result += m[j][i] * m[j][i];
        }
    }
    result = sqrt(result);
    return result;
}

Matrice operator * (float a, const Matrice& m){
    Matrice result = m;
    for (int i = 0; i < m.dims[0]; i++) {
        for (int j = 0; j < m.dims[1]; j++) {
            result[j][i] = a * m[j][i];
        }

    }
    return result;

}

Matrice outer(const Vecteur& v1, const Vecteur& v2){
    if (v1.taille() != v2.taille()){
        cout << "Les vecteurs de sont pas de même taille, on ne peut pas effectué le produit externe";
        Matrice m(1,1);
        return m;

    }
    Matrice m(v1.taille());
    for (int i = 0; i < v1.taille(); i++) {
        for (int j = 0; j < v1.taille(); j++){
        m[j][i] = v1[i]*v2[j];
        }
    }
    return m;
}

int Matrice::ltaille() const {
    return dims[0];
}

int Matrice::ctaille() const {
    return dims[1];
}