#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  string filename;
  const int SIZE = 5;
  //Our first array of 5 strings
  string data[SIZE];

  cout << "enter file name: " << endl;
  cin >> filename;
  ofstream myfile(filename);
  // or
  ofstream filename2;
  filename2.open("afile.txt");

  myfile.close();
  filename2.close();

  ifstream myInput(filename);
  while (!myInput.eof())
  {
    string line;
    myInput>> line;
    cout<<line<<endl;
  }
  
  if(myfile.fail())
  {
    cout << "file has no permission to read";
    exit(1);
  }

  return 0;
}


