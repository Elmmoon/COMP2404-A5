/*Class that represents the snorcs of the pit*/
#ifndef SNORC_H
#define SNORC_H

#include "Participant.h"

class Snorc: public Participant{
    public:
        Snorc(int = 0, int = 0, int = 0);
        ~Snorc();
        virtual void incurDamage(Participant*);
        virtual int causeDamage() const;
        virtual bool isSafe() const;
    private:
        int strength;
};

#endif
