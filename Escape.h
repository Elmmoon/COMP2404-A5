/*The control class controlling the simulation of the escape*/

#ifndef ESCAPE_H
#define ESCAPE_H

#include "Hero.h"
#include "Participant.h"
#include "List.h"

class Escape{
  public:
    Escape();
    ~Escape();
    void runEscape();
    static bool withinBounds(int, int);

  private:
    List<Participant*> list;
    Hero* h1;
    Hero* h2;
    int numSnorcs;
    
    void spawnSnorc();
    void spawnNinja();
    void moveParticipants();
    Participant* checkForCollision(Participant*);
    bool isOver() const;
    void printPit() const;
    void printOutcome() const;
};

#endif

