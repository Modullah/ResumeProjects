/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/23/2018
** Description: Implementation file for lineup class.
*********************************************************************/

#include "Lineup.hpp"
#include "CharacterNode.hpp"
#include "Character.hpp"

using std::cout;
using std::endl;
using std::string;


//Default constructor.
Lineup::Lineup()
{
  //set both pointers to nullptr
  front = nullptr;

  back = nullptr;
}

//Function to return front of list.
Character* Lineup::getFront()
{
  if(front == nullptr)
  {
    return nullptr;
  }
  else
  {
    return front->character;
  }
}

//Function to remove node from front of list.
CharacterNode* Lineup::removeFront()
{
  if(front == nullptr)
  {
    return nullptr;
  }
  //If only one node.
  else if(front == back)
  {
    CharacterNode *temp = front;
    front = nullptr;
    back = nullptr;

    return temp;
  }
  else
  {
    //Create temp pointer.
    CharacterNode *temp = front;

    //Set front to next.
    front = front->next;

    //Change front prev to back.
    front->prev = back;

    //Set back next to front.
    back->next = front;

    //Return temp pointer.
    return temp;
  }
}

//Function to create new linked node list.
void Lineup::addNew(int charType, string charName)
{
  //If only one node.
  if(front == nullptr)
  {
    front = new CharacterNode(charType, charName);
    back = front;

    //Create doubly linked circular list.
    front->next = back;
    front->prev = back;
    back->next = front;
    back->prev = front;
  }
  else
  {
    //Add a new object to end of list.
    CharacterNode *temp = new CharacterNode(charType, charName);
    front->prev = temp;
    back->next = temp;
    temp->prev = back;
    temp->next = front;
    back = temp;
  }
}

//Function to append integer to back of list.
void Lineup::addBack(CharacterNode *charNode)
{
  //If only one node.
  if(front == nullptr)
  {
    front = charNode;
    back = front;

    //Create doubly linked circular list.
    front->next = back;
    front->prev = back;
    back->next = front;
    back->prev = front;
  }
  else
  {
    //Add new object to end of list.
    CharacterNode *temp = charNode;
    front->prev = temp;
    back->next = temp;
    temp->prev = back;
    temp->next = front;
    back = temp;
  }
}

//Function to add integer to front of list.
void Lineup::addFront(CharacterNode *charNode)
{
  //If only one value.
  if(front == nullptr)
  {
    front = charNode;
    back = front;

    //Create doubly linked circular list.
    front->next = back;
    front->prev = back;
    back->next = front;
    back->prev = front;
  }
  else
  {
    //Add new object to end of list.
    CharacterNode *temp = charNode;
    back->next = temp;
    front->prev = temp;
    temp->prev = back;
    temp->next = front;
    front = temp;
  }
}

//Function to print to list to console.
void Lineup::print()
{
  if(front == nullptr)
  {
    std::cout << "The queue is empty.\n";
  }
  else
  {
    //Create pointer to transverse from front to back.
    CharacterNode *printer = front;

    do
    {
      //Print name to console.
      std::cout << printer->character->getName() << " ";

      //Point to next node.
      printer = printer->next;

    //Keep looping until front is reached.
    }while(printer != front);

    cout << endl;
  }
}

//Default destructor.
Lineup::~Lineup()
{
  while(front != nullptr)
  {
    //If only one node.
    if(front == back)
    {
      delete front;
      front = nullptr;
      back = nullptr;
    }
    else
    {
      //Create temp pointer.
      CharacterNode *temp = front;

      //Set front to next.
      front = front->next;

      //Change front prev to back.
      front->prev = back;

      //Set back next to front.
      back->next = front;

      //Free memory.
      delete temp;
    }
  }
}
