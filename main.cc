/* 
Purpose: A randomized simulation of the two heroes' (Timothy and Harold) escape from the pit. 
    Both heroes spawn at the bottom of the pit and will attempt to climb up to the top.
    Snorcs (monsters represented by the char 's'), will randomly spawn.
    If a snorc and a hero land on the same area, the hero will take damage.
    The movements of the heroes and snorcs are randomized. 
    Ninjas will randomly spawn at the top of the pit to rescue the heroes.
    They will rappel down the pit until the collide wit a hero.
    Once a Ninja collides with a hero, they will climb up the pit.
    If a ninja collides with a snorc, they will turn into a giant snorc ('S').
    Giant snorcs will act as normal snorcs but will deal greater damage to the heroes.
    When a hero reaches 0 health they will die.
    If a hero reaches the top, they have escaped and will be removed from the simulation.
    The simulation ends when both heroes have died or escaped.
Usage:
    Enter the project directory
    Enter 'make', then './a5' into the command line
Author: Dylan Yin
ID: 101257186
*/

#include "Escape.h"

int main(){
    Escape escape;
    escape.runEscape();
}