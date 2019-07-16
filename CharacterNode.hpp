/*********************************************************************
** Program charName: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/23/2018
** Description: Header file for character node class.
*********************************************************************/
#ifndef CHARACTERNODE_HPP
#define CHARACTERNODE_HPP

#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <cstdlib>

struct CharacterNode
{
  //Initializing pointers.
  Character *character;

  CharacterNode *prev;

  CharacterNode *next;

  //Constructor to initialiaze node.
  CharacterNode(int charType, std::string charName)
  {

    //Set points to nullptr.
    prev = nullptr;

    next = nullptr;

    //New character created based on user selection.
    switch(charType)
    {
      case 1:
      {
        //Set character pointer to new vampire.
        character = new Vampire(charName);

        break;
      }
      case 2:
      {
        //Set character pointer to barbarian.
        character = new Barbarian(charName);

        break;
      }
      case 3:
      {
        //Set character pointer to new bluemen.
        character = new BlueMen(charName);

        break;
      }
      case 4:
      {
        //Set character pointer to new medusa.
        character = new Medusa(charName);

        break;
      }
      case 5:
      {
        //Set character pointer to new harry potter.
        character = new HarryPotter(charName);

        break;
      }
    }
  }

  //Default Destructor.
  ~CharacterNode()
  {
    //Free memory.
    delete character;
  }

};

#endif
