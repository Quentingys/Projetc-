//
// Created by Quentin Gyselinck on 29/05/2020.
//
#include <iostream>
#include <cmath>
#include "Vecteur.h"

using namespace std;

void Vecteur::affiche() const {
    cout << "(";
    for (int i = 0; i < dim; i++){
        cout << tab[i] << ";";
    }
    cout << ")" << endl;
    cout << "Dimension : " << dim << endl;
 // il serait bien d'afficher le nom des variable ici, pe faudra t il rajouter un attribu name...

}
//Constructeur par défaut
Vecteur::Vecteur() {
    dim = 0;

}

//Constructeur par taille : vecteur avec des 0
Vecteur::Vecteur(int taille){
    if (taille <= 0) {
        cout << "Taille négative";
    }
    else {
        dim = taille;
        tab = new float [dim]; // créer le tableau de taille dim
        for (int i = 0; i < dim ; i++) //Rempli le vecteur avec des 0
        {
            tab[i] = 0;
        }

    }
}

Vecteur::Vecteur(float *t, int taille){
    dim = taille;
    if (dim>0){
        tab = new float [dim];
        for (int i = 0; i < dim; i++){
            tab[i] = t[i];
        }
    }
}

Vecteur::~Vecteur()
{
    delete [] tab;

}



Vecteur::Vecteur(const Vecteur& v){
    dim = v.dim;
    if (dim > 0) {
        tab = new float [dim];
        for (int i =0; i < dim; i++)
        {
            tab[i] = v.tab[i]; // v.tab[i] ? marche normalement une fois qu'on aura surdef l'op []
        }
    }

}

//Opérateur pr aller chercher la i-eme composante d'un vecteur
float& Vecteur::operator[](int i)const {
    if (i<0 || i >= dim ){
        cout << " La recherche ne correspond pas au vecteur, indice :" << i << endl;
        return tab[0]; // Sinon warning car pas de retour si la condition n'est pas vérifiée

 // encore pr empêcher warning, mais attention si on se trompe on nous retourne un 0 pb ici trouver qqch a return pr plus warning
    }
    else {
        return tab[i];
    }
}

//opérateur d'affectation par = surdéfinition opérateur d'affectation
Vecteur& Vecteur::operator=(const Vecteur& v){
    if (this != &v){
        dim = v.dim;
        tab = new float [dim];
        for (int i = 0; i<dim;i++){
            tab[i] = v.tab[i];
        }
    }
    return *this;
}

//surdéfinition des opérateur + et -
// this permet d'utilisé le vecteur sur lequel on fait l'opération, évite de définir l'op en dehors de la classe
//et de devoir ajouter des méthodes pour pouvoir récupérer dim et tab définis en privé

Vecteur Vecteur::operator+(const Vecteur& v1) {
    if (this->dim != v1.dim) {
        cout << "Les vecteurs n'ont pas la meme dimension" << endl;
        Vecteur v(1);
        return v;
    } else {
        Vecteur v(v1.dim);
        for (int i = 0; i < v1.dim; i++) {
            v[i]= tab[i] + v1[i];
        }
        return v;
    }

}

Vecteur Vecteur::operator-(const Vecteur& v1) {
    if (this->dim != v1.dim) {
        cout << "Les vecteurs n'ont pas la meme dimension" << endl;
        Vecteur v(1);
        return v;           //Pr enlever les warning du retour de rien si on a pas le if vérifié si on peut pas faire l'op
    } else {                   // retourne un vecteur avec 1 0 : pas oufouf
        Vecteur v(v1.dim);
        for (int i = 0; i < v1.dim; i++) {
            v[i]= tab[i] - v1[i];
        }
        return v;
    }

}
//def de subvec
Vecteur Vecteur::subvec(int i, int j){
    int taille = this->dim;
    if (i>j || j>taille){
        cout << "On ne peut pas définir de sousvecteur avec ces paramètres";
        Vecteur v(1);
        return v;
    }
    else{
        int taille1 = j-i + 1;
        Vecteur v(taille1);
        for (int k = i -1; k < j; k++){
            v[k-i+1] = tab[k];
        }
        return v;
    }
}

//fonction qui récup la taille d'un vect
int Vecteur::taille() const{
    int t = this->dim;
    return t;

}

float dot(const Vecteur& v1, const Vecteur& v2){
    if (v1.taille() != v2.taille()){
        cout << "Les vecteurs n'ont pas la meme taille, le produit scalaire est impossible";
        return 0;
        //encore un pb de non retour, comment faire avec les float ?...
    }
    else {
        float ps =0;
        for (int i = 0; i < v1.taille(); i++){
            ps += v1[i] * v2[i];

        }
        return ps;
    }
}

float norm(const Vecteur& v){
    float a = sqrt(dot(v,v));
    return a;
}

Vecteur operator* (float a, const Vecteur& v){
    int lg = v.taille();
    Vecteur v1(lg);
    for (int i = 0; i < lg; i++){
        v1[i] = a * v[i];
    }
    return v1;
}

