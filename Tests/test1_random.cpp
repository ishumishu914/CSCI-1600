#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main() 
{
  //variable declaration
  int min = 2;
  int max = 5;
  int randomnum;

  //seed random num generator
  srand(time(NULL));

  //process
  randomnum = min + rand()%((max-min)+1);

  //output
  cout << "A random number in the range  [" << min << ", " << max << "} is " << randomnum << "." << endl;

  return 0;

}