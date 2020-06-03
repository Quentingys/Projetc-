//
// Created by Quentin Gyselinck on 29/05/2020.
//

#ifndef UNTITLED9_VECTEUR_H
#define UNTITLED9_VECTEUR_H


class Vecteur {
    // méthodes
    public:

    //Fonction affiche
    void affiche() const; //pas d'arg ni valeur de retour : affiche valeurs de tab

    //Constructeurs
    Vecteur(int taille); // premier constructeur (créer un tableau de float initialisés à 0)
    Vecteur(float * t, int taille); //2e constructeur : créer un vecteur de dim taille avec un tableau de float en argument
    Vecteur(const Vecteur& v); //constructeur de recopie on donne le nom des var dans .h, pas oufouf?

    //Destructeur
    ~Vecteur(); // Destructeur

    //Opérateurs
    Vecteur& operator=(const Vecteur&); // Opérateur d'affectation
    float& operator[](int) const; //pr aller chercher l'élément i du vecteur
    Vecteur operator+(const Vecteur &);
    Vecteur operator-(const Vecteur &);

    //fonction subvec
    Vecteur subvec(int i, int j);

    //fonction qui récupère la taille d'un vecteur
    int taille() const ;


    // Attribus
    private:
    float *tab;
    int dim;



};
float dot(const Vecteur &, const Vecteur &);
float norm(const Vecteur &);
Vecteur operator*(float , const Vecteur &);


#endif //UNTITLED9_VECTEUR_H
