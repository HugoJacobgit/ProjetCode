#include "Leona.h"
#include "Stats.h"
#include <fstream>
#include <iostream>

Leona::Leona(){

};

void Leona::SetStats(){
    std::ifstream infile;
    infile.open("../DataStats/LeonaStats.dat",std::ios::in);
    infile >> Stats::armor >> Stats::magic_resistance >> Stats::health_points_max >> Stats::attack_damage >> Stats::attack_speed;
    infile >> Stats::attack_range >> Stats::crit_chance >> Stats::crit_damage >> Stats::dodge >> Stats::mana;
    infile >> Stats::mana_max >> Stats::projectile_speed;
    infile.close();
}

/*void Leona::SpellCast(){
    Stats::armor += 20;
    Stats::magic_resistance += 20;
};*/

/*void Leona::SetSpell(){
    Spell::SpellCast() = Leona::SpellCast();
}*/


Leona::~Leona(){

};
