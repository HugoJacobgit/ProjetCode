/*#include "Team.h"
#include "Champion.h"

#include <fstream>
#include <iostream>*/
#include "FightParser.h"
#include "Fight.h"
#include "Champion.h"
#include "Team.h"
#include <iostream>
#include <string>
#include <fstream>

FightParser::FightParser(){
    TeamStatus = 0;
};

/*FightParser::FightParser( Fight CurrentFight ){
    
};*/

FightParser::FightParser(std::string file){
    TeamStatus = 0;
    FightParser::filename = file;


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
    }*/
    /*Time = 0;
    TimeIncrement = 0.05;*/
    /*Team1->CheckTeamComposition();
    Team2->CheckTeamComposition();*/
};



FightParser::~FightParser(){

};

void FightParser::Parserfilename(std::string filename){
    FightParser::filename = filename;
};

void FightParser::ParserTeamStatus(int TeamStatus){
    FightParser::TeamStatus = TeamStatus;
};

void FightParser::ParserChampionName(std::string ChampionName){
    FightParser::ChampionName = ChampionName;
};

/*void FightParser::ParserFight(Fight *CurrentFight){
    FightParser::CurrentFight = CurrentFight;
};*/

void FightParser::OpenInfile(){
    std::cout << filename << std::endl;
    infile.open(filename,std::ios::in);
    std::ofstream fileout1;
    fileout1.open("../DataStats/Team1.dat",std::ios::out);
    fileout1.close();
    std::ofstream fileout2;
    fileout2.open("../DataStats/Team2.dat",std::ios::out);
    fileout2.close();
}

void FightParser::CloseInfile(){
    infile.close();
}

void FightParser::CheckTeam(){
    int count = 0;

//    if(TeamNumber == 1 || TeamNumber == 2){
    if(infile.is_open()){
        for(std::string line; std::getline(infile, line);){
            if(line.front() == '/'){
                if(line.find("Team1")!= std::string::npos){
                    std::cout << "Found Team1" <<  std::endl;               
                    FightParser::TeamStatus = 1;
                    if(ReadChampions() == false){
                        std::cout << "Something is wrong with champions readin" << std::endl << std::endl;
                    }
                }
                if(line.find("Team2")!= std::string::npos){
                    std::cout << "Found Team2" <<  std::endl;               
                    FightParser::TeamStatus = 2;
                    if(ReadChampions() == false){
                        std::cout << "Something is wrong with champions readin" << std::endl << std::endl;
                    }
                }
            }
            count++;
            if(count == 1000){
                std::cout << "Count 1000" << std::endl;
                break;
            }
        }
    }
}


void FightParser::AddChampion(){
    std::cout << "Champion :" << FightParser::ChampionName << std::endl;
    //ChampToAdd = Champion(FightParser::ChampionName);
    bool IsChampion = CheckChampList();
    
    if(IsChampion){
        if(TeamStatus == 1){
            //GetTeam1()->CheckTeamComposition();
            std::ofstream fileout;
            fileout.open("../DataStats/Team1.dat",std::ios::app);
            fileout << ChampionName << " ";
            fileout.close();
            //CreatedFight->GetTeam1()->AddChampion(& ChampToAdd);
        }
        if(TeamStatus == 2){
            std::ofstream fileout;
            fileout.open("../DataStats/Team2.dat",std::ios::app);
            fileout << ChampionName << " ";
            fileout.close();
            //CreatedFight->GetTeam2()->AddChampion(& ChampToAdd);
        }
        std::cout << "Added champion " << ChampionName << " to Team" << TeamStatus << std::endl << std::endl; 
    }
}

bool FightParser::ReadChampions(){
    std::string ChampionName;
//    std::string line;
    bool result = true;
    if(infile.is_open()){
//        std::getline(*infile, line);
        while(infile >> ChampionName)
        {
            if(ChampionName == "/")
                break;
            ParserChampionName(ChampionName);
            AddChampion();
        }
        //if(line.find("Leona")!= std::string::npos){
//            std::cout << "Added Leona to Team" << TeamStatus << std::endl;               

//            Champion("Leona");
  //      }
    //    *infile >> ChampionName;

    }
    else{
        result = false;
    }

    return result;
}

Team* FightParser::GetTeam1(){
    std::cout << "This GetTeam1 is from FighParser (probaby not the one you're looking for)" << std::endl << std::endl;
    Team Dummy;
    return & Dummy;
}

Team* FightParser::GetTeam2(){
    std::cout << "This GetTeam2 is from FighParser (probaby not the one you're looking for)" << std::endl << std::endl;
    Team Dummy;
    return & Dummy;
}


std::string FightParser::GetFileName(){
    std::cout << "This GetFileName is from FighParser (probaby not the one you're looking for)" << std::endl << std::endl;
    return "Dummy return";
}


bool FightParser::CheckChampList(){
    
    bool ChampionExists = false;
    std::ifstream infile;
    infile.open("../DataStats/ChampionNames.dat", std::ios::in);
    if(infile.is_open()){
        for(std::string line; std::getline(infile, line);){
            if(line.find(ChampionName)!= std::string::npos){
                ChampionExists = true;  
                break;          
            }
        }
    }
    return ChampionExists;
}