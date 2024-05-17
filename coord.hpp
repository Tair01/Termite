#ifndef COORD_HPP
#define COORD_HPP
#include<iostream>
#include<stdexcept>
#include<vector>

using namespace std;

//une constante tailleGrille
const int tailleGrille = 21;

//La classe Coord
class Coord{
public: 
    //le constructeur Coord(int x, int y); qui construit la coordonnée (x, y)
    Coord(int lig, int col);
    
    //le getter Coord::getLig(), renvoie ligne
    int getLig()const;
    
    //le getter Coord::getCol(), renvoie colonne
    int getCol()const;
    
    // Surcharge de l'operator << pour les coordonnées 
    ostream &operator<<(ostream &out);
    
    //conversion de type "bool"
    explicit operator bool() const;
        
    //les opérateurs d'égalité et d'inégalité pour le type Coord
    bool operator==(Coord &a)const;
    
    
private:
    int l;
    int c;
};

//type enuméré Direction
enum class Direction{nord_ouest, nord, nord_est, est, sud_est, sud, sud_ouest, ouest};

//// Surcharge de l'operator << pour enum class Direction
ostream &operator<<(ostream &out, Direction d);

//renvoie la direction située juste à sa gauche
Direction aGauche(Direction d);

////renvoie la direction située juste à sa droite
Direction aDroite(Direction d);

//retourne la coordonnée devant une coordonnée donnée dans une direction donnée
Coord devantCoord(const Coord &c, Direction d);

#endif