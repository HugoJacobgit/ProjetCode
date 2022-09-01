#ifndef __STATS__
#define __STATS__

#include <string>

class Stats// : virtual public Team

{

public:

    Stats();
    ~Stats();
    //virtual void SetStats(std::string ChampionName);
    virtual void SetStats(){};
    int GetMana();
    int GetManaMax();
    void ResetMana();
    void AddMana(int Mana);
    int CheckHP();
    int CheckHPmax();
    
    int GetRange();

protected:

    int health_points_max;
    int health_points;
    int mana_max;
    int mana;
    int armor;
    int magic_resistance;
    double attack_speed;
    double projectile_speed;
    int attack_damage;
    int dodge;
    int attack_range;
    int crit_chance;
    int crit_damage;    


};


#endif