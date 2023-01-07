#include <iostream> 
#include <string> 
using namespace std; 

int main() 
{ 
  const int COLS = 6; 
  const int ROWS = 6; 
  char array[COLS][ROWS]; 
  
  for (int c = 0; c < COLS; c++) 
  { 
    for (int r = 1; r < ROWS; r += 2) 
    { 
      array[c][r] = 'X'; 
    } 
  } 
  
  for (int c = 0; c < COLS; c++) 
  { 
    for (int r = 0; r < ROWS; r += 2) 
    { 
      array[c][r] = 'Y'; 
    } 
  } 
  
  for (int r = 0; r < ROWS; r++) 
  { 
    for (int c = 0; c < COLS; c++) 
    { 
      cout << array[c][r] << " "; 
    } 
    
    cout << endl; 
    
  } return 0; 
}
