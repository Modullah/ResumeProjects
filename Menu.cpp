/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Implementation file for Menu functions.
*********************************************************************/

#include "Menu.hpp"
#include "Gameplay.hpp"
#include "validInput.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

//Function definition for Menu.
void menu()
{
  //Initialize variables.
  int menuInt;

  string input;

  // //Loop until user decides to exit the game.
  // do
  // {
    //Print options to console.
    cout << "\n[1] Play" << endl;
    cout << "[2] Exit \n" << endl;

    //Validate user input.
    getline(cin, input);
    menuInt = validInt(1, 2, input);

    //Switch to start game or end game.
    switch(menuInt)
    {
      case 1:
      {
        //Call start game function below.
        startGame();

        playAgain();

        //Break.
        break;
      }
      case 2:
      {
        //Ends the game.
        break;
      }
    }

  // //Once user enters the value two, game ends.
  // }while(menuInt != 2);

}

//Function definition which starts the game.
void startGame()
{
  int numLineup;

  string input;

  //Print character selection to console.
  cout << "\n************* Characters *************\n\n";
  cout << "[1] - Vampire      - has 1 armor, 18 strength, and charm.\n";
  cout << "[2] - Barbarian    - has 0 armor and 12 strength.        \n";
  cout << "[3] - Blue Men     - has 3 armor, 12 strength, and mob.  \n";
  cout << "[4] - Medusa       - has 3 armor, 8  strength, and glare.\n";
  cout << "[5] - Harry Potter - has 0 armor, 10/20 strength, and hogwarts.\n" << endl;
  cout << "\nEnter number of characters both teams will have. [Maximum of 10]: ";
  getline(cin, input);
  numLineup = validInt(1, 10, input);

  //Initialize gameplay object.
  Gameplay game(numLineup);

  game.buildLineup(1);
  game.buildLineup(2);

  game.fight();

}


void playAgain()
{

  //Initialize variables.
  int playInt;

  string playInput;

    //Print options to console.
    cout << "\n[1] Play again" << endl;
    cout << "[2] Exit" << endl;

    //Validate user input.
    getline(cin, playInput);
    playInt = validInt(1, 2, playInput);

    //Switch to start game or end game.
    switch(playInt)
    {
      case 1:
      {
        //Call start game function below.
        startGame();

        playAgain();

        //Break.
        break;
      }
      case 2:
      {
        //Ends the game.
        break;
      }
    }

}
