//
// Created by Quentin Gyselinck on 02/06/2020.
//
#include <iostream>
# include <cmath>
#include "Vecteur.h"
#include "Matrice.h"
using namespace std;
int main(){
cout << "Question 1" << endl;
//Création de la matrice A
    float tab1 [] = {1,1,0};
    Vecteur u(tab1,3);
    float tab2 [] = {-0.5,2,-1};
    Vecteur z(tab2,3);
    float tab3 [] = {0,-1,1};
    Vecteur w(tab3,3);
    Vecteur *tabv1 = new Vecteur[3];

    tabv1[0]=u;
    tabv1[1]=z;
    tabv1[2]=w;

    Matrice a(tabv1, 3);

// Matrice B
    Matrice b(2,2);
    b[0][0] = -2;
    b[1][0] = 3;
    b[1][1] = 1;

    cout << "A = " << endl;
    a.affiche();
    cout << "B = " << endl;
    b.affiche();

//Question 2
    cout << "Question 2" << endl;
    Matrice c(b);
    b[1][0] = 0;
    cout << "B = " << endl;
    b.affiche();
    cout << "C = " << endl;
    c.affiche();

//Question 3
    cout << "Question 3" << endl;
    Matrice d = a.submat(1,3,1,2);
    cout << "D = " << endl;
    d.affiche();

//Question 4
    cout << "Question 4" << endl;
    Vecteur v(3);
    v[0] = 3;
    v[1] = 2;
    v[2] = 1;
    Matrice e(v);
    cout << "Vecteur v = ";
    v.affiche();
    cout << endl;
    cout << "Matrice E = " << endl;
    e.affiche();

//Question 5
    cout << "Question 5" << endl;
    cout << "B + C =" << endl;
    (b + c).affiche();
    cout << "C - B = " << endl;
    (c - b).affiche();
    cout << "D * C = " << endl;
    (d * c).affiche();

//Question 6
    cout << "Question 6" << endl;
    cout << "La norme de Frobenius de C = ";
    cout << norm(c) << endl << endl;

//Question 7
    cout << "Question 7" << endl;
    cout << "0.5 * (B + Bt) = " << endl;
    (0.5 * (b + b.transpose())).affiche();







};