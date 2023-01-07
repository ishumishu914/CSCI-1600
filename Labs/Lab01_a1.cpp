#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    //Activity 1

    //variable declarations & inputs
    string name;    //getting user's name
    cout << "Enter name: "; 
	cin >> name;

    int year;   //getting user's birth year
    cout << "Enter birth year: ";
    cin >> year;
    
    double wage;    //getting desired hourly wage
    cout << "Enter hourly wage($): ";
    cin >> wage;
    cout << fixed << setprecision(2);

    //age calculation
    int age = 2020-year;

    //output
    cout << name << " is " << age << " years old " << " and requests an hourly wage of $" << wage << "." << endl;

    return 0;
}