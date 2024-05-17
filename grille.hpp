#ifndef GRILLE_HPP
#define GRILLE_HPP
#include<iostream>
#include<stdexcept>
#include<vector>
#include <ctime>
#include "coord.hpp"

using namespace std;

//la structure Case
struct Case {
    bool brindille;
    int termite;
    
    Case(bool brindille, int termite);

    
};

class Grille{
public:
    int largeur, hauteur;
    
    //un constructeur par défaut qui fabrique une case vide
    Grille();
    
    //Constructeur pour l'initialisation
    Grille(int l, int h);
    
    void poseBrindille(Coord c);
    
    void enleveBrindille(Coord c);
    
    bool contientBrindille(Coord c) const;
    
    void poseTermite(Coord c, int idT);
    
    void enleveTermite(Coord c);
    
    int numeroTermite(Coord c) const;
    
    bool estVide(Coord c) const;
    
    Case grille[tailleGrille][tailleGrille];
    
};


#endif