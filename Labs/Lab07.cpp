//Create a Connect 4 Game
#include <iostream>
#include <string>

using namespace std;

//Global constants for the game pieces
const char EMP = '-';
const char P1 = 'X';
const char P2 = 'O';

//global variables/constants for the game board
const int COLS = 7;
const int ROWS = 6;
char board[COLS][ROWS]; //2D array of 7x6 connect 4 board

//Initialize the board to be empty
void initializeBoard();

//Display the board
void displayBoard();

//Get column for current move
int getColumn(bool isPlayer1);

//Add one piece to the Board
bool addPiece(int c, bool isPlayer1);

//Check if a given player has won
bool isWinner(bool isPlayer1, int lastCol);

int main() 
{
  //Initialize game
  //TO DO: Add code to randomize first player
  int totalMoves = 0; //number of moves by both players
  const int MAX_MOVES = COLS * ROWS; //total cells on the board
  bool playerOne = true; //boolean to keep track of current player
  bool gameWon = false; //boolean to keep track if game won
  int column = -1;

  initializeBoard();
  displayBoard();

  //Game play loop
  //loop until game is won or the board is full
  while ((!gameWon) && (totalMoves < MAX_MOVES)) 
  {
    bool validMove = false;

    while (!validMove) 
    {
      column = getColumn(playerOne);
      validMove = addPiece(column, playerOne);
      if (!validMove) 
      {
        cout << "Invalid move. Try again." << endl;
      }
    }

    totalMoves++;
    displayBoard();

    //Check if game is won
    gameWon = isWinner(playerOne, column);
    if (gameWon) 
    {
      cout << "CONGRATULATIONS Player " << (playerOne ? "1" : "2")
           << ". You've won Connect 4!!!!" << endl;
    } 
    else if (totalMoves == MAX_MOVES) 
    {
      cout << "Game over! No moves remaining." << endl;
    } 
    else 
    {
      playerOne = !playerOne; //switch player
    }
  }
  return 0;
}

void initializeBoard() {
  //Loops through each column
  for (int c = 0; c < COLS; c++) 
  {
    //Loop through each row in a given column
    for (int r = 0; r < ROWS; r++)
    {
      board[c][r] = EMP; //initialize all cells to empty
    }
  }
}

void displayBoard() 
{
  cout << endl << "Connect 4 Board:" << endl;
  //Display the board one row at a time
  for (int r = 0; r < ROWS; r++) 
  {
    //For each row display all of the columns
    for (int c = 0; c < COLS; c++) 
    {
      cout << board[c][r] << " ";
    }
    cout << endl; //After each row output a newline character
  }
  //Now display the column numbers below the board
  for (int c = 0; c < COLS; c++) 
  {
    cout << c << " ";
  }
  cout << endl << endl;
}

int getColumn(bool isPlayer1) 
{
  int col = 0;

  /*cout << "Player ";
  if (isPlayer1) {
    cout << "1";
  } else {
    cout << "2";
  }
  cout << " - Select a column [0," << (COLS-1) <<  "] to play: ";*/
  //The below is a short form of above output
  cout << "Player " << (isPlayer1 ? "1" : "2")
       << " - Select a column [0," << (COLS-1) <<  "] to play: ";
  cin >> col;
  return col;
}

bool addPiece(int c, bool isPlayer1) 
{
  if ((c < 0) || (c >= COLS)) 
  { //check if column is valid for board
    return false;
  }
  //check if column c has space
  if (board[c][0] == EMP) 
  {
    //add a piece to the lowest unoccupied row in column c
    for (int r = (ROWS-1); r >= 0; r--) 
    {
      if (board[c][r] == EMP) 
      {
        //add piece
        if (isPlayer1) 
        {
          board[c][r] = P1;
        } 
        else 
        {
          board[c][r] = P2;
        }
        return true;
      }
    }
  }
  //if column is full return false
  return false;
}

bool isWinner(bool isPlayer1, int lastCol) 
{
  //Identify which tile is used by current player
  char currTile;
  if (isPlayer1) 
  {
    currTile = P1;
  } 
  else 
  {
    currTile = P2;
  }

  //Check if current player has 4 vertical tiles in a row in the current column
  int counter1 = 0;
  for (int r = ROWS-1; r >= 0; r--) 
  {
    if (board[lastCol][r] == currTile) 
    {
      counter1++;
      if (counter1 == 4) 
      {
        return true;
      }
    } 
    else if (board[lastCol][r] == EMP) //an optimization to stop searching if no more tiles in columns
    {             
      break;                               
    }
    else 
    {
      counter1 = 0;
    }
  }

  //Alternative algorithm (for homework): 
  //First start at top of column and find row of last piece played
  //check if last piece player has three below it first
  //then check that piece and three below are same

  //Check if current player has 4 horizontal tiles in a row
  int counter2 = 0;
  for (int r = ROWS-1; r >= 0; r--) 
  {
    for (int c = COLS-1; c >= 0; c--)
    {
      if (board[c][r] == currTile) 
      {
        counter2++;
        if (counter2 == 4) 
        {
          return true;
        }
      } 
      else if (board[lastCol][r] == EMP) //an optimization to stop searching if no more tiles in columns
      {             
        break;                               
      }
      else 
      {
        counter2 = 0;
      }
    }
  }

  //Check if current player has 4 diagonal tiles in a row (\)
  //loops throught row and columns
  for (int c = COLS-1; c>=0; c--)
  {
    for (int r = ROWS-1; r >= 0; r--) 
    {
      //if currenttile has same symbol in a diagonal row 
      if (currTile==board[c][r] && currTile==board[c+1][r+1] && currTile==board[c+2][r+2] && currTile==board[c+3][r+3]) 
      {
        return true;
      } 
      /*else if (board[lastCol][r] == EMP) //an optimization to stop searching if no more tiles in columns
      { 
        break;                               
      } */
    }
  }

  //Check if current player has 4 diagonal tiles in a row (/)
  //loops throught row and columns
  for (int c = COLS-1; c>=0; c--)
  {
    for (int r = ROWS-1; r >= 0; r--) 
    {
      //if currenttile has same symbol in a diagonal row 
      if (currTile==board[c][r] && currTile==board[c+1][r-1] && currTile==board[c+2][r-2] && currTile==board[c+3][r-3]) 
      {
        return true;
      }
      else if (board[lastCol][r] == EMP) //an optimization to stop searching if no more tiles in columns
      { 
        break;                               
      }
    }
  }

  //otherwise no winner
  return false;

}
