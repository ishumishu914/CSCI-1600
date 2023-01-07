#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() 
{
  string filename;
  const int SIZE = 5;
  string data[SIZE];

  cout << "Enter output filename: ";
  cin >> filename;
  ofstream myOutput(filename, ios::app);

  cout << "Enter " << SIZE << " words to store in a file in reverse order: ";
  for (int i=0; i < SIZE; i++) 
  {
    cin >> data[i];
  }

  for (int i = SIZE-1; i >= 0; i--) 
  {
    myOutput << data[i] << endl;
  }

  myOutput.close();

  //check if the fstream encountered an error
  //when opening
  if(myOutput.fail()) 
  {
    cout << "ERROR: no permissions to write to file" << filename << endl;
    exit(1);
  }

  //close the file 
  myOutput.close();

  //FILE INPUT




  //Close the file
  //myInput.close();

  return 0;
}
