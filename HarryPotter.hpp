/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Header file for harry potter class.
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter: public Character
{

  private:

    //Initializing bool variable for harry's special ability.
    bool hogwarts;

  public:

    //Default constructor.
    HarryPotter(std::string charName);

    //Function prototype to redefine pure virtual attack function.
    int attack();

    //Function prototype to redefine pure virtual defense function.
    int defense(int attack);

};

#endif
