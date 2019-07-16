/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Implementation file for gameplay class.
*********************************************************************/

#include "Gameplay.hpp"
#include "Lineup.hpp"
#include "validInput.hpp"
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//Overloaded constructor.
Gameplay::Gameplay(int numLineup)
{
  //Set pointer to point to new lineup.
  loserLineup = new Lineup;

  this->numLineup = numLineup;
}

//Function to add characters to roster/lineup.
void Gameplay::buildLineup(int charNum)
{
  //Create temp Lineup pointer.
  Lineup *temp = new Lineup;

  //Print to console.
  cout << "\nPlayer " << charNum << " please select " << numLineup << " character(s). \n\n" << endl;

  //loop based on number of characters allowed.
  for(int i = 0; i < numLineup; i++)
  {
    //Initialize variables.
    string typeInput;
    string charName;

    //Print to console.
    cout << "Character " << i + 1 << " type: " << endl;

    //Validate user input.
    getline(cin, typeInput);
    int charType = validInt(1, 5, typeInput);


    cout << "Enter character name: " << endl;
    getline(cin, charName);

    //Add a new node.
    temp->addNew(charType, charName);
  }

  //Based on input assign to a temp pointer.
  switch(charNum)
  {
    case 1:
    {
      char1Lineup = temp;
      break;
    }
    case 2:
    {
      char2Lineup = temp;
      break;
    }
  }

  cout << endl;
}

//Function to have characters battle each other.
void Gameplay::fight()
{
  //create two temp pointers for easy access
  Character *character1 = char1Lineup->getFront();
  Character *character2 = char2Lineup->getFront();

  //Counter variable for rounds.
  int counter = 1;

  int char1Points = 0;
  int char2Points = 0;

  //loop until no front node for both lineups.
  while(character1 != nullptr && character2 != nullptr)
  {

    //Variables to hold character damage.
    int char1Damage = 0;
    int char2Damage = 0;

    //Print rounds to console.
    cout << endl;
    cout << "**************************Round " << counter << ": ";
    cout << "Player 1 " << character1->getName() << " vs. ";
    cout << "Player 2 " << character2->getName() << "**************************\n" << endl;

    //While both characters alive, do the below.
    while(character1->getStrength() && character2->getStrength())
    {
      //Player one attacks first.
      //Print 1. Attacker Type.
      cout << "Attacker " << character1->getName() << ".\n" << endl;

      //Print 2. Defender type, armor, and strength point.
      cout << "Defender "<< character2->getName() << " has ";
      cout << character2->getArmor() << " armor and ";
      cout << character2->getStrength() << " strength point(s). \n" << endl;

      //Player one attacks player two.
      char2Damage += character2->defense(character1->attack());

      //Print 6.The defender’s updated strength point
      //amount after subtracting damage.
      cout << character2->getName() << " updated strength after taking damage: ";
      cout << character2->getStrength() << ".\n" << endl;

      if(character2->getStrength() == 0)
      {
        cout << character1->getName() << " Won! \n" << endl;
        char1Points++;

        //Restore random amount of strength.
        cout << character1->getName() << " ";
        character1->recovery(char1Damage);
        cout << endl;

        //Add winner to back of winning line up.
        char1Lineup->addBack(char1Lineup->removeFront());

        //Add loser to loser lineup.
        loserLineup->addFront(char2Lineup->removeFront());

        //Pull new characters to battle from list.
        character1 = char1Lineup->getFront();
        character2 = char2Lineup->getFront();

        break;
      }

      //Player two attacks second.
      //Print 1. Attacker Type.
      cout << "Attacker " << character2->getName() << ".\n" << endl;

      //Print 2. Defender type, armor, and strength point.
      cout << "Defender "<< character1->getName() << " has ";
      cout << character1->getArmor() << " armor and ";
      cout << character1->getStrength() << " strength point(s). \n" << endl;

      //Player two attacks player one.
      char1Damage += character1->defense(character2->attack());

      //Print 6.The defender’s updated strength point
      //amount after subtracting damage.
      cout << character1->getName() << " updated strength after taking damage: ";
      cout << character1->getStrength() << ".\n" << endl;

      //If character one dies.
      if(character1->getStrength() == 0)
      {
        cout << character2->getName() << " Won! \n" << endl;
        char2Points++;

        ////Restore random amount of strength.
        cout << character2->getName() << " ";
        character2->recovery(char2Damage);
        cout << endl;

        //Add winner to back of winning line up.
        char2Lineup->addBack(char2Lineup->removeFront());

        //Add loser to loser lineup.
        loserLineup->addFront(char1Lineup->removeFront());

        //Pull new characters to battle from list.
        character1 = char1Lineup->getFront();
        character2 = char2Lineup->getFront();

        break;
      }

    }

    counter++;

  }

    cout << "\n\n************* Final Scores *************\n\n" <<endl;
    cout << "Player 1 Score: " << char1Points << endl;
    cout << "Player 2 Score: " << char2Points << endl;

    //Print to console based on points.
    if(char1Points > char2Points)
    {
      cout << "Player 1 Won! \n" << endl;
    }
    else if (char1Points < char2Points)
    {
      cout << "Player 2 Won! \n" << endl;
    }
    else
    {
      cout << "The tournament resulted in a tie." << endl;
    }

    //Print loser line up if desired.
    cout << "\nDisplay Loser pile? Enter [1] for yes and [2] for no. " << endl;

    //Validate user input.
    string loserInput;
    getline(cin, loserInput);
    int loserInt = validInt(1, 2, loserInput);

    if(loserInt == 1)
    {
      loserLineup->print();
    }
    else{

      return;
    }

}

//Default destructor.
Gameplay::~Gameplay()
{
    delete loserLineup;
    delete char1Lineup;
    delete char2Lineup;
}
