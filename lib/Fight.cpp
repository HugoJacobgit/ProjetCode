#include "Fight.h"
#include "Team.h"
#include "Champion.h"

#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <random>

Fight::Fight(){
}

void Fight::SetupFight(Champion Champ[20]){
    TimeIncrement = 0.05;
    Time = 0;
    int iterator = 0;
    Team1 = new Team;
    Team2 = new Team;
    std::string ChampName;
    std::ifstream filein;
    filein.open("../DataStats/Team1.dat",std::ios::in);
    while(filein >> ChampName){
        Champ[iterator].SetChampion(ChampName);
        Champ[iterator].SetTeamNumber(1);
        Team1->AddChampion(&Champ[iterator]);
        iterator++;
    }
    filein.close();
    filein.open("../DataStats/Team2.dat",std::ios::in);
    while(filein >> ChampName){
        Champ[iterator].SetChampion(ChampName);
        Champ[iterator].SetTeamNumber(2);
        Team2->AddChampion(&Champ[iterator]);
        iterator++;
    }
    filein.close();
}

/*Fight::Fight(Team* Team1, Team* Team2){
    Fight::Team1 = Team1;
    Fight::Team2 = Team2;
    Time = 0;
    TimeIncrement = 0.05;
};*/


/*Fight::Fight(std::string FightFileName){
    filename = FightFileName;

    std::cout << "Hello 1" << std::endl;

    //int TeamStatus = 0;
    //Team1 = &Team();
    //std::size_t found;
    //std::ifstream infile;
    OpenInfile();
    //CloseInfile();
    CheckTeam();
    CheckTeam();
    CloseInfile();


    /*infile.open(FightFileName,std::ios::in);
    if(infile.is_open()){
        for(std::string line; std::getline(infile, line);){
            if(line.front() == '/'){
                if(line.find("Team1")!= std::string::npos){
                    std::cout << "Found Team1" << std::endl;               
                    TeamStatus = 1;
                }
                else if(line.find("Team2")!= std::string::npos){
                    std::cout << "Found Team2" << std::endl;               
                    TeamStatus = 2;
                }
                else if(TeamStatus > 0){
                    if(line.find("Leona")!= std::string::npos){
                        std::cout << "Added Leona to Team" << TeamStatus << std::endl;               
                        
                        Champion("Leona");
                    }
                }
                
                else{
                    std::cout << "This line is not meaningful. Note that the structure to declare a team should be:" << std::endl;
                    std::cout << "/ Team1" << std::endl;
                    std::cout << "/ Champion1, Champion2, Champion3, etc." << std::endl;
                    std::cout << "(Replace Champion1 by the name of the champion)" << std::endl << std::endl;
                }
            }
            else{
                std::cout << "Note that a meaningful line should start with an /" << std::endl << std::endl;;
            }
        }
    Time = 0;
    TimeIncrement = 0.05;
    Team1->CheckTeamComposition();
    Team2->CheckTeamComposition();
};
*/
std::string Fight::GetFileName(){
    return filename;
}

void Fight::SetFileName(std::string file){
    filename = file;
}

Team* Fight::GetTeam1(){
    return Team1;
}

Team* Fight::GetTeam2(){
    return Team2;
}

void Fight::RunAttacks(Team* CurrentTeam){
    int millitime = Time*1000;
        for (auto it= CurrentTeam->GetChampionList()->begin(); it != CurrentTeam->GetChampionList()->end(); it++){
            int i = std::distance(CurrentTeam->GetChampionList()->begin(),it);
            Champion* Champ = CurrentTeam->GetChampion(i);
            /*if(Champ->GetMana() == Champ->GetManaMax()){
                Champ->SpellCast();
                Champ->ResetMana();

            }*/
            if(Champ->CheckAlive()){
                if(millitime%1000 < 5 || millitime%1000 > 995){
                    std::cout << "/////////// Team" << CurrentTeam->GetTeamNumber() <<  "HP ///////////" <<  std::endl;
                    std::cout << Champ->GetChampionName() << ": " << Champ->CheckHP() << "/" << Champ->CheckHPmax() << std::endl << std::endl;;;

                }
                if(Champ->CheckFocus() == true){
                    if(Champ->CanAttack() == true){
                        Champ->Attack();
                        Champ->SetAttackTimer();
                    }
                    else{
                        if(Champ->GetAttackTimer() > 0){
                            Champ->ChangeAttackTimer(GetTimeIncrement());
                        }
                        else if (Champ->GetAttackTimer() < 0){
                            Champ->ResetAttackTimer();
                        }                    
                        else{
                            std::cout << "Something is wrong, the champ shouldve attacked" << std::endl;
                        }
                    }
                }
                else{
                    if(CurrentTeam->GetTeamNumber() == 1){
                        CurrentTeam->GetChampion(i)->FindNewFocus(Team2);
                    }
                    else{
                        CurrentTeam->GetChampion(i)->FindNewFocus(Team1);
                    }
                }
            }
            else{
                std::cout << Champ->GetChampionName() << " has just died" << std::endl;
                it = CurrentTeam->GetChampionList()->erase(it);
                it--;
            }        
        }

}

