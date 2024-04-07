#include "Hero.h"

Hero::Hero(char a, int r, int c, string n)
 : Participant(a, r, c, new EscapeeBehaviour), name(n)
 , health(MAX_HEALTH), rescued(false){}

Hero::~Hero(){}

void Hero::incurDamage(Participant* p){
    if (dead || isSafe())
        return;
    int damage = p->causeDamage();
    if (damage == RESCUE){
        rescued = true;
        setBehaviour(new RescuedBehaviour);
        return;
    }
    health -= damage;
    if (health <= 0){
        health = 0;
        avatar = '+';
        dead = true;
    }
}

int Hero::causeDamage() const{
    return 0;
}

string Hero::getName() const{
    return name;
}

int Hero::getHealth() const{
    return health;
}

bool Hero::isSafe() const{
    return (row == 0);
}

bool Hero::isRescued() const{
    return rescued;
}