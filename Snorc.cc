#include "defs.h"
#include "Snorc.h"

Snorc::Snorc(int r, int c, int s)
 :Participant('s', r, c, new VillainBehaviour), strength(s) {}

Snorc::~Snorc(){}

void Snorc::incurDamage(Participant* p){}

int Snorc::causeDamage() const{
    return strength;
}

bool Snorc::isSafe() const{
    return false;
}   