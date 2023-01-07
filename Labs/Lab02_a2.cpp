#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

    //Activity 2

//random number generator
int RandNum (int maxNum)
{
  srand(time(NULL));
  return (rand()%(maxNum + 1));
}

//game process function
int PlayRound (int round)
{
  //variable declaration
  int playership, playerguess;
  int compship = (rand()%9 + 1);
  int compguess = RandNum(9);
  bool win;

  //process
  cout << "Guess location of the battleship [0,9]: ";
  cin >> playerguess;

  if (compguess == playership)
  {
    cout << "HIT!\n" << endl;
    win = true;
    cout << "PLAY AGAIN!\n" <<endl;
    round++;
  }
  else
  {
    cout << "MISS!\n" << endl;
  }

  cout << "Computer's Guess: " << compguess << endl;
  if(compguess == playership)
  {
    cout << "HIT!\n" << endl;
    win = true;
    cout << "PLAY AGAIN!" <<endl;
    round++;
  }
  else
  {
    cout << "MISS!\n" << endl;
  }

  return win;
}

int main() 
{
  cout << "-----------------------------------" << endl;
  cout << "    Welcome to Battleship Lite!    " << endl;
  cout << "-----------------------------------" << endl;

  //variable declaration
  int round = 1;
      
  cout << "Round: " << round << endl;
  while (round>=1)
  {  
    PlayRound(1);
  }

  return 0;
}