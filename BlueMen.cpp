/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Implementation file for bluemen class.
*********************************************************************/

#include "BlueMen.hpp"
using std::cout;
using std::endl;

//Default constructor
BlueMen::BlueMen(std::string charName):Character(charName)
{
  //Initializing variables according to table values.
  armor = 3;

  //Health.
  strength = 12;

  this->charName = this->charName + " BlueMen";
}

/***********************************************************************
** Description: Function for attacking which redefines base class's
** pure virtual function. Calls roll function to get attacker's
** random roll and displays roll value to the user.
***********************************************************************/
int BlueMen::attack()
{
  //Bluemen rolls two die, each with 10 sides.
  int attack = roll(2, 10);

  //Print out 1.Attacker type and 3.Attacker's attack dice roll.
  cout << charName << " attacker's dice roll is " << attack << "." << endl;

  //Return attack value.
  return attack;
}

/***********************************************************************
** Description: Function that accepts character's attack value as a
** parameter and calculates how much damage character takes. See below
** comments for more details. Also redefines base class pure virtual.
***********************************************************************/
int BlueMen::defense(int attack)
{
  //Initialize variable.
  int mob;

  //Bluemen ability where they lose a die for every four damage taken
  //and part of a die roll for every increment of strength they lose.
  if(strength > 8 && strength <= 12){
    mob = 3;
  }
  else if(strength > 4 && strength <= 8){
    mob = 2;
  }
  else if(strength <= 4){
    mob = 1;
  }

  //Defense die roll for bluemen is mob number of die with six sides.
  int defense = roll(mob, 6);

  //Actual damage inflicted. Attacker roll value minus
  //defender's roll and defender's armor.
  int damage = attack - defense - armor;

  //Print 4.Defender's defense dice roll.
  cout << charName << " defender's dice roll is " << defense << "." << endl;

  //Print 5.The total inflicted damage calculation.
  cout << "Attacker total inflicted damage calculation: " << damage << "." << endl;

  /***********************************************************************
  ** If damage dealt is less than character defense make sure not to add
  ** health/strength to defending character. Basically, only deal damage
  ** when damage is a positive integer otherwise we add strength to the
  ** character, which is not intended.
  ***********************************************************************/
  if(damage >= 0)
  {
    //Strength equals strength minus damage.
    strength -= damage;
  }

  //If strength drops below zero.
  if(strength <= 0)
  {
    //Set strength to zero.
    strength = 0;
  }

  return damage;

}
