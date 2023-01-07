#include <iostream>
#include <string> 
#include <fstream> 

using namespace std;

void writeString(string texts)
{
  ofstream filename;
  filename.open ("user.txt");
  filename << texts << endl;
  filename.close();
}

int main() 
{
  //variable declaration
  string words;

  //process and output
  cout << "Enter a string: ";
  cin >> words;
  writeString(words);
  cout << "String test written to file user.txt";

  return 0;

}