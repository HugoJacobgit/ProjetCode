#ifndef __FIGHTPARSER__
#define __FIGHTPARSER__

#include <fstream>
#include <string>

class Fight;
class Team;
class Champion;

class FightParser
{
public:
    FightParser();
    FightParser(std::string file);
    //FightParser(Fight* CurrentFight);
    ~FightParser();
    
    void ParserChampionName(std::string ChampionName);
    void Parserfilename(std::string file);
    void ParserTeamStatus(int TeamStatus);
    //void ParserInFile()
    void ParserFight(Fight* CreatedFight);    

    void OpenInfile();
    void CheckTeam();
    void AddChampion();
    void CloseInfile();
    bool ReadChampions();

    bool CheckChampList();

    virtual Team* GetTeam1();
    virtual Team* GetTeam2();
    virtual std::string GetFileName();

protected:

    int TeamStatus;
    std::string ChampionName;
    std::ifstream infile;
    std::string filename;
    //Champion ChampToAdd;    


};

#endif