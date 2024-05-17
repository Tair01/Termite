#include <iostream>
#include <stdexcept>
#include <vector>
#include "coord.hpp"
#include "grille.hpp"
#include "termite.hpp"
using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

TEST_CASE("Le constructeur de la classe Coord "){
    CHECK_FALSE(Coord(0, 0));
    CHECK(Coord(3, 1));
    CHECK(Coord(4, 2));
    CHECK(Coord(8, 7));
    CHECK(Coord(7, 0));
    CHECK(Coord(4, 4));
}
/**
TEST_CASE("Le constructeur de la classe Coord avec des exception"){
    CHECK_THROWS_AS(Coord(-1, -1), invalid_argument);
    CHECK_THROWS_AS(Coord(-1,  0),  invalid_argument);
    CHECK_THROWS_AS(Coord(0,  -1),  invalid_argument);
    CHECK_THROWS_AS(Coord(10, 10), invalid_argument);
    CHECK_THROWS_AS(Coord(10,  0),  invalid_argument);
    CHECK_THROWS_AS(Coord(0,  10),  invalid_argument);
    CHECK_THROWS_AS(Coord(11,  4),  invalid_argument);
    CHECK_THROWS_AS(Coord(4,  11),  invalid_argument);
}
**/
TEST_CASE("Getter getLig et getCol"){
    
    Coord a1(4, 3);
    Coord a2(5, 1);
    Coord a3(8, 9);
    Coord a4(0, 0);
    
    CHECK(a1.getLig() == 4);
    CHECK(a1.getCol() == 3);
    CHECK(a2.getLig() == 5);
    CHECK(a2.getCol() == 1);
    CHECK(a3.getLig() == 8);
    CHECK(a3.getCol() == 9);
    CHECK(a4.getLig() == 0);
    CHECK(a4.getCol() == 0);
    CHECK_FALSE(a1.getLig() == 8);
    CHECK_FALSE(a1.getCol() == 9);
    
}


TEST_CASE("L'opérateur d'égalité =="){

    Coord c1(4, 1);
    Coord c2(4, 1);
    Coord c3(6, 3);
    Coord c4(6, 3);
    
    CHECK(c1 == c2);
    CHECK_FALSE(c1 == c3);
    CHECK(c3 == c4);
    CHECK_FALSE(c4 == c2);

}

TEST_CASE("Le fonction aGauche"){
    CHECK(aGauche(Direction::nord_ouest) == Direction:: ouest);
    CHECK(aGauche(Direction::nord) == Direction:: nord_ouest);
    CHECK(aGauche(Direction::nord_est) == Direction:: nord);
    CHECK(aGauche(Direction::est) == Direction:: nord_est);
    CHECK(aGauche(Direction::sud_est) == Direction:: est);
    CHECK(aGauche(Direction::sud) == Direction:: sud_est);
    CHECK(aGauche(Direction::sud_ouest) == Direction:: sud);
    CHECK(aGauche(Direction::ouest) == Direction:: sud_ouest);

}
    
TEST_CASE("Le fonction aDroite"){
    CHECK(aDroite(Direction::nord_ouest) == Direction:: nord);
    CHECK(aDroite(Direction::nord) == Direction:: nord_est);
    CHECK(aDroite(Direction::nord_est) == Direction:: est);
    CHECK(aDroite(Direction::est) == Direction:: sud_est);
    CHECK(aDroite(Direction::sud_est) == Direction:: sud);
    CHECK(aDroite(Direction::sud) == Direction:: sud_ouest);
    CHECK(aDroite(Direction::sud_ouest) == Direction:: ouest);
    CHECK(aDroite(Direction::ouest) == Direction:: nord_ouest);

}

TEST_CASE("Les fonctions aGauche et aDroite"){
    Direction d = Direction:: nord;
    Direction test_d = d;
    
    //on tourne à gauche puis à droite
    for(int i = 0; i < 2; i++){
        d = aGauche(d);
        d = aDroite(d);
    }
    CHECK(d == test_d);
    
    //on tourne à droite puis à droite
    for(int i = 0; i< 2; i++){
        d = aDroite(d);
        d = aGauche(d);
    }
    CHECK(d == test_d);
    
    //on tourne 8 fois à gauche
    for(int i = 0; i < 8; i++){
        d = aGauche(d);
    }
    CHECK(d == test_d);
    
    //on tourne 8 fois à droite
    for(int i = 0; i < 8; i++){
        d = aDroite(d);
    }
    CHECK(d == test_d);
}


TEST_CASE("La fonction devantCoord"){
    Coord k(3, 2);
    Direction d = Direction::nord_ouest;
    Coord r = devantCoord(k, d);
    CHECK(r.getLig() == 4);
    CHECK(r.getCol() == 1);
    
    Coord c(4, 5); 
    Direction b = Direction::nord_est;
    Coord e = devantCoord(c, b);
    CHECK(e.getLig() == 5); 
    CHECK(e.getCol() == 6);
    /**
    CHECK_THROWS_AS(Coord(13, 11), invalid_argument);
    CHECK_THROWS_AS(Coord(11, 10),invalid_argument);
    **/
}


