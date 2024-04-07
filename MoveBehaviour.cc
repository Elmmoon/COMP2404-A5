#include "MoveBehaviour.h"
#include "defs.h"
#include "Escape.h"

void EscapeeBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol){
    do{
        newRow = oldRow + random(5) - 2;
        newCol = oldCol + random(3) - 1;
    } while(!Escape::withinBounds(newRow, newCol));
}

void RescuedBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol){
    newRow = oldRow - 1;
    newCol = oldCol;
}

void RescuerBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol){
    newRow = oldRow + 1;
    newCol = oldCol;
}

void VillainBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol){
    do{
        newRow = oldRow;
        newCol = oldCol + random(3) - 1;
        if (random(2) == 0)
            newRow--;
        else
            newRow++;
    } while(!Escape::withinBounds(newRow, newCol) || newRow < MAX_ROW - 7);
    
}

MoveBehaviour::MoveBehaviour(){}
MoveBehaviour::~MoveBehaviour(){}

EscapeeBehaviour::EscapeeBehaviour(){}
EscapeeBehaviour::~EscapeeBehaviour(){}

RescuedBehaviour::RescuedBehaviour(){}
RescuedBehaviour::~RescuedBehaviour(){}

RescuerBehaviour::RescuerBehaviour(){}
RescuerBehaviour::~RescuerBehaviour(){}

VillainBehaviour::VillainBehaviour(){}
VillainBehaviour::~VillainBehaviour(){}
