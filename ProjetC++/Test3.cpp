//
// Created by Quentin Gyselinck on 04/06/2020.
//
#include "Matrice.h"
#include "Vecteur.h"
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float tab1 [] = {1,1,0};
    Vecteur u(tab1,3);
    Vecteur v = u.subvec(3,3);
    v.affiche();
    Vecteur s(4);





}