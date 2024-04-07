#include "Ninja.h"
#include "defs.h"

Ninja::Ninja(int r, int c)
 : Participant('N', r, c, new RescuerBehaviour), poisoned(false), strength(0){}

Ninja::~Ninja(){}

void Ninja::incurDamage(Participant* p){
    if (dead || isSafe() || poisoned)
        return;
    int damage = p->causeDamage();
    if (damage == RESCUE)
        return;
    if (damage == 0){
        setBehaviour(new RescuedBehaviour);
        return;
    }
    poisoned = true;
    avatar = 'S';
    strength = random(3) + 6;
    setBehaviour(new VillainBehaviour);
}

int Ninja::causeDamage() const{
    if (poisoned)
        return strength;
    return RESCUE;
}

bool Ninja::isSafe() const{
    int newRow, newCol;
    behaviour->move(row, col, newRow, newCol);
    return (!poisoned && ((row == 0 && newRow == -1) || row == MAX_ROW - 1));
}
