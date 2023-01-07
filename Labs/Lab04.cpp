#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int dayNumber(int day, int month, int year) 
{ 
  /* Function returning the index of the day of the date: DD/MM/YYYY 
  Index	  DAY 
  0		    Sunday 
  1		    Monday 
  2		    Tuesday 
  3		    Wednesday 
  4		    Thursday 
  5		    Friday 
  6		    Saturday */

  //Tomohiko Sakamoto's algorithm for finding day of week
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
	year -= month < 3; 
	return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7; 
} 

string getMonthName(int monthNum) 
{ 
  /* Function returning the name of the month given the month number 

  Month Number	 NAME 
  0			         January 
  1			         February 
  2			         March 
  3			         April 
  4			         May 
  5			         June 
  6			         July 
  7			         August 
  8			         September 
  9			         October 
  10			       November 
  11			       December */

	string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 

	return (months[monthNum]); 
} 

int numberOfDays (int monthNumber, int year) 
{ 
  /* Function returning the number of days in a month 

  Month number	NAME	      Number of Days 
  1			        January	    31 
  2			        February    28 / 29 (leap) 
  3			        March	      31 
  4			        April	      30 
  5			        May		      31 
  6			        June	      30 
  7			        July	      31 
  8			        August	    31 
  9			        September   30 
  10			      October	    31 
  11			      November    30 
  12			      December    31  */

	// January 
	if (monthNumber == 1) 
		{
      return (31);
    } 

	// February 
	if (monthNumber == 2) 
	{ 
		// if given year is leap year 
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) 
		{
      return (29);
    }	 
		else
    {
      return (28);
    }			 
	} 

	// March 
	if (monthNumber == 3)
  {
    return (31);
  } 

	// April 
	if (monthNumber == 4) 
  {
    return (30);
  } 

	// May 
	if (monthNumber == 5) 
  {
    return (31);
  } 

	// June 
	if (monthNumber == 6) 
	{	
    return (30); 
  }

	// July 
	if (monthNumber == 7) 
  {
    return (31);
  } 

	// August 
	if (monthNumber == 8) 
	{
    return (31);
  } 

	// September 
	if (monthNumber == 9) 
  {
    return (30);
  } 

	// October 
	if (monthNumber == 10) 
	{
    return (31);
  } 

	// November 
	if (monthNumber == 11) 
	{
    return (30); 
  }	

	// December 
	if (monthNumber == 12) 
	{
    return (31); 
  }	
  return 0;
} 

void printMonth(int month, int year)
{
  cout << "\n\t\t  " << getMonthName(month-1) <<", "<< year << "\n";
  cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
	
  // get how many days has to be printed for the month given
  int days= numberOfDays (month, year); 

	// Index of the day from 0 to 6 
	int current = dayNumber (1, month, year); 

  int k=0; // variable for printing dates (1,2,3...)

	// i --> Iterate through all the rows (dates)
	// j --> Iterate through all the columns (days of week) 
  for (int i = 0; i < 6; i++)
  {
    if (i == 0)
    {
      // printing spaces on epmty the days of week in first row 
      for (int n = 0; n < current; n++)
      {
        cout << "     "; 
      }      
    }

    for (int j=current; j<7;j++)
    {
      cout << right << setw(3) << ++k << "  "; // right justify and print days
      current = 0;

      if (k == days)
      {
        break; // once last value of date is printed stop printing further dates
      }
    }
    
    // again, once last value of date is given stop printing dates (this is needed as after exiting previous loop next one continues)
    if (k == days)
    {
      break; 
    }

    cout <<"\n";
  }
  cout << "\n";
}

void printYear(int year)
{
  cout << "\n\t\t Calender - " << year <<"\n";

  // prints calenders of every month of the given year
  return printMonth(1, year), 
        printMonth(2, year), 
        printMonth(3, year), 
        printMonth(4, year), 
        printMonth(5, year), 
        printMonth(6, year), 
        printMonth(7, year), 
        printMonth(8, year), 
        printMonth(9, year), 
        printMonth(10, year), 
        printMonth(11, year), 
        printMonth(12, year);
}

int main() 
{
  string userchoice; //user input for displaying either month or year calender

  cout <<"Do you want a month calender only or a year calender? \nEnter 'm' for month calender and 'y' for year calender: ";
  cin >> userchoice;

  if (userchoice == "m")
  {
    int monthnum,year;

    cout << "\nWhich month calender do you wish to see?\nEnter in M format (e.g. 6 for June): ";
    cin >> monthnum;
    cout << "\nAnd which year? --> ";
    cin >> year;

    printMonth(monthnum, year);
  }
  else if (userchoice == "y")
  {
    int year;
    cout << "\nWhich year's calender do you wish to see? --> ";
    cin >> year;
    
    printYear(year);
  }
  return 0; 
}