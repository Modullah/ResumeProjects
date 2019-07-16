/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Header file for medusa class.
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa: public Character
{
  public:

    //Default constructor.
    Medusa(std::string charName);

    //Function prototype to redefine pure virtual attack function.
    int attack();

    //Function prototype to redefine pure virtual defense function.
    int defense(int attack);

};

#endif