TEST_CASE("La fonction devantCoord "){
    Coord c(6, 6);
    Direction d = Direction::nord_ouest;
    Coord nv_coord = devantCoord(c, d);
    
    for(int i = 0; i < 4; i++){
        d = aDroite(d);
    }
    
    nv_coord = devantCoord(nv_coord, d);
    
    CHECK(nv_coord == c);

    Coord b(3, 3);
    Direction dir = Direction::nord;
    Coord nv2_coord = devantCoord(b, dir);
    
    for(int i = 0; i < 4; i++){                   //Il ya un truc qui marche pas
        dir = aDroite(dir);
    }
    
    nv2_coord = devantCoord(nv2_coord, dir);
    
    CHECK(nv2_coord == b);

}

TEST_CASE("Le constructeur Case"){
    Case c1(false, -1);
    CHECK(c1.brindille == false);
    CHECK(c1.termite == -1);
    
    Case c2(true, -1);
    CHECK(c2.brindille == true);
    CHECK(c2.termite == -1);
    
    Case c3(false, 1);
    CHECK(c3.brindille == false);
    CHECK(c3.termite == 1);
}

TEST_CASE("Le constructeur Grille"){
    Grille g;
    for(int i = 0; i < tailleGrille; i++){
        for(int j = 0; j < tailleGrille; j++){
            CHECK(g.grille[i][j].brindille == false);
            CHECK(g.grille[i][j].termite == -1);
        }
    }

}
TEST_CASE("Les méthodes poseBrindille, enleveBrindille et contientBrindille "){
    Grille g(10, 10);
    Coord c1(6, 6);
    Coord c2(7,8);
    
    g.poseBrindille(c1);
    g.poseBrindille(c2);
    
    CHECK(g.contientBrindille(c1) == true);
    CHECK(g.contientBrindille(c2) == true);
    
    //On pose encore une brindille pour avoir une exception
    CHECK_THROWS_AS(g.poseBrindille(c1), invalid_argument);
    CHECK(g.contientBrindille(c1) == true);
    
    //On enleve une brindille
    g.enleveBrindille(c1);
    CHECK(g.contientBrindille(c1) == false);
    
    g.enleveBrindille(c2);
    CHECK(g.contientBrindille(c2) == false);
    
    //On essaye d'enlever une brindille pour avoir une exception
    CHECK_THROWS_AS(g.enleveBrindille(c1), invalid_argument);
}


TEST_CASE("Les méthodes poseTermite, enleveTermite, numeroTermite et estVide"){
    Grille g(10, 10);
    Coord c1(1, 3);
    Coord c2(4, 5);
    Coord c3(7, 7);
    
    //poseTermite
    g.poseTermite(c1, 1);
    g.poseTermite(c2, 3);
    
    //numeroTermite
    CHECK(g.numeroTermite(c1) == 1);
    CHECK(g.numeroTermite(c2) == 3);
    
    
    //On essaye de  poser encore un termite pour avoir une exception
    CHECK_THROWS_AS(g.poseTermite(c1, 2), invalid_argument);
    CHECK_THROWS_AS(g.poseTermite(c2, 4), invalid_argument);
    
    //enleveTermite
    g.enleveTermite(c1);
    g.enleveTermite(c2);
    
    //estVide j'ai l'à pas tester

    CHECK(g.estVide(c1));
    CHECK(g.estVide(c2));
    CHECK(g.estVide(c3));
    
    //On essaye d'enlever un termite mais le grille estVide
    CHECK_THROWS_AS(g.enleveTermite(c1), invalid_argument);
    CHECK_THROWS_AS(g.enleveTermite(c2), invalid_argument);
    CHECK_THROWS_AS(g.enleveTermite(c3), invalid_argument);
    
    Grille a(5, 5);
    Coord b = {2, 2};

    a.poseBrindille(b);
    a.enleveBrindille(b);
    
    CHECK(a.estVide(b));
    
}
/**
TEST_CASE("toString convertit l'animal en chaîne de caractères"){
    Termite t(1, 2, 3, Direction::nord, false);
    string a = "Termite id: 1\nLigne(x): 2\nColonne(y): 3\nDirection: nord\nBrind: 0\n";;
    CHECK(t.toString() == a);
}
**/
TEST_CASE("La méthode directionTermite "){
    Termite t(0, 0, 0, Direction::nord, false);
    CHECK(t.directionTermite() == Direction::nord);
    
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction:: nord_est);
    
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction:: est);
    
    t.tourneAGauche();
    CHECK(t.directionTermite() == Direction:: nord_est); 
}


TEST_CASE("La méthode devant"){
    Termite t(1, 2, 3, Direction:: nord, false);
    Coord c = t.devant();
    CHECK(c.getLig() == 3);
    CHECK(c.getCol() == 3);
    
    Termite d(1, 2, 3, Direction:: est, false);
    Coord c1 = d.devant();
    CHECK(c1.getLig() == 2);
    CHECK(c1.getCol() == 4);
    
    Termite b(1, 2, 3, Direction::ouest, false);
    Coord c2 = b.devant();
    CHECK(c2.getLig() == 2);
    CHECK(c2.getCol() == 2);
    
}

