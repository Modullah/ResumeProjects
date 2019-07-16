/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Main file.
*********************************************************************/

#include "Menu.hpp"
#include <ctime>
#include <cstdlib>

//Function main.
int main()
{
  //Seeding random number generator.
  srand(time(NULL));

  //Call menu funtion to start program.
  menu();

  //Return zero to indicate normal exit.
  return 0;
}
