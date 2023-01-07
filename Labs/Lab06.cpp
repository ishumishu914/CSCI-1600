#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int SIZE = 3;
void displayBoard(string b[][SIZE]);
bool userFirst();
bool currentPlayerWon(string b[][SIZE], string symbol);
void generateComputerMove(string b[][SIZE]);

int main() 
{
  //construct board
  string board[SIZE][SIZE];

  int position_id = 1;
  for (int i=0; i< SIZE; i++) 
  {
    for (int j=0; j < SIZE; j++) 
    {
      board[i][j] = to_string(position_id);
      /* stringstream ss;
      ss << position_id;
      board[i][j] = ss.str(); */
      position_id++;
    }
  }

  //Initial game output
  cout << "Welcome to Tic-Tac-Toe" << endl;

  bool userTurn = userFirst();
  if (userTurn == true) 
  {
    cout << "Player goes first!" << endl;
  } 
  else 
  {
    cout << "Computer goes first!" << endl;
  }

  //Loop for turn taking in game
  int positionsRemaining = SIZE * SIZE;
  bool userWon = false;
  bool computerWon = false;

  while ((positionsRemaining > 0) && (!userWon) && (!computerWon)) 
  {
    displayBoard(board);

    //User's turn
    if (userTurn) 
    {
      bool validMove = false;

      while (!validMove) 
      {
        int position_id;
        cout << "Enter a position: ";
        cin >> position_id;

        if ((position_id <= (SIZE*SIZE)) && (position_id > 0)) 
        {
          int row = (position_id - 1) / SIZE;
          int col = (position_id - 1) % SIZE;

          //cout << "row = " << row << " col = " << col << endl;
          if ((board[row][col] != "X") && (board[row][col] != "O")) 
          {
            board[row][col] = "X";
            validMove = true;
          } 
          else 
          {
            cout << "Position already used. Try again." << endl;
          }
        } 
        else 
        {
          cout << "Position invalid. Try again." << endl;
        }
      }
      positionsRemaining--;
      userWon = currentPlayerWon(board, "X");
      userTurn = false;
    }

    //Computer's turn
    else 
    {
      generateComputerMove(board);
      positionsRemaining--;
      computerWon = currentPlayerWon(board, "O");
      userTurn = true;
    }
  }

  //Display game result
  displayBoard(board);
  if (userWon) 
  {
    cout << "Congratulations! You have won!" << endl;
  } 
  else if (computerWon) 
  {
    cout << "The computer has won. Try again." << endl;
  } 
  else 
  {
    cout << "Out of moves. Try again." << endl;
  }
  return 0;
}

