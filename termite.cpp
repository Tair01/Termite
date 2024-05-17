#include "termite.hpp"
#include <string>
#include <sstream>


Termite::Termite(int idT, int l, int c, Direction d, bool brind): id(idT), lig(l), col(c), dir(d), brind(false){}

string Termite:: toString() const{
        stringstream ss;
        ss << "Termite id:" << " " << id << endl;
        ss << "Ligne(x): " << " " << lig << endl;
        ss << "Colonne(y): " << " " << col << endl;
        ss << "Direction:" << " "<< dir << endl;
        ss << "Brind:" << " " << brind << endl;
        return ss.str();
}

Direction Termite:: directionTermite()const{
    return dir;
}

Coord Termite:: devant()const{
    Coord c = {lig, col};
    return devantCoord(c, dir);    
}

bool Termite::porteBrindille(const Grille &g)const{
    Coord c = {lig, col};
    return g.contientBrindille(c);
}

void Termite::tourneADroite(){
    dir = aDroite(dir);
}

void Termite::tourneAGauche(){
    dir = aGauche(dir);
}

void Termite::tourneAleat(){
    dir = Direction(rand() % 8);
}

bool Termite::laVoieEstLibre(const Grille &g)const{
    Coord c = {lig, col};
    c = devantCoord(c, dir);
    if(c.getLig() < 0 or c.getLig() >= tailleGrille or c.getCol() < 0 or c.getCol() >= tailleGrille){
        throw invalid_argument("Les coordonnÃ©es ne sont pas dans la grille");
    }
    return g.estVide(c);
}

bool Termite::brindilleEnFace(const Grille &g)const{
    Coord c = {lig, col};
    c = devantCoord(c, dir);
    if(c.getLig() < 0 or c.getLig() >= tailleGrille or c.getCol() < 0 or c.getCol() >= tailleGrille){
        throw invalid_argument("Les coordonnÃ©es ne sont pas dans la grille");
    }
    return g.contientBrindille(c);
}

int Termite::voisinsLibre(const Grille &g) const{
    int count = 0;
    Coord c = {lig, col};
    for(int i = 0; i <= 7; i++){
        Coord n = devantCoord(c, Direction(i));
        if(g.estVide(n)) count++;
    }
    return count;
}

void Termite::avance(Grille &g) {
    Coord c = { lig, col };
    c = devantCoord(c, dir);
    if (c.getLig() < 0 or c.getLig() >= tailleGrille or c.getCol() < 0 or c.getCol() >= tailleGrille) throw invalid_argument("Les coordonnÃ©es ne sont pas dans la grille");
    lig = c.getLig();
    col = c.getCol();
    g.grille[lig][col].termite = id;
}

void Termite::marcheAleatoire(Grille &g) {
  Coord c = {lig, col};
  do { tourneAleat(); 
  c = devantCoord(c, dir); }
  while (c.getLig() < 0 or c.getLig() >= tailleGrille or c.getCol() < 0 or c.getCol() >= tailleGrille);
  lig = c.getLig();
  col = c.getCol();
  g.grille[lig][col].termite = id;
}

void Termite::chargeBrindille(Grille &g) {
    Coord c = {lig, col};
    if (g.contientBrindille(c)){
        g.enleveBrindille(c);
        brind = true;
  }
}

void Termite::dechargeBrindille(Grille &g) {
  Coord c = {lig, col};
  if(!g.contientBrindille(c)){
      g.poseBrindille(c);
      brind = false;
  }
}
void Termite:: vieTermite(Grille &g){
        if(laVoieEstLibre(g)){
            float rand_num = static_cast<float>(rand()) / RAND_MAX;
            if(rand_num < probaTourner){
                tourneAleat();
            }
        }    
        else{
            avance(g);
        }
        Coord c = {lig, col};
        if(g.contientBrindille(c)){
            chargeBrindille(g);
            for(int i = 0; i < dureeSablier; i++){
                marcheAleatoire(g);
            }
            c = {lig, col};
            if(g.estVide(c)){
                dechargeBrindille(g);
            }
        }if(!brind){
            for(int i = 0; i < 20; i++){
                marcheAleatoire(g);
                if(i >= dureeSablier){
                    if(brindilleEnFace(g)){
                        avance(g);
                        chargeBrindille(g);
                        break;
                    }
                }
            }
                        int s = voisinsLibre(g);
                        if(s != 0 and s!= 1){
                            c = {lig, col};
                            while(!laVoieEstLibre(g)){
                                tourneAleat();
                            }
                            avance(g);
                            dechargeBrindille(g);
                        }
                        else{
                            while(s != 2){
                                tourneAleat();
                                if(laVoieEstLibre(g)){
                                    avance(g);
                                    dechargeBrindille(g);
                                }
                            }
                        }
        }
}
                 