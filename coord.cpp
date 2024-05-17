#include "coord.hpp"


Coord:: Coord(int lig, int col): l(lig), c(col){
    if(lig < 0 or lig >= tailleGrille or col < 0 or col >= tailleGrille){
        throw invalid_argument("Les coordonnées ne sont pas dans la grille");
    }
}

Coord::operator bool() const {
    return (l != 0 or c != 0);
}
    
int Coord:: getLig()const{
    return l;
}
    
int Coord:: getCol()const{
    return c;
}
// Surcharge de l'operator << pour les coordonnées    
ostream &operator<<(ostream &out, const Coord &a){
    out << "Ligne:" << " " << a.getLig() << endl;
    out << "Colonne:" << " " << a.getCol() << endl;
    return out;
}
    
bool Coord:: operator==(Coord &a)const{
    return l == a.l and c == a.c;
}


//Surcharge de l'operator << pour enum class Direction
ostream& operator<<(ostream& out, Direction d){
    switch(d){
        case Direction::nord_ouest: out << "Nord-Ouest" << endl; break;
        case Direction::nord: out << "Nord" << endl; break;
        case Direction::nord_est: out << "Nord-Est" << endl; break;
        case Direction::est: out << "Est" << endl; break;
        case Direction::sud_est: out << "Sud-Est" << endl; break;
        case Direction::sud: out << "Sud" << endl; break;
        case Direction::sud_ouest: out << "Sud-Ouest" << endl; break;
        case Direction::ouest: out << "Ouest" << endl; break;
        default: out << "Direction invalid";   
    }
    return out;
}

Direction aGauche(Direction d){
    switch(d){
        case Direction::nord_ouest: return Direction::ouest; break;
        case Direction::nord: return Direction::nord_ouest; break;
        case Direction::nord_est: return Direction::nord; break;
        case Direction::est: return Direction::nord_est; break;
        case Direction::sud_est: return Direction::est; break;
        case Direction::sud: return Direction::sud_est; break;
        case Direction::sud_ouest: return Direction::sud; break;
        case Direction::ouest: return Direction::sud_ouest; break;
        default: throw invalid_argument("Invalid direction");
    }
}

Direction aDroite(Direction d){
    switch(d){
        case Direction::nord_ouest: return Direction::nord; break;
        case Direction::nord: return Direction::nord_est; break;
        case Direction::nord_est: return Direction::est; break;
        case Direction::est: return Direction::sud_est; break;
        case Direction::sud_est: return Direction::sud; break;
        case Direction::sud: return Direction::sud_ouest; break;
        case Direction::sud_ouest: return Direction::ouest; break;
        case Direction::ouest: return Direction::nord_ouest; break;
        default: throw invalid_argument("Invalid direction");
    }
}

Coord devantCoord(const Coord &c, Direction d){
    int ligne = c.getLig();
    int colonne = c.getCol();
    
    switch(d){
        case Direction::nord_ouest: ligne++; colonne--; break;
        case Direction::nord: ligne++; break;
        case Direction::nord_est: ligne++; colonne++; break;
        case Direction::est: colonne++; break;
        case Direction::sud_est: ligne--; colonne++; break;
        case Direction::sud: ligne--; break;
        case Direction::sud_ouest: ligne--; colonne--; break;
        case Direction::ouest:colonne--; break;
        default: throw invalid_argument("Direction invalid"); 
    }
    
    if(ligne < 0 or ligne >= tailleGrille or colonne < 0 or colonne >= tailleGrille){
        throw invalid_argument("Les coordonnées ne sont pas dans la grille");
    }
    
    return Coord(ligne, colonne);
}

