/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Header file for bluemen class.
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen: public Character
{
  public:

    //Default constructor.
    BlueMen(std::string charName);

    //Function prototype to redefine pure virtual attack function.
    int attack();

    //Function prototype to redefine pure virtual defense function.
    int defense(int attack);
};

#endif
