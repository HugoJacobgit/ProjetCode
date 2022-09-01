#include "iostream"
#include "ostream"
#include <cstdlib>
#include <random>
//#ifdef USE_ORIGINAL_LIB
#   include "Fight.h"
#   include "Team.h"
#   include "Champion.h"
#   include "Position.h"
//#endif


#include "ProjetConfig.h"

int main(){ 
    std::cout << "C++ version code : " <<  __cplusplus << std::endl;
    #ifdef USE_ORIGINAL_LIB
        std::cout << "Currently using original libraries to run the project" << std::endl;
//        Team* Team1();
//        Team* Team2();
    /*std::cout << "Nicolas Sarkozy 0" << std::endl;  
    Champion Champ1;
    Champion Champ2 = Champ1;
    
    Champion ChampList[2];
    ChampList[0] = Champ1;
    std::cout << "Nicolas Sarkozy 0" << std::endl;  
    Fight CurrentFight[1];
    std::cout << "Nicolas Sarkozy 0" << std::endl;  
    int index[1];
    std::cout << "Nicolas Sarkozy 0" << std::endl;  
    index[0] = 0;
    std::cout << "Nicolas Sarkozy 0" << std::endl;  */

//This part works
    FightParser("../Fight.dat");
    //Fight();


//This part works
    /*Champion Champ1[10];
    Champ1[0].SetChampion("Leona");
    Team Team1;
    Team1.AddChampion(& Champ1[0]);
    Team1.CheckTeamComposition();
*/
/*    Fight f1;
    Champion Champ1[20];
    f1.SetupFight(Champ1);
    f1.GetTeam1()->CheckTeamComposition();
    f1.GetTeam2()->CheckTeamComposition();
    f1.RunFight();
    */
    Position* Pos = new Position;
    Champion* Champ1 = new Champion(Pos->GetMap());
    Champ1->SetChampionName("Test1");
    Champion* Champ2 = new Champion(Pos->GetMap());
    Champ2->SetChampionName("Test2"); 
    Champion* Champ3 = new Champion(Pos->GetMap());
    Champ3->SetChampionName("Test3"); 
    Champion* Champ4 = new Champion(Pos->GetMap());
    Champ4->SetChampionName("Test4"); 
    
    
    Champion* Champ = new Champion(Pos->GetMap());
    Champ->SetChampionName("Draven");
    std::vector<std::vector<Champion*>>* Maptest= Pos->GetMap();
    
    std::random_device rd;
    std::mt19937 g(rd());
    
    Champ1->SetInitialPosition(Champ1,7,3);
    Champ2->SetInitialPosition(Champ2,4,6);
    Champ3->SetInitialPosition(Champ3,2,2);
    Champ4->SetInitialPosition(Champ4,3,0);
    
    Champ->SetInitialPosition(Champ,0,0);
    Champ->SetStats();
    Champion* ChampClose = Champ->FindClosestInRange(&g);
    if(ChampClose == NULL){
        std::cout << "C'est bien nul" << std::endl;
    }
    else{
        std::cout << ChampClose->GetChampionName() << std::endl;
    }

    std::cout << Champ->GetRealDistance(Champ1) << "   " << Champ->GetRealDistance(Champ2) << std::endl;
    std::cout << Champ->GetHexDistance(Champ1) << "   " << Champ->GetHexDistance(Champ2) << std::endl;
    Pos->PrintMap();

    #else
        std::cout << "Currenty not using any library, the project will quit" << std::endl;
    #endif
    return 0;
}