#include "iostream"
#include "ostream"
#include <cstdlib>
//#ifdef USE_ORIGINAL_LIB
#   include "Fight.h"
#   include "Team.h"
#include "Champion.h"
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
    Fight f1;
    Champion Champ1[20];
    f1.SetupFight(Champ1);
    f1.GetTeam1()->CheckTeamComposition();
    f1.GetTeam2()->CheckTeamComposition();
    f1.RunFight();




    #else
        std::cout << "Currenty not using any library, the project will quit" << std::endl;
    #endif
    return 0;
}