#ifndef __FIGHT__
#define __FIGHT__

#include "FightParser.h"
#include "Position.h"
#include <iostream>
#include <string>
#include <random>

class Team;

class Fight: public FightParser//, public Position

{
public:

    Fight();
//    Fight(Team* Team1, Team* Team2);//, int Stage);
//    Fight(std::string FightFileName);
    void SetupFight(Champion Champ[20]);
    void RunFight();
    void RunAttacks(Team* CurrentTeam);
    void RunAttacks2(std::mt19937* g);
    void EraseDeadChamps(Team* CurrentTeam);
    ~Fight();

    std::string GetFileName();
    void SetFileName(std::string file);

    double GetTimeIncrement();

    Team* GetTeam1();
    Team* GetTeam2();




protected:

    std::string filename;
    Team* Team1;// = new Team;
    Team* Team2;// = new Team;
    
    double TimeIncrement;
    double Time;
    int Damage;
    




};


#endif