#include <iostream>
# include <cmath>
#include "Vecteur.h"
using namespace std;

int main() {
    cout << "Question 1 : " << endl;
    float tab1 [] = {1,1,1};
    float tab2 [] = {3,4,0,0};
    Vecteur u(tab1,3);
    Vecteur v(tab2, 4);
    cout << "u = ";//pb c pas good
    u.affiche();
    cout << "v = ";
    v.affiche();// serait bien d'afficher le nom des vecteur dans fonction affiche mais jnsp comment recup
    cout << endl;
    cout << "Question 2 : " << endl;
    Vecteur t(u);
    cout << "Question 3 : " << endl;
    u[2] = 0;
    cout << "u = ";
    u.affiche();
    cout << "t =";
    t.affiche();
    cout << endl;
    cout << "Question 4 : " << endl;
    float a = dot(v,v);
    float b = norm(v);
    cout << "Question 5 : " << endl;
    Vecteur z = (1/b) * v;
    cout << "z = ";
    z.affiche();
    cout << endl;
    cout << "Question 6 : " << endl;
    Vecteur w = v.subvec(1,3);
    cout << "v = ";
    v.affiche();
    cout << "w = ";
    w.affiche();
    cout << endl;
    cout << "Question 7 : " << endl;
    Vecteur z1 = u + w;
    cout << "u + w = ";
    z1.affiche();
    Vecteur z2 = u - w;
    cout << "u - w = ";
    z2.affiche();



}
