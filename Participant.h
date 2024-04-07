/*Abstract class that defines base functionality for each kind of participant,
i.e. Hero, Ninja and Snorc*/

#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "MoveBehaviour.h"
#include "defs.h"

class Participant{
  public:
    Participant(char = ' ', int = 0, int = 0, MoveBehaviour* b = NULL);
    virtual ~Participant();
    virtual void incurDamage(Participant*) = 0;
    virtual int causeDamage() const = 0;
    virtual bool isSafe() const = 0;
    char getAvatar() const;
    int getRow() const;
    int getCol() const;
    bool isDead() const;
    void setBehaviour(MoveBehaviour*);
    void move();
    
  protected:
    char avatar;
    bool dead;
    int row;
    int col;
    MoveBehaviour* behaviour;
};

#endif