void Fight::RunAttacks2(std::mt19937* g){
    int millitime = Time*1000;
    std::vector<Champion*>* AllChampions = new std::vector<Champion*>;
    std::vector<Champion*>* ChampList1 = Team1->GetChampionList();
    std::vector<Champion*>* ChampList2 = Team2->GetChampionList();
    for (auto it= ChampList1->begin(); it != ChampList1->end(); it++){
        int i = std::distance(ChampList1->begin(),it);
        AllChampions->push_back((*ChampList1)[i]); 
    }
    for (auto it= ChampList2->begin(); it != ChampList2->end(); it++){
        int i = std::distance(ChampList2->begin(),it);
        AllChampions->push_back((*ChampList2)[i]); 
    }


    std::shuffle(AllChampions->begin(), AllChampions->end(), *g);
    for (auto it= AllChampions->begin(); it != AllChampions->end(); it++){
        int i = std::distance(AllChampions->begin(),it);
        //std::cout << (*AllChampions)[i]->GetChampionName() << std::endl;
        Champion* Champ = (*AllChampions)[i];
        //std::cout << Champ->GetTeamNumber() << std::endl;
        /*if(Champ->GetMana() == Champ->GetManaMax()){
            Champ->SpellCast();
            Champ->ResetMana();

        }*/
        if(Champ->CheckAlive()){
            if(millitime%1000 < 5 || millitime%1000 > 995){
                std::cout << "/////////// Team" << Champ->GetTeamNumber() <<  "HP ///////////" <<  std::endl;
                std::cout << Champ->GetChampionName() << ": " << Champ->CheckHP() << "/" << Champ->CheckHPmax() << std::endl << std::endl;;;
            }
            if(Champ->CheckFocus() == true){
                if(Champ->CanAttack() == true){
                    Champ->Attack();
                    Champ->SetAttackTimer();
                }
                else{
                    if(Champ->GetAttackTimer() > 0){
                        Champ->ChangeAttackTimer(GetTimeIncrement());
                    }
                    else if (Champ->GetAttackTimer() < 0){
                        Champ->ResetAttackTimer();
                    }                    
                    else{
                        std::cout << "Something is wrong, the champ shouldve attacked" << std::endl;
                    }
                }
            }
            else{
                if(Champ->GetTeamNumber() == 1){
                    Champ->FindNewFocus(Team2);
                }
                if(Champ->GetTeamNumber() == 2){
                    Champ->FindNewFocus(Team1);
                }
                /*else{
                    Champ->FindNewFocus(Team1);
                }*/
            }
        }
    }

} 


/*    std::cout << std::endl;

    std::shuffle(AllChampions->begin(), AllChampions->end(), g);
    for (auto it= AllChampions->begin(); it != AllChampions->end(); it++){
        int i = std::distance(AllChampions->begin(),it);
        std::cout << (*AllChampions)[i]->GetChampionName() << std::endl;
    } 

    std::cout << std::endl;
    
*/    
    
    
    
    
    
  /*  for (auto it= Team1->GetChampionList()->begin(); it != Team1->GetChampionList()->end(); it++){
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    
    for (auto it= ChampList1->begin(); it != ChampList1->end(); it++){
        std::cout << *it << std::endl;
        AllChampions->push_back(*it); 
    }
    std::cout << std::endl;

    for (auto it= ChampList2->begin(); it != ChampList2->end(); it++){
        std::cout << *it << std::endl;
        AllChampions->push_back(*it); 
    }
    std::cout << std::endl;

    for (auto it= AllChampions->begin(); it != AllChampions->end(); it++){
        std::cout << *it << std::endl;
    } 
    std::cout << std::endl;
    
    
    if((*AllChampions)[0]->CheckStatus())
        std::cout << "true1" << std::endl;
    (*AllChampions)[0]->ChangeStatus();
    if((*AllChampions)[0]->CheckStatus() == false)
        std::cout << "false1" << std::endl;
    if((*Team1->GetChampionList())[0]->CheckStatus() == false)
        std::cout << "false2" << std::endl;
//    Team1->GetChampionList()->erase(AllChampions->begin());

    for (auto it= AllChampions->begin(); it != AllChampions->end(); it++){
        std::cout << *it << std::endl;
    } 
    std::cout << std::endl;
    
    for (auto it= Team1->GetChampionList()->begin(); it != Team1->GetChampionList()->end(); it++){
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
*/


void Fight::RunFight(){
    int millitime;
    std::random_device rd;
    std::mt19937 g(rd());
    //RunAttacks2(g);
    while(Team1->CheckAlive() && Team2->CheckAlive() && Time < 30){
        RunAttacks2(&g);
        EraseDeadChamps(Team1);
        EraseDeadChamps(Team2);
        millitime = Time*1000;
        if(millitime%1000 < 5 || millitime%1000 > 995){
            std::cout << "Combat time is : " << Time << std::endl;
        }
    Time+= TimeIncrement;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void Fight::EraseDeadChamps(Team* CurrentTeam){
    for (auto it= CurrentTeam->GetChampionList()->begin(); it != CurrentTeam->GetChampionList()->end(); it++){
        int i = std::distance(CurrentTeam->GetChampionList()->begin(),it);
        Champion* Champ = CurrentTeam->GetChampion(i);
        if(Champ->CheckStatus() == false){
            it = CurrentTeam->GetChampionList()->erase(it);
            it--;
        }
    }
}

Fight::~Fight(){

};

double Fight::GetTimeIncrement(){
    return TimeIncrement;
}