void displayBoard(string b[][SIZE]) 
{
  cout << "Tic-tac-toe board:" << endl << endl;

  for (int i=0; i< SIZE; i++) 
  {
    for (int j=0; j < SIZE; j++) 
    {
      cout << b[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

bool userFirst() 
{
  //set seed for random number generation
  srand(time(NULL));

  //generate a random number
  //0 for computer
  //1 for user
  int num = rand() % 2;
  if (num == 0) 
  {
    return false;
  }
  return true;
}

//Return true if player/computer with symbol (X or O) has won
bool currentPlayerWon(string b[][SIZE], string symbol) 
{
  //Horizontal case - Loop through each row
  for (int i=0; i < SIZE; i++) 
  {
    bool rowWinDetected = true;
    //Check all positions in row and see if they are the same symbol
    for (int j = 0; j < SIZE; j++) 
    {
      if (b[i][j] != symbol) 
      {
        rowWinDetected = false;
      }
    }
    if (rowWinDetected) 
    {
      return true;
    }
  }

  //Vertical case - Loop through each column
  for (int i=0; i < SIZE; i++) 
  {
    bool colWinDetected = true;
    //Check all positions in column and see if they are the same symbol
    for (int j = 0; j < SIZE; j++) 
    {
      if (b[j][i] != symbol) 
      {
        colWinDetected = false;
      }
    }
    if (colWinDetected) 
    {
      return true;
    }
  }

  //Diagonal case #1
  bool diagonal1WinDetected = true;
  for (int i=0; i < SIZE; i++) 
  {
    if (b[i][i] != symbol) 
    {
      diagonal1WinDetected = false;
    }
  }
  if (diagonal1WinDetected) 
  {
    return true;
  }

  //Diagonal case #2
  bool diagonal2WinDetected = true;
  for (int i=0; i < SIZE; i++) 
  {
    if (b[(SIZE-1)-i][i] != symbol) 
    {
      diagonal2WinDetected = false;
    }
  }
  if (diagonal2WinDetected) 
  {
    return true;
  }

  //otherwise win not diagonal2WinDetected
  return false;
}

void generateComputerMove(string b[][SIZE])
{  //Horizontal case

  //bool to check if computer move is valid 
  bool validMove = false;
  //loops through rows 
  for (int i=0; i < SIZE; i++)
  {
    //loops through columns
    for (int j=0; j < SIZE; j++)
    { 
      //variable to count number used spaces in a Horizontal  line
      int count_horizontal = 0;
      
      if ((b[i][j] == "X") || (b[i][j] == "O"))
      {
        //if a space is used with either X or O add one to count
       count_horizontal++;        
      } 

      //when count_horizontal == 2 and space is not occupied 
      else if ((count_horizontal == 2) && (b[i][j] != "X") && (b[i][j] != "O"))
      {
         //computer occupies space where there are two X's
        b[i][j] = "O";
        validMove = true;
        break;    
        count_horizontal++;
      } 
      
    }
    //loop breaks once computer enters a valid move 
    if (validMove == true)
    {
      break;
    }
  }

  if (validMove == false)
  {
    //Vertical case

    //loops through rows and columns 
    for (int i=0; i < SIZE; i++)
    {
      for (int j=0; j < SIZE; j++)
      {
        //variable to count number used spaces in a Vertical line
        int count_vertical = 0;
        
        if ((b[j][i] == "X") || (b[j][i] == "O"))
        { 
          //if a space is used with either X or O add one to count
          count_vertical++;        
        }
        //when count_vertical == 2 and space is not occupied 
        else if ((count_vertical == 2) && (b[j][i] != "X") && (b[j][i] != "O"))
        { 
          //computer occupies space where there are two player moves to block player 
          b[j][i] = "O";
          validMove = true;
          break;  
        }       
      }
      //loop breaks once computer enters a valid move 
      if (validMove == true)
      {
        break;
      }
    }
  }

  if (validMove == false)
  { //Diagonal 

    //loops through rows
    for (int i=0; i < SIZE; i++) 
    {
      //variable to count number used spaces in a diagonal line
      int count_diagonal = 0;

      if ((b[(SIZE-1)-i][i] == "X") || (b[(SIZE-1)-i][i] == "O")) 
      {
        //if a space is used in a diagonal line with either X or O add one to count
         count_diagonal++;  
      }  

       //when count_diagonal == 2 and last space in a diagonal line is not occupied 
      else if ((count_diagonal == 2) && (b[(SIZE-1)-i][i] != "X") && (b[(SIZE-1)-i][i] != "O"))
      { 
        //computer occupies space where there are two player moves to block player 
        b[(SIZE-1)-i][i] = "O";
        validMove = true;
        break;  
      }
    }  
  }
//if validMove is false computer will occupy a random space 
  if (validMove == false)
  {
    //loop through rows 
    for (int i=0; i < SIZE; i++)
    {
      //loop through colums 
      for (int j=0; j < SIZE; j++)
      {
        //if a space is not occupied by "X" or "O"
        if ((b[i][j] != "X") && (b[i][j] != "O"))
        {
          //Computer will occupy space 
          b[i][j] = "O";
          validMove = true;
          break;
        }
      }
      if (validMove == true)
      {
        break;
      } 
    }
  }
}