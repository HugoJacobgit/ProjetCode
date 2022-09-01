#ifndef __POSITION__
#define __POSITION__

#include <string>
#include <vector>
#include <random>

class Champion;

class Position// : virtual public Team

{
///////// IMPORTANTE NOTE A MOI MEME //////////
// J'ai fait le test et les dimensions du terrain sont telles que la relation d'ordre entre deux distances en hex et deux distances réelles est respectée
//(Pour deux longueur en hex différentes)
// Cela n'est plus le cas si on ajoute un hexagone de longueur à chaque rangée !!
// On peut donc explorer le terrain par hexagones concentriques avant de se poser la question de la distance réelle minimale
// En fait non mais remarque: c'est le cas que dans un seul cas de figure-> marginal, on ignore ce détail pour l'instant

public:

    Position();
    Position(std::vector<std::vector<Champion*>>* DefineMap);
    ~Position();


    void SetInitialPosition(Champion* Champ, int x, int y);
    void MoveToFocused();
    //std::vector<Champion*> 

    Champion* FindClosest(std::mt19937* g);
    Champion* FindClosestInRange(std::mt19937* g); // Find all champions at lowest distance (can be more than 1, in this case use random)
    // Y'a moyen d'optimiser cette fonction en lui faisant d'abord explorer les hexagones proches et en s'éloignant au fur et à mesure;
    // puis en faisant un break dès qu'on a exploré tout un hexagone dans lequel on 
    //std::vector<Champion*> FindInRange(); // Find all champions in range
    double GetRealDistance(Champion* Champ);
    int GetHexDistance(Champion* Champ);

    double Computexcoor();
    double Computeycoor();

    int Getxm();
    int Getym();
    double Getxcoor();
    double Getycoor();




//    std::vector<std::vector<int>>* GetMap();    
    std::vector<std::vector<Champion*>>* GetMap();    
    void PrintMap();
    void PrintTopHex(int i);
    void PrintLastTopHex();
    void PrintBottomHex(int i);
    void PrintLateralHex(int i);


protected:

    int MapLength = 7;
    int MapWidth = 8;
    //std::vector<std::vector<int>>* Map;
    std::vector<std::vector<Champion*>>* Map;
    int xm;
    int ym;
    double xcoor;
    double ycoor;

};


#endif