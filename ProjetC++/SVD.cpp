//
// Created by Quentin Gyselinck on 05/06/2020.
//

#include "Matrice.h"
#include "Vecteur.h"
#include <iostream>
#include <cmath>

using namespace std;

void cppidcolgivens(float x, float z, float &c, float &s){
    if (z == 0){
        c = 1;
        s = 0;
    }
    else {
        if (abs(z) > abs(x)){
            float t = (-x)/z;
            s = 1/(sqrt(1 + t*t));
            c = s * t;
        }
        else {
            float t = (-z)/x;
            c = 1/(sqrt(1 + t*t));
            s = c * t;
        }
    }
}

Vecteur householder(Vecteur x, float& b){
    int n = x.taille();
    Vecteur a = x.subvec(2,n);
    float o = dot(a,a);
    Vecteur v(n);
    v[0] = 1;
    for (int i =1; i < v.taille(); i++){
        v[i] = a[i-1];
    }
    if (o==0 & x[0] >= 0){
         b = 0;
    }
    else {
        if (o == 0 & x[0] < 0){
            b = 2;
        }
        else {
            float u = sqrt(x[0]*x[0] + o);
            if (x[0] <= 0){
                v[0] = x[0] - u;
            }
            else {
                v[0] = (-o)/(x[0]+u);
            }
        }
    }
    b = (2*v[0]*v[0])/(o + v[0]*v[0]);
    v = (1/v[0])*v;
    return v;
}

int signe(float d) {
    if (d<0){
        return -1;
    }
    else {
        return 1;
    }
}

Matrice reductridiag(Matrice& m){
    int l = m.ctaille();
    float d = (m[l-2][l-2] - m[l-1][l-1])/2;
    float u = m[l-1][l-1] - (m[l-2][l-1]*m[l-2][l-1])/(d + signe(d)*sqrt(d*d + m[l-2][l-1]*m[l-2][l-1]));
    float x = m[0][0] - u;
    float z = m[0][1];
    float c = 0;
    float s = 0;
    float t1;
    float t2;
    Vecteur s(l);
    for (int i=0; i<l;i++){
        s[i]=1;
    }
    Matrice Z(s);
    for (int k=0; k<l-1;k++){
        cppidcolgivens(x , z , c , s);
        for (int j=0; j < l; j++){
            t1 = m[k][j];
            t2 = m[k+1][j];
            m[k][j] = c*t1 - s*t2;
            m[K+1][j] = s*t1 + c*t2;
            t1 = Z[k][j];
            t2 = Z[k+1][j];
            Z[k][j] = c*t1 - s*t2;
            Z[k+1][j] = s*t1 + c*t2;
        }
        for (int j=0; j < l; j++){
            t1 = m[k][j];
            t2 = m[k+1][j];
            
        }

    }


}

int main(){

    float x = 1;
    float z = 2;
    float c = 3;
    float s = 4;
    cppidcolgivens(x , z , c , s);
    cout << x << endl << z << endl << c << endl << s << endl;
    cout << endl;
    Vecteur u(2);
    u[0] = 1/sqrt(2);
    u[1] = 1/sqrt(2);
    u.affiche();

    float i;
    Vecteur h = householder(u,i);
    h.affiche();
    cout << i << endl;
    cout << signe(-6.4);



}