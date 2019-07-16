/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Header file for barbarian class.
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian: public Character
{

  public:

    //Default constructor.
    Barbarian(std::string charName);

    //Function prototype to redefine pure virtual attack function.
    int attack();

    //Function prototype to redefine pure virtual defense function.
    int defense(int attack);

};

#endif
