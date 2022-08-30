#include "Stats.h"

Stats::Stats(){
};


Stats::~Stats(){

};

int Stats::GetMana(){
    return mana;
}

void Stats::ResetMana(){
    mana = 0;
}

int Stats::CheckHP(){
    return health_points;
}
int Stats::CheckHPmax(){
    return health_points_max;
}

void Stats::AddMana(int Mana){
    Stats::mana += Mana;
}