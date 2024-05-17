#include "grille.hpp"
#include <vector>


Case::Case(bool brindille = false, int termite = -1):
    brindille(brindille), termite(termite){}


Grille::Grille(){
        for(int i = 0; i < tailleGrille; i++){
            for(int j = 0; j < tailleGrille; j++){
                grille[i][j] = Case{false, -1};
            }
        }
}

Grille::Grille(int l, int h) : largeur(l), hauteur(h) {}

void Grille::poseBrindille(Coord c){
    if(c.getLig() < 0 or c.getLig() >= tailleGrille or c.getCol() < 0 or c.getCol() >= tailleGrille){
        throw invalid_argument("Erreur en posebrind");
    }
    if(contientBrindille(c)){
        throw invalid_argument("Il y a d'éjà une brindille  ");
    }
    grille[c.getLig()][c.getCol()] = {true, -1}; 
}

void Grille::enleveBrindille(Coord c){
    if(c.getLig() < 0 or c.getLig() >= tailleGrille or c.getCol() < 0 or c.getCol() >= tailleGrille){
        throw invalid_argument("erreur en enlevebrind");
    }
    if (grille[c.getLig()][c.getCol()].brindille == false) {
        throw invalid_argument("Pas de brindille");
    }
    grille[c.getLig()][c.getCol()] = {false, -1};
}

bool Grille::contientBrindille(Coord c) const{
    if(c.getLig() < 0 or c.getLig() >= tailleGrille or c.getCol() < 0 or c.getCol() >= tailleGrille){
        throw invalid_argument("contientbrind");
    }
    return grille[c.getLig()][c.getCol()].brindille == true;
}

void Grille::poseTermite(Coord c, int idT){
    if(c.getLig() < 0 or c.getLig() >= tailleGrille or c.getCol() < 0 or c.getCol() >= tailleGrille){
        throw invalid_argument("poseTermite");
    }
    if(grille[c.getLig()][c.getCol()].termite != -1){
        throw invalid_argument("Il y d'éjà un termite");
    }
    grille[c.getLig()][c.getCol()].termite = idT;
}
void Grille::enleveTermite(Coord c){
    if(c.getLig() < 0 or c.getLig() >= tailleGrille or c.getCol() < 0 or c.getCol() >= tailleGrille){
        throw invalid_argument("enleveTermite");
    }
    if (grille[c.getLig()][c.getCol()].termite == -1) {
        throw invalid_argument("Pas de termite");
    }
    grille[c.getLig()][c.getCol()].termite = -1;
}
    
int Grille::numeroTermite(Coord c) const{
    if(c.getLig() < 0 or c.getLig() >= tailleGrille or c.getCol() < 0 or c.getCol() >= tailleGrille){
        throw invalid_argument("numeroTermite");
    }
    return grille[c.getLig()][c.getCol()].termite;
    }
    
bool Grille::estVide(Coord c) const{
    if(c.getLig() < 0 or c.getLig() >= tailleGrille or c.getCol() < 0 or c.getCol() >= tailleGrille){
        throw invalid_argument("estVide");
    }
    return grille[c.getLig()][c.getCol()].termite == -1 and grille[c.getLig()][c.getCol()].brindille == false; 
}
