/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Header file for vampire class.
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire: public Character
{
  public:

    //Default constructor.
    Vampire(std::string charName);

    //Function prototype to redefine pure virtual attack function.
    int attack();

    //Function prototype to redefine pure virtual defense function.
    int defense(int attack);
};

#endif
