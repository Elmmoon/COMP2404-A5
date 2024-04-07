#include "Participant.h"

Participant::Participant(char a, int r, int c, MoveBehaviour* b)
 :avatar(a), dead(false), row(r), col(c), behaviour(b){}

Participant::~Participant(){
    delete behaviour;
}

char Participant::getAvatar() const{
    return avatar;
}

int Participant::getRow() const{
    return row;
}

int Participant::getCol() const{
    return col;
}

bool Participant::isDead() const{
    return dead;
}

void Participant::setBehaviour(MoveBehaviour* b){
    if (behaviour)
        delete behaviour;
    behaviour = b;
}

void Participant::move(){
    if (dead || isSafe())
        return;
    int newRow, newCol;
    behaviour->move(row, col, newRow, newCol);
    row = newRow;
    col = newCol;
}

