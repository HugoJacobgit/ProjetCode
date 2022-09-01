#ifndef __LEONA__
#define __LEONA__

#include <string>
//#include "Champion.h"
//#include "Stats.h"
//#include "Spell.h"
#include "Champion.h"

class Leona : public Champion//, public Position

{

public:

    Leona();
    void SetStats();
    void SetSpell();
//    void Leona_Spell();
    ~Leona();

protected:

    void SpellCast();


};


#endif