#include "Team.h"
#include "Champion.h"
#include <vector>

Team::Team()
    :Fight()
{
    Champions = new std::vector<Champion*>;
};

void Team::SetTeamNumber(int nb){
    TeamNumber = nb;
}

int Team::GetTeamNumber(){
    return TeamNumber;
}
/*void Team::SetChampionNumber(int ChampNumb){
    ChampionNumber = ChampNumb;
};
*/

void Team::AddChampion(Champion* Champ){
    std::cout << Champ->GetChampionName() << std::endl;
    Champions->push_back(Champ);    
    //std::cout << "Hello 14" << std::endl;
}

bool Team::CheckAlive(){
    bool result = false;
    for(int i = 0; i < Champions->size(); i++){
        if((*Champions)[i]->Champion::CheckStatus() == true){
            result = true;
        }
    }
    return result;
}

int Team::CheckChampNumber(){
    return Champions->size();
}

Champion* Team::GetChampion(int Iterator){
    return (*Champions)[Iterator];
}

/*Team::~Team(){

};
*/
void Team::CheckTeamComposition(){
    std::cout << Champions->size() << std::endl;
    std::cout << "The team composition is the following :" << std::endl;
    
    for(Champion* it : *Champions){
        std::cout << it->GetChampionName() << " ";
    }
    std::cout << std::endl << std::endl;
}

std::vector<Champion*>* Team::GetChampionList(){
    return Champions;
}