/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Implementation file for Medusa class.
*********************************************************************/

#include "Medusa.hpp"
using std::cout;
using std::endl;

//Default constructor
Medusa::Medusa(std::string charName):Character(charName)
{
  //Initializing variables according to table values.
  armor = 3;

  //Medusa's health.
  strength = 8;

  this->charName = this->charName + " Medusa";
}

/***********************************************************************
** Description: Function for attacking which redefines base class's
** pure virtual function. Calls roll function to get attacker's
** random roll and displays roll value to the user.
***********************************************************************/
int Medusa::attack()
{
  //Medusa rolls two die, each with six sides.
  int attack = roll(2, 6);

  //Medusa special ability *Glare.
  //If roll value equals twelve she auto wins.
  if(attack == 12)
  {
    //Print out ability to console.
    cout << charName << " Glare ability used." << endl;

    //Set attack value high enough to autokill all random defense values.
    int attack = 9001;

    //Return glare attack value.
    return attack;
  }
  //Else just return random attack roll value.
  else
  {
    //Print out 1.Attacker type and 3.Attacker's attack dice roll.
    cout << charName << " attacker's dice roll is " << attack << "." << endl;

    //Return attack value.
    return attack;
  }
}

/***********************************************************************
** Description: Function that accepts character's attack value as a
** parameter and calculates how much damage character takes. See below
** comments for more details. Also redefines base class pure virtual.
***********************************************************************/
int Medusa::defense(int attack)
{
  //Defense die roll for medusa is one die with six sides.
  int defense = roll(1, 6);

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
