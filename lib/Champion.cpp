#include "Champion.h"
#include <fstream>
#include <iostream>
//#include <string>

Champion::Champion(){
    Status = true;
    Focus = false;
    Moving = false;
    ChampionName = "";
}

Champion::Champion(const Champion &old){
    ChampionName = old.ChampionName;
    Focus = old.Focus;
    Status = old.Status;
    Moving = old.Moving;
}

void Champion::SetChampion(std::string ChampionName){    
    SetChampionName(ChampionName);
    SetStats();
}

/*Champion::~Champion(){

};
*/
bool Champion::CheckStatus(){
    return Status;
}

bool Champion::CheckFocus(){
    if(Focus == true && BeingFocused->CheckStatus() == true){
        return Focus;
    }
    else{
        Focus = false;
        //std::cout << ChampionName << " has lost its focus because the focused champion died" << std::endl;
        return Focus;
    }
}

bool Champion::FindNewFocus(Team* EnemyTeam){
    bool result = false;
    Focus = false;
    for(int i = 0; i < EnemyTeam->CheckChampNumber(); i++)
        if((EnemyTeam->GetChampion(i))->CheckStatus() == true){
            result = true;
            BeingFocused = EnemyTeam->GetChampion(i);
            Focus = true;
    }
    return result;
}

Champion* Champion::GetFocusedChampion(){
    return BeingFocused;
}

bool Champion::CanAttack(){
    bool result = false;
    if(AttackTimer == 0 && BeingFocused->CheckStatus() == true){
        result = true;
    }
    return result;
}

void Champion::Attack(){
    BeingFocused->TakeDamage(attack_damage, "AD");
}

void Champion::TakeDamage(int IncomingDamage, std::string DamageType){
    int mitigated_damage;
    if(DamageType == "AD"){
        mitigated_damage = MitigationComputation(IncomingDamage, armor);
    }
    else if(DamageType == "AP"){
        mitigated_damage = MitigationComputation(IncomingDamage, magic_resistance);
    }
    else if(DamageType == "T" ){
        mitigated_damage = IncomingDamage;
    }
    else{
        std::cout << "Wrong damage type" << std::endl;
        mitigated_damage = 0;
    }
    health_points -= mitigated_damage;
    if(health_points <= 0){
        Status = false;
    }
}


int Champion::MitigationComputation(int RawDamage, int Resistance){
    if(Resistance >= 0){
        return RawDamage*(100.0 / (100.0 + Resistance));
    }
    else{
        std::cout << ChampionName << " has a resistance that is lower than 0, currently this case is treated as true dmg" << std::endl;
        return RawDamage;
    }
}

void Champion::SetAttackTimer(){
    AttackTimer = attack_speed;
}

double Champion::GetAttackTimer(){
    return AttackTimer;
}

void Champion::ChangeAttackTimer(double t){
    AttackTimer -= t;
    //std::cout << "yolo : " << Fight::GetTimeIncrement() << std::endl;
}

void Champion::ResetAttackTimer(){
    AttackTimer = 0;
}


void Champion::SetStats(){
    std::cout << "/////////////  Setting Stats /////////////" << std::endl;
    std::ifstream infile;
    infile.open("../DataStats/ChampionStats.dat",std::ios::in);
    if(infile.is_open()){
        std::cout << "youpi" << std::endl;
        for(std::string line; std::getline(infile, line);){
            if(line.front() == '/'){ 
                if(line.find(Champion::ChampionName)!= std::string::npos){
                    infile >> Stats::armor >> Stats::magic_resistance >> Stats::health_points_max >> Stats::attack_damage >> Stats::attack_speed;
                    infile >> Stats::attack_range >> Stats::crit_chance >> Stats::crit_damage >> Stats::dodge >> Stats::mana;
                    infile >> Stats::mana_max >> Stats::projectile_speed;
                    infile.close();
                }
            }
            if(infile.is_open() == false)
                break;
        }
    }
    Stats::health_points = health_points_max;
    std::cout << CheckHPmax() << std::endl;
}


std::string Champion::GetChampionName(){
    return ChampionName;
}

void Champion::SetChampionName(std::string cname){
    Champion::ChampionName = cname;
}

bool Champion::CheckAlive(){
    return Status;
}

void Champion::ChangeStatus(){
    if(Status){
        Status = false;
    }
    else{
        Status = true;
    }
}