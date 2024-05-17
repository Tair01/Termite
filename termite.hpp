#ifndef TERMITE_HPP
#define TERMITE_HPP
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include "coord.hpp"
#include "grille.hpp"

using namespace std;


const float probaTourner = 0.1; // 10%
const int dureeSablier = 6;

class Termite{
public:
    Termite(int idT, int l, int c, Direction d, bool brind);
    
    Termite() {}
    
    //convertit l'animal en chaîne de caractères pour l'affichage
    string toString() const;
    
    //renvoie la direction du Termite
    Direction directionTermite() const;
    
    //renvoie les coordonnées de la case devant le termite
    Coord devant()const;
    
    //renvoie si le termite porte une brindille
    bool porteBrindille(const Grille &g)const;
    
    //fait tourner le termite à droite
    void tourneADroite();
    
    //fait tourner le termite à gauche
    void tourneAGauche();
    
    //fait tourner le termite dans un sens aléatoire
    void tourneAleat();
    
    //renvoie si la case devant le termite est libre
    bool laVoieEstLibre(const Grille &g)const;
    
    //renvoie si la case devant le termite contient une brindille
    bool brindilleEnFace(const Grille &g)const;
    
    //renvoie le nombre de cases libre autour du termite
    int voisinsLibre(const Grille &g)const;
    
    //avance le termite
    void avance(Grille &g);
    
    //déplace aléatoirement le termite
    void marcheAleatoire(Grille &g);
    
    //le termite prend une brindille
    void chargeBrindille(Grille &g);
    
    //le termite pose une brindille
    void dechargeBrindille(Grille &g);
    
    ////algorithme du termite
    void vieTermite(Grille &g);

    
private:
    int id;
    int lig;
    int col;
    Direction dir;
    bool brind;
};




#endif