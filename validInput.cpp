/*********************************************************************
** Program name: Project4_Adlouni_Mohammad
** Author: Mohammad(Mo) Adlouni
** Date: 05/08/2018
** Description: Implementation file for input validation function.
*********************************************************************/
#include "validInput.hpp"
#include <iostream>
#include <sstream>

/***********************************************************************
** Description: Function converts string to a stream
** to move the ant and update the grid accordingly. Will continue to
** loop until user intputs valid integer.
***********************************************************************/
int validInt(int min,int max, std::string strNum){

  int vInt;

  //Convert the string into a stream.
  std::stringstream convert(strNum);

  //Boolean if else statement. If true return integer if false prompt user to enter valid integer.
  if (convert >> vInt && !(convert >> strNum) && vInt >= min && vInt <=max) return vInt;
  else{

    std::string strNum;
    int returnInt;

    std::cout << "Please enter a valid integer value greater than or equal to " << min << std::endl;
    std::cout << "and less than or equal to " << max << "." << std::endl;
    std::getline(std::cin, strNum);

    //Set returnInt equal Recursive function.
    returnInt = validInt(min, max, strNum);

    return returnInt;
  }

}
