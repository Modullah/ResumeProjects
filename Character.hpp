/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/23/2018
** Description: Header file for character class.
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

class Character
{

  protected:

    //Initializing variables.
    int armor;

    //Character health.
    int strength;

    //Character type.
    std::string type;

    std::string charName;

  public:

    //Default constructor.
    Character(std::string charName);

    //Pure virtual attack function.
    virtual int attack() = 0;

    //Pure virtual defense function.
    virtual int defense(int attack) = 0;

    //Function prototype for die roll.
    int roll(int roll, int die);

    //Getter prototype to get health.
    int getStrength();

    //Getter prototype to get armor.
    int getArmor();

    //Getter prototype to get type.
    std::string getType();

    //Getter prototype to get name.
    std::string getName();

    //Setter prototype to set type.
    void setType(std::string type);

    //Function prototype for recovery die roll.
    void recovery(int damage);

};

#endif
