/*Class that represents the ninjas of the escape.
Ninjas will turn into Giant Snorcs after being poisoned.
Only the behaviour class will change*/
#ifndef NINJA_H
#define NINJA_H

#include "defs.h"
#include "Participant.h"

class Ninja: public Participant{
    public:
        Ninja(int = 0, int = 0);
        virtual ~Ninja();
        virtual void incurDamage(Participant*);
        virtual int causeDamage() const;
        virtual bool isSafe() const;

    private:
        bool poisoned;
        int strength;

};

#endif
