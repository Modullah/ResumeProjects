/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Implementation file for character class.
*********************************************************************/

#include "Character.hpp"

#include <cstdlib>
using std::cout;
using std::string;

//Default constructor.
Character::Character(string charName)
{
  this->charName = charName;
}

/***********************************************************************
** Description: Function that calculates a random roll by taking two int
** parameters. A int for number of die and a int for number of sides.
***********************************************************************/
int Character::roll(int roll, int die)
{
  //Initialize temp variable.
  int Roll = 0;

  //Loop to calculate total roll value.
  for(int i = 0; i < roll; i++)
  {
    Roll += rand() % die + 1;
  }

  //Return roll value.
  return Roll;
}

//Function definition to get character health.
int Character::getStrength()
{
  return strength;
}

//Function definition to get character armor.
int Character::getArmor()
{
  return armor;
}

//Function definition to get character type.
string Character::getType()
{
  return type;
}

//Function definition to get character name.
string Character::getName()
{
  return charName;
}

//Function definition to set character type.
void Character::setType(string type)
{
  this->type = type;
}

//Function to heal character while in list.
void Character::recovery(int damage)
{
  //Random number roll between one and five.
  int healRoll = rand() % 5 + 1;

  //Damage multiplied by fraction to get new strength value.
  strength += abs(damage) * (healRoll/10.0);

  //Print to console new updated strength value.
  cout << "recovered to " << strength << " strength while resting in lineup. \n";
}
