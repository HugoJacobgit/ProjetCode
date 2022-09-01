#ifndef __TEAM__
#define __TEAM__

#include <vector>

//#include "Augments.h"
#include "Fight.h"
#include "Color.h"

class Champion;

class Team : public Fight, public Color//, Augments


{
public:

    Team();
    //Team(int Nb, Champion[10] Champions);//, Augments[3] Augments);
    //~Team();
    
//    void SetChampionNumber(int ChampNumb);
    void AddChampion(Champion* Champ);    
    void SetTeamNumber(int nb);
    Champion* GetChampion(int Iterator);
    std::vector<Champion*>* GetChampionList(); 
    virtual bool CheckAlive();
    int CheckChampNumber();
    void CheckTeamComposition();
    int GetTeamNumber();

protected:

//    int ChampionNumber;
    std::vector<Champion*>* Champions;
    int TeamNumber;



};


#endif