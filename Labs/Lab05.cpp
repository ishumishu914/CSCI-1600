/*
#include <iostream>
#include <cmath>

using namespace std;
const int A_CONSTANT = 3;

void functionA(int a[], int aNumber);
void functionB(int a[], int anotherNumber);
void functionC(const int anArray[], int aNumber);
void functionD(int& sum);
int functionE(double number); void functionF(int n);

int main( )
{
    int production[A_CONSTANT];
    cout << "This program displays a graph showing\n" << "production for each factory in the company.\n";
    functionA(production, A_CONSTANT);
    functionB(production, A_CONSTANT);
    functionC(production, A_CONSTANT);
    return 0;
}

void functionA(int a[], int aNumber)
{
    for (int someNumber = 1;someNumber <= aNumber; someNumber++)
    {
        cout << endl << "Enter production data for plant number " << someNumber << endl;
        functionD(a[someNumber - 1]);}}

void functionD(int& sum)
{
    cout << "Enter number of units produced by each department.\n" << "Append a negative number to the end of the list.\n";
    sum = 0; int next;
    cin >> next;
    while (next >= 0) {
    sum = sum + next;
    cin >> next;
    } cout << "Total = " << sum << endl;
}

void functionB(int a[], int anotherNumber)
{
for (int index = 0; index < anotherNumber; index++)
    a[index] = functionE(a[index]/1000.0);
}

int functionE(double number) {
return static_cast<int>(floor(number + 0.5));
}

void functionC(const int anArray[], int aNumber)
{
    cout << "\nUnits produced in thousands of units:\n";
    for (int someNumber = 1; someNumber <= aNumber; someNumber++)
    {
        cout << "Factory #" << someNumber << " ";
        functionF(anArray[someNumber - 1]);
        cout << endl;
    }
}
void functionF(int n) {
    for (int count = 1; count <= n; count++) cout << "*";
} */

#include <iostream>
#include <cmath>

using namespace std;
const int totalPlantNum = 3;

void productionData(int production[], int totalPlantNum);
void numStarCalc(int production[], int num_factories);
void finalOutput(const int num_stars[], int totalPlantNum);
void unitsProduced(int& sum);
void printUnit(int unitNum);
int roundNum(double totalNum_unit); 

int main()
{
  //variable declaration
  int production[totalPlantNum];
  
  // output
  cout << "This program displays a graph showing\n" << 
  "production for each factory in the company.\n";

  productionData(production, totalPlantNum);
  numStarCalc(production, totalPlantNum);
  finalOutput(production, totalPlantNum);

  return 0;
}

// calls unitsProduced function for each plant number
void productionData(int production[], int totalPlantNum)
{
  for (int plantnum = 1; plantnum <= totalPlantNum; plantnum++)
  {
    // output
    cout << endl << "Enter production data for plant number: " << plantnum << "\n";
    unitsProduced(production[plantnum - 1]);
  }
}

// takes user input of amount of production data for each department 
void unitsProduced(int& sum)
{
  // variable declaration
  sum = 0; 
  int units;

  //take user input 
  cout << "Enter number of units produced by each department.\n" 
  << "Append a negative number to the end of the list.\n";
  cin >> units;

  // process to calculate total number of units
  while (units >= 0) 
  {
    sum += units;
    cin >> units;
  } 
  //output
  cout << "Total = " << sum << endl;
}

/* calculates the number of '*' to be printed by dividing the production data by 1000 
 and rounding the number through roundNum function */
void numStarCalc(int production[], int num_factories)
{
  for (int i = 0; i < num_factories; i++)
  {
    production[i] = roundNum(production[i]/1000.0);
  }
}

// rounds down (floors) the total amount of production data  
int roundNum(double totalNum_unit) 
{
  return static_cast<int>(floor(totalNum_unit + 0.5));
}

// displays the final output- equivalent units of production by calling printUnit function
void finalOutput(const int num_stars[], int totalPlantNum)
{
  cout << "\nUnits produced in thousands of units:\n";

  for (int i = 1; i <= totalPlantNum; i++)
  {
    cout << "Factory #" << i << " ";

    printUnit(num_stars[i - 1]);
    cout << endl;
  }
}

// prints the amount of * needed to represent production units in thousands
void printUnit(int unitNum) 
{
  for (int count = 1; count <= unitNum; count++) 
  {  
    cout << "*";
  }
} 