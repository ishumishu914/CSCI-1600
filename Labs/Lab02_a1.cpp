#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

  //Activity 1

int main()
{
  cout << "-----------------------------------" << endl;
  cout << "    Welcome to Battleship Lite!    " << endl;
  cout << "-----------------------------------" << endl;

  //variable declaration
  int round = 1;
  int guess;
  int num = 10;
  int attempt = 1;
  
  //process
  while (attempt <= 5)
  {
    int rndnum = rand()%num;
    srand(time(NULL));
    
    //output
    cout << "Round: " << round << endl;
    cout << "Guess a location of the battleship: " << endl;
    cin >> guess;

    if (guess == rndnum)
    {
      cout << "You are a gunius!" << endl;
      attempt = 1;
      round++;
      num += 10; 
    }
    else 
    {     
      cout << "Miss!" << endl;
      attempt++;    
    }
  }
    return 0;
}