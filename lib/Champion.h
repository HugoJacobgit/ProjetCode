#ifndef __CHAMPION__
#define __CHAMPION__

//#include "Position.h"
#include "Stats.h"
#include "Spell.h"
#include "Team.h"
//#include "Team.h"
//#include "Fight.h"
#include <string>
#include <iostream>

class Champion : public Team, public Stats, public Spell, public Position


{
//    friend class Stats;

public:

    Champion();
    Champion(std::vector<std::vector<Champion*>>* DefineMap);
    Champion(const Champion &old);
    void SetChampion(std::string ChampionName);
//    ~Champion();
    
    
    void SetChampionName(std::string ChampionName);
    std::string GetChampionName(); 
    void SetStats();
    
    //virtual void SetStatus(bool ChampionStatus);
    
    bool FindNewFocus(Team* EnemyTeam);
    Champion* GetFocusedChampion();
    bool CheckStatus();
    bool CheckFocus();

/*    bool GetCastingStatus();
    bool GetStunStatus();
    int GetRemainingStunTime();
    int GetReaminingCastTime();     
    void SetStunTime(double StunTime);
    void SetCastTime();
*/
    bool CanAttack();
    void Attack();
    void SetAttackTimer();
    double GetAttackTimer();
    void ChangeAttackTimer(double t);
    void ResetAttackTimer();

    void TakeDamage(int IncomingRawDamage, std::string DamageType);
    int MitigationComputation(int RawDamage, int Resistance);

    bool CheckAlive();

    void ChangeStatus();

protected:

    std::string ChampionName;
    bool Focus;
    bool Status;
    bool Moving;
    Champion* BeingFocused;

    bool IsCasting;
    bool IsStunned;
    double RemainingCastTime;
    double RemainingStunTime;
    double AttackTimer;


};


#endif