TEST_CASE("La méthode porteBrindille"){
    Grille g(3, 3);
    Coord c = {1, 1};
    g.poseBrindille(c);
    Termite t(1, 1, 1, Direction::nord, true);
    CHECK(t.porteBrindille(g) == true);
    
    Grille a(4, 4);
    Termite d(1, 1, 1, Direction::nord, false);
    CHECK(d.porteBrindille(a) == false);
}

TEST_CASE("Les méthodes tourneADroite, tourneAGauche "){
    //tourneADRoite
    Termite t(1, 7, 6, Direction::nord, false);
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction::nord_est);
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction:: est);
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction::sud_est);

    //tourneAGauche
    Termite d(1, 5, 5, Direction::nord, false);
    d.tourneAGauche();
    CHECK(d.directionTermite() == Direction::nord_ouest);
    d.tourneAGauche();
    CHECK(d.directionTermite() == Direction::ouest);
    d.tourneAGauche();
    CHECK(d.directionTermite() == Direction::sud_ouest);
}
/*
TEST_CASE("La méthode tourneAleat"){
    Termite t(1, 2, 3, Direction:: nord, false);
    for(int i = 0;  i < 100; i++){
        Direction depart = t.directionTermite();
        t.tourneAleat();
        Direction f = t.directionTermite();
        CHECK(depart != f);
    }
}
*/
TEST_CASE("laVoieEstLibre renvoie vrai si la case devant est libre"){
    Grille g(5, 5);
    Coord c = {3, 3};
    Termite t(1, 2, 3, Direction::nord, false);

    // la case devant est vide
    CHECK(t.laVoieEstLibre(g) == true);

    // la case devant n'est pas vide
    g.poseBrindille(c);
    CHECK(t.laVoieEstLibre(g) == false);

    // la case devant n'est pas dans la grille
    Termite t2(1, 0, 0, Direction::sud, false);
    CHECK_THROWS_AS(t2.laVoieEstLibre(g), invalid_argument);
}

TEST_CASE("brindilleEnFace renvoie si la case devant le termite contient une brindille"){
    Grille g(5, 5);
    Coord c = {2, 4};
    Termite t(1, 2, 3, Direction:: est, false);
    
    //Il n'y a pas de brindille en face de termite
    CHECK(t.brindilleEnFace(g) == false);
    
    g.poseBrindille(c);
    CHECK(t.brindilleEnFace(g) == true);
    
    Termite t2(1, 0, 0, Direction::sud, false);
    CHECK_THROWS_AS(t2.brindilleEnFace(g), invalid_argument);
    
}

TEST_CASE("voisinsLibre renvoie le nombre de cases libre autour du termite"){
    Grille g(3, 3);
    Coord c1 = {0, 0};
    Coord c2 = {2, 2};
    Coord c3 = {1, 1};

    g.poseBrindille(c1);
    g.poseBrindille(c2);
    g.poseBrindille(c3);

    Termite t(1, 1, 1, Direction::nord, false);

    CHECK(t.voisinsLibre(g) == 6);

    g.enleveBrindille(c3);
    CHECK(t.voisinsLibre(g) == 6);

    g.enleveBrindille(c2);
    CHECK(t.voisinsLibre(g) == 7);

    g.enleveBrindille(c1);
    CHECK(t.voisinsLibre(g) == 8);
}

TEST_CASE("avance") {
	Grille g(5, 5);
	
	Termite t(1, 3, 2, Direction::nord, false);
	
	Coord c = {3, 2};
	g.poseTermite(c, 1);
	
	t.avance(g);
	c = {4, 2};
	
	CHECK(g.numeroTermite(c) == 1);
	
	t.tourneADroite();
	t.tourneADroite();
	t.avance(g);
	c = {4, 3};
	
	CHECK(g.numeroTermite(c) == 1);
	
	t.tourneADroite();
	t.tourneADroite();
	t.tourneADroite();
	t.tourneADroite();
	t.avance(g);
	c = {4, 2};
	
	CHECK(g.numeroTermite(c) == 1);
	
	t.tourneAGauche();
	t.tourneAGauche();
	t.avance(g);
	c = {3, 2};
	
	CHECK(g.numeroTermite(c) == 1);
}

TEST_CASE("charge/décharge brindille") {
	Grille g(3,3);
	
	Termite t(1, 1, 2, Direction::nord, false);
	
	Coord c = {2, 2};
	
	g.poseBrindille(c);
	
	CHECK(g.contientBrindille(c));
	
	t.avance(g);
	
	t.chargeBrindille(g);
	
	CHECK(!g.contientBrindille(c));
	
	t.dechargeBrindille(g);
	
	CHECK(g.contientBrindille(c));
}

int main(int argc, const char **argv) {

    doctest::Context context(argc, argv);
    int test_result = context.run();
    if (context.shouldExit())
    return test_result;
    
    return 0;
}
