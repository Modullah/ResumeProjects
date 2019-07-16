/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Implementation file for vampire class.
*********************************************************************/

#include "Vampire.hpp"
#include <cstdlib>
using std::cout;
using std::endl;

//Default constructor
Vampire::Vampire(std::string charName):Character(charName)
{
  //Initializing variables according to table values.
  armor = 1;

  //Vampire's health.
  strength = 18;

  this->charName = this->charName  + " Vampire";
}

/***********************************************************************
** Description: Function for attacking which redefines base class's
** pure virtual function. Calls roll function to get attacker's
** random roll and displays roll value to the user.
***********************************************************************/
int Vampire::attack()
{
  //Vampire rolls one die with 12 sides.
  int attack = roll(1, 12);

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
int Vampire::defense(int attack)
{
  //Vampire special ability with fifty percent
  //chance to be zero or one.
  int charm = rand() % 2;

  //If one(true) charm is activated and vampire
  //takes no damage.
  if(charm)
  {
    //Print out ability to console.
    cout << charName << " Charm ability used. No damage taken." << endl;

    int damage = 0;

    return damage;

  }
  //Else vampire takes damage as normal.
  else
  {
    //Defense die roll for vampire is one die with six sides.
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
}
