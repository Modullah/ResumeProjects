/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Header file for gameplay class.
*********************************************************************/

#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "Lineup.hpp"
#include "Character.hpp"

class Gameplay
{
  private:

    //Initializing private variables and pointers.
    Lineup *char1Lineup;

    Lineup *char2Lineup;

    Lineup *loserLineup;

    int numLineup;

  public:

    //Overloaded constructor.
    Gameplay(int numLineup);

    //Function prototype.
    void buildLineup(int charNum);

    //Function prototype.
    void fight();

    //Default destructor.
    ~Gameplay();
};

#endif
