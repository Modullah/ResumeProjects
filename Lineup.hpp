/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/23/2018
** Description: Header file for lineup class.
*********************************************************************/

#ifndef LINEUP_HPP
#define LINEUP_HPP

#include "CharacterNode.hpp"
#include "Character.hpp"

class Lineup
{
  private:

    //Initializing character node pointers.
    CharacterNode *front;

    CharacterNode *back;

  public:

    //Default constructor.
    Lineup();

    //Default destructor.
    ~Lineup();

    //Function prototype.
    Character* getFront();

    //Function prototype.
    CharacterNode* removeFront();

    void addNew(int charType, std::string charName);

    //Function prototype.
    void addBack(CharacterNode *charNode);

    //Function prototype.
    void addFront(CharacterNode *charNode);

    //Function prototype.
    void print();
};

#endif
