#include "Escape.h"
#include "Snorc.h"
#include "Ninja.h"
#include "defs.h"
#include <typeinfo>

Escape::Escape() : numSnorcs(0){
  srand((unsigned)time(NULL));

  int rand = random(10) + 7;
  h1 = new Hero('T', MAX_ROW - 1, rand, "Timmy");
  while (rand == h1->getCol())
    rand = random(10) + 7;
  h2 = new Hero('H', MAX_ROW - 1, rand, "Harold");
  list += h1;
  list += h2;
}

Escape::~Escape(){}

void Escape::runEscape(){ 
  while (!isOver()){
    if (random(100) < SNORC_SPAWN)
      spawnSnorc();
    if (random(100) < NINJA_SPAWN)
      spawnNinja();
    moveParticipants();
    printPit();
    usleep(300000); 
  }
  printPit();
  printOutcome();
}

bool Escape::withinBounds(int row, int col){
  return (row >= 0 && row < MAX_ROW && col >= 0 && col < MAX_COL);
}

void Escape::spawnSnorc(){ 
  if (numSnorcs >= MAX_SNORCS)
    return;
  list += new Snorc(MAX_ROW - random(5) - 1, random(MAX_COL), random(3) + 2);
  numSnorcs++;
}

void Escape::spawnNinja(){
  list += new Ninja(0, random(MAX_COL));
}

void Escape::moveParticipants(){ 
  Participant* arr[MAX_ARR];
  int size = 0;
  list.convertToArray(arr, size);
  for (int i = 0; i < size; i++){
    arr[i]->move();
    Participant* collision = checkForCollision(arr[i]);
    if (collision){
      collision->incurDamage(arr[i]);
      arr[i]->incurDamage(collision);
    }
  }
}

Participant* Escape::checkForCollision(Participant* p){ 
  Participant* arr[MAX_ARR];
  int size = 0;
  list.convertToArray(arr, size);
  for (int i = 0; i < size; i++){
    if (arr[i]->getCol() == p->getCol() && arr[i]->getRow() == p->getRow() 
    && p != arr[i])
      return arr[i];
  }
  return NULL;
}

bool Escape::isOver() const{ 
  return ((h1->isDead()|| h1->isSafe()) && (h2->isDead()|| h2->isSafe()));
}

void Escape::printPit() const{
  char tempLayout[MAX_ROW][MAX_COL + 1];
  for (int i = 0; i < MAX_ROW; i++){
    for (int j = 0; j < MAX_COL; j++)
        tempLayout[i][j] = ' ';
    tempLayout[i][MAX_COL] = '\0';
  }

  Participant* arr[MAX_ARR];
  int size = 0;
  list.convertToArray(arr, size);

  for (int i = 0; i < size; i++){
    int row = arr[i]->getRow();
    int col = arr[i]->getCol();
      if(!arr[i]->isSafe() && 
      tempLayout[row][col] != h1->getAvatar() &&
      tempLayout[row][col] != h2->getAvatar())
        tempLayout[row][col] = arr[i]->getAvatar();
  }
  
  int j = 0;
  cout << setw(MAX_COL + 2) << setfill('-') << ""; 
  for (; j < MAX_ROW - 1; j++)
    cout << endl << "|" << tempLayout[j] << "|";

  cout << left << setfill(' ') << setw(5) << "";
  cout << setw(6) << h1->getName() << ":";
  cout << setw(2) << "" << setw(4)<< h1->getHealth();
  if (h1->isDead())
    cout << "Deceased";
  else if (h1->isRescued())
    cout << "Rescued";
  else if (h1->isSafe())
    cout << "Escaped";
  
  cout << endl << "|" << tempLayout[j] << "|";
  cout << left << setfill(' ') << setw(5) << "";
  cout << setw(6) << h2->getName() << ":";
  cout << setw(2) << "" << setw(4)<< h2->getHealth();
  if (h2->isDead())
    cout << "Deceased";
  else if (h2->isRescued())
    cout << "Rescued";
  else if (h2->isSafe())
    cout << "Escaped";
  cout << endl << setw(MAX_COL + 2) << setfill('-') << "" << endl;
}

void Escape::printOutcome() const{
  cout << setfill(' ') << left;
  if (h1->isDead())
    cout << setw(6) << h1->getName() << " died..."<< endl;
  else if (h1->isRescued())  
    cout << setw(6) << h1->getName() << " was safely rescued!"<< endl;
  else
    cout << setw(6) << h1->getName() << " escaped on his own!!!"<< endl;

  if (h2->isDead())
    cout << setw(6) << h2->getName() << " died..."<< endl;
  else if (h2->isRescued())  
    cout << setw(6) << h2->getName() << " was safely rescued!"<< endl;
  else
    cout << setw(6) << h2->getName() << " escaped on his own!!!"<< endl;
}


