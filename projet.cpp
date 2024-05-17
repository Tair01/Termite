#include "coord.hpp"
#include "grille.hpp"
#include "termite.hpp"

using namespace std;

const float densiteBrindille=0.05;
const int nbTermites=20;


vector<Termite> term;

void deplaceBrindille(Grille &g){
    for(int i = 0; i <tailleGrille; i++){
        for(int j = 0; j < tailleGrille; j++){
            float rand_num = static_cast<float>(rand()) / RAND_MAX;
            if(rand_num < densiteBrindille){
                g.grille[i][j].brindille = true;
            }
        }
    }
}

void deplaceTermite(Grille &g){
    int a = 0;
    while(a <= nbTermites){
        for(int i = 0; i < tailleGrille; i++){
            Coord c = {i, i};
            if(g.estVide(c)){
                int h = rand() % 8;
                g.poseTermite(c, a);
                Termite t(a, c.getLig(), c.getCol(), Direction(h), false);
                term.push_back(t);
                a++;
            }
        }
        a++;
    }
    
}
/**
void passe(Grille &g) {
    deplaceTermite(g);
    cout << g;
    char c = getchar();
    while (c != '.') {
        deplaceTermite(g);
        cout << g;
        c = getchar();
    }
}
**/
ostream &operator << (ostream &out,  Grille &a) {
    out << " ";
    for(int a = 0; a < tailleGrille; a++){
        out << "-";
    }
    out << endl;
    for(int i = 0; i < tailleGrille; i++) { 
        out << "|";
        for (int j = 0; j < tailleGrille; j++) {
            Coord c = {i, j};
            if (a.estVide(c)) out << " ";
            if (a.contientBrindille(c)) out << "*";
            if (a.numeroTermite(c) != -1){
                int n = a.numeroTermite(c);
                if(term[n].directionTermite() == Direction(0) or term[n].directionTermite() == Direction(4)){
                    out << "\\" ;
                }
                if(term[n].directionTermite() == Direction(1) or term[n].directionTermite() == Direction(5)){
                    out << "|";
                }
                if(term[n].directionTermite() == Direction(2) or term[n].directionTermite() == Direction(6)){
                    out << "/";
                }
                if(term[n].directionTermite() == Direction(3) or term[n].directionTermite() == Direction(7)){
                    out << "-";
                }
            }
        } 
        out << "|" <<  endl;
    }
    out << " ";
    for(int b = 0; b< tailleGrille; b++){
        out << "-";
    }
    out <<endl;
    return out;
}

int main(){
    Grille g(tailleGrille, tailleGrille);
    deplaceTermite(g);
    cout << g;
    char c = getchar();
    while (c != '.') {
        for(int i = 0; i < nbTermites; i++){
            term[i].vieTermite(g);
        }
        cout << g;
        c = getchar();
    }
}