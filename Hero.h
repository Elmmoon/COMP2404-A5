/*Class that represents the heroes of the escape.*/
#ifndef HERO_H
#define HERO_H

#include "defs.h"
#include "Participant.h"

class Hero: public Participant{
    public:
        Hero(char = ' ', int = 0, int = 0, string = " ");
        virtual ~Hero();
        virtual void incurDamage(Participant*);
        virtual int causeDamage() const;
        virtual bool isSafe() const;
        string getName() const;
        int getHealth() const;
        bool isRescued() const;

    private:
        string name;
        int health;
        bool rescued;

};

#endif
