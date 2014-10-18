//Program Name: Peg Solitaire Game
//Author (Student ID): w13003946
//Date: November (2013) - January (2014)
//Last Revision: 10/01/2014

//Purpose: To allow the user to play multiple games of Peg Solitaire
//Change: A random peg becomes immortal - it can be jumped over, but won't
//be removed from the board. It acts as a normal peg and can be moved over
//other pegs. A move counter has also been added



#include <iostream> //library used to access functions such as cin and cout
#include <time.h> //library used to seed srand, which is used in order to
                  //find a random immortal peg



using namespace std; //uses standard namespace



//Const & Struct Declarations
const int NUMCOLUMNS = 5; //the number of columns in the grid
const int NUMROWS = 5;	//the number of rows in the grid



//This subprogram fills the board initially
void MakeGrid(char Board[NUMROWS][NUMCOLUMNS] /*inout*/,
  char& pegSpace /*inout*/, bool& startNewGame /*inout*/)
{
  if (startNewGame == true) //if a new game is started
  {
    char Peg = 'O'; //the letter O is used as a peg
    for (int xCoord = 5; xCoord > 0; xCoord--) //filling the X coordinates
      //from row 5 (at the top)
      //to row 1 (at the bottom)
    {
      for (int yCoord = 1; yCoord < 6; yCoord++) //filling the Y coordinates
        //from column 1 (left) to
        //column 5 (right)
      {
        Board[xCoord][yCoord] = Peg; //both the X and Y coordinates in the for
        //loops will store a peg (O)
      }
    }
    Board[3][3] = pegSpace;
    //except the location 3,3 (centre) has a space
    //written to it (declared in 'main')
  }
}



//This subprogram shows the board once it is made
void ShowGrid(char Board[NUMROWS][NUMCOLUMNS]/*inout*/, char pegSpace /*in*/,
  int pegsRemaining /*in*/, int& highscore /*inout*/)
{
  cout << "\n" << endl; //drops down a line
  cout << "               Simple Solitaire " << endl;
  //displays the game's title center-aligned
  cout << "\n     Highscore: " << highscore;
  //outputs the current highscore left-aligned
  cout << "          Pegs Remaining: " << pegsRemaining;
  //outputs the number of current pegs remaining on the board
  //right-aligned
  cout << "\n\n\n\n";
  for (int xCoord = 5; xCoord > 0; xCoord--) //for loop displays the board 
    //using dashes and pipes - prints out the rows
  {
    if (xCoord == 5) //if loop displays a Y next to 5, or spaces instead
      //next to numbers instead
    {
      cout << "         Y  " << xCoord << " | "; //displays a Y, #
      //then a seperator
    }
    else
    {
      cout << "            " << xCoord << " | "; //or displays spaces, #
      //and a seperator
    }
    for (int yCoord = 1; yCoord < 6; yCoord++)
    {
      cout << Board[yCoord][xCoord] << "   ";
    } //end of Y Coordinate display loop
    if (xCoord != 1)
    {
      cout << "\n                           \n"; //prints a row of underscores
    }                                          //in between each line    
  }//end of X Coordinate display for loop
  cout << "\n              --------------------\n";
  cout << "                1   2   3   4   5   \n"; //prints X coordinates at
  //bottom
  cout << "\n                                X   \n"; //prints X label at the
  //bottom
}



//This subprogram takes the user's input of the X and Y coordinates and
//the direction the player wishes to move, works out the peg to be removed 
//and if the move is valid. If the user has selected the immortal peg, the
//moves of its new position are worked out (and the regular procedure is
//ignored.
void CalculateMoves(int& playerCoordinateX /*inout*/,
  int& newSpaceX /*inout*/,
  char directionToMove /*in*/, char Board[NUMROWS][NUMCOLUMNS]/*inout*/,
  int& playerCoordinateY /*inout*/, int& newSpaceY/*inout*/, 
  int& immortalX /*inout*/, int& immortalY /*inout*/)
{
  if (directionToMove == 'n' || directionToMove == 'N')
  { 
    //if the user inputted direction is N

  //---------------- X ----------------- 
    
    if (playerCoordinateX == immortalX)
    {
      immortalX = immortalX;
    }
    //the immortal peg's X coordinates are not changed, if the user has
    //selected it

    newSpaceX = playerCoordinateX;
    playerCoordinateX = playerCoordinateX;
    //no changes are made to the coordinates

  //---------------- Y ----------------- 

    if (playerCoordinateY == immortalY)
    {
      immortalY = immortalY + 2;
    }
    //the immortal peg's Y coordinate is moved two spaces up
    //if the user has selected it

    newSpaceY = playerCoordinateY + 1;
    //the peg to be deleted in one space up from the inputted peg
    playerCoordinateY = playerCoordinateY + 2;
    //the new peg coordinate is two spaces up from the inputted peg
  }
  else if (directionToMove == 'e' || directionToMove == 'E')
  { 
    //if the user inputted direction is E
    
  //---------------- X ----------------- 
    
    if (playerCoordinateX == immortalX)
    {
      immortalX = immortalX + 2;
    }
    //the immortal peg's X coordinate is moved two spaces right
    //if the user has selected it

    newSpaceX = playerCoordinateX + 1;
    //the deleted peg is one space more than the inputted peg
    playerCoordinateX = playerCoordinateX + 2;
    //the new coordinate is two spaces more than the inputted peg

  //---------------- Y ----------------- 

    if (playerCoordinateY == immortalY)
    {
      immortalY = immortalY;
    }
    //the immortal peg's Y coordinate is not changed, if the user has
    //selected it

    newSpaceY = playerCoordinateY;
    playerCoordinateY = playerCoordinateY;
    //no changes are made to the peg

  }
  else if (directionToMove == 'w' || directionToMove == 'W')
  { 
    //if the user inputted direction is W

  //---------------- X ----------------- 

    if (playerCoordinateX == immortalX)
    {
      immortalX = immortalX - 2;
    }
    //the immortal peg's X coordinate is moved two spaces left
    //if the user has selected it

    newSpaceX = playerCoordinateX - 1;
    //the deleted peg is one space less than the inputted peg
    playerCoordinateX = playerCoordinateX - 2;
    //the new coordinate is two spaces less than the inputted peg

  //---------------- Y ----------------- 

    if (playerCoordinateY == immortalY)
    {
      immortalY = immortalY;
    }
    //the immortal peg's Y coordiante is not changed, if the user has
    //selected it
    
    newSpaceY = playerCoordinateY;
    playerCoordinateY = playerCoordinateY;
    //no changes are made to the peg
  }
  else if (directionToMove == 's' || directionToMove == 'S')
  { 
    //if the user inputted direction is S

  //---------------- X ----------------- 

    if (playerCoordinateX == immortalX)
    {
      immortalX = immortalX;
    }
    //the immortal peg's X coordinate is not changed, if the user has
    //selected it

    newSpaceX = playerCoordinateX;
    playerCoordinateX = playerCoordinateX;
    //no changes are made to the pegs
    
  //---------------- Y -----------------  
     
    if (playerCoordinateY == immortalY)
    {
      immortalY = immortalY - 2;
    }
    //the immortal peg's Y coordinate is moved two spaces down,
    //if the user has selected it

    newSpaceY = playerCoordinateY - 1;
    //the peg to be deleted is one space down from the peg inputted
    playerCoordinateY = playerCoordinateY - 2;
    //the new peg location is two spaces down from the peg inputted
  }
}



//This subprogram validates user moves
void MoveValidation(char Board[NUMROWS][NUMCOLUMNS] /*inout*/,
  int playerCoordinateX /*in*/,
  int playerCoordinateY /*in*/, int newSpaceX /*in*/,
  int newSpaceY /*in*/, bool& makeAMove /*inout*/,
  bool& validMove /*inout*/,
  int lastMoveX/*in*/, int lastMoveY/*in*/)
{
  if (Board[lastMoveX][lastMoveY] == ' ')
  { 
    //if the last move (i.e. the original user coordinates) is
    //a space:
    cout << "~~~ Error 0 - there is no peg to start with" << endl;
    //output error 0 as there is no peg to start with
    makeAMove = true; //return the user to the move making stage
    validMove = false;  //set to invalid move
  }
  else if (Board[newSpaceX][newSpaceY] != 'O')
  { 
    //if the peg that is to be deleted is not a peg (is a space instead):
    cout << "~~~ Error 1 - there is no peg to jump over" << endl;
    //output error 1 as there is no peg to jump over
    makeAMove = true; //returns user to move making stage
    validMove = false;  //set to invalid move
  }
  else if (playerCoordinateX < 0 || playerCoordinateX > 5
    || playerCoordinateY < 0 || playerCoordinateY > 5
    || newSpaceX < 0 || newSpaceX > 5 ||
    newSpaceY < 0 || newSpaceY > 5)
  { 
    //if the new coordinates or deleted peg coordinates are not within
    //the range of 1 to 5 (the original coordinates are dealt with in
    //the main subprogram):
    cout << "~~~ Error 2 - a peg will move off the board" << endl;
    //output error 2 as a peg would move off the board and the array
    //would break
    makeAMove = true; //returns user to move making stage
    validMove = false;  //set to invalid move
  }
  else if (Board[playerCoordinateX][playerCoordinateY] == 'O')
  { 
    //if the new coordinates already have an O (a peg) in:
    cout << "~~~ Error 3 - a peg already occupies this space!" << endl;
    //output error 3 as a peg already exists in the selected location
    makeAMove = true; //returns user to move making stage
    validMove = false;  //set to invalid move
  }
}



//This subprogram updates the user inputted moves on the board after
//the program has validated the user's moves
void UpdateMoves(char Board[NUMROWS][NUMCOLUMNS], int& playerCoordinateX,
  int& playerCoordinateY, int& newSpaceX,
  int& newSpaceY, int& lastMoveX, int& lastMoveY,
  bool& validMove,  int& immortalX,
  int& immortalY) /*all are inout*/
{
  Board[playerCoordinateX][playerCoordinateY] = 'O';
  //the new coordinates have a peg (O) inserted
  Board[newSpaceX][newSpaceY] = ' ';
  //the deleted coordinates have a space inserted to mark deletion
  Board[lastMoveX][lastMoveY] = ' ';
  //the last move's coordinates also have a space inserted to mark deletion
  Board[immortalX][immortalY] = 'O';
  //the immortal peg cannot be deleted and is therefore always displayed with
  //a peg
}



//This subprogram handles the highscore main menu option
void DisplayHighscores(int& currentScore, int& highscore) /*both inout*/
{
  cout << "\nThe last score was: " << currentScore << endl; //prints line
  cout << "You need " << highscore - currentScore;
  //works out how many points the user needs in order to beat the highscore
  cout << " points to set a new record!" << endl; //prints line
  //the user is alerted of the last score of the last played game, and how
  //many points extra were required to beat it (the last game's score is
  //subtracted from the current highscore
  cout << "The current highscore is: " << highscore << "\n" << endl;
  //prints out current highscore
}



//This subprogram displays the rules to the player using cout
void DisplayRules() //no parameters are used in this subprogram
{ 
  //when the rules subprogram is run, these lines are printed:
  cout << "\nHow To Play:\n" << endl;
  cout << "> The aim of the game is to move pegs around the board";
  cout << ", jumping over and removing other pegs until no more can";
  cout << " be removed. \n\n";
  cout << "> The game starts on a 5x5 board with 24 pegs. The centre slot";
  cout << " (peg 3,3) is empty. The user must select a peg to move to this";
  cout << " position, which deletes the peg jumped over. Two spaces will now";
  cout << " be vacant. \n\n";
  cout << "> A peg cannot be moved on top of another peg, but must jump over";
  cout << " and delete a peg. Pegs cannot also not be moved off the board.";
  cout << " You cannot start in a space - to start a move, there";
  cout << " must be a peg in the space! Finally, one peg will be immortal. ";
  cout << "This peg can be jumped over, but will not be removed from the";
  cout << " board. It can also jump over other peg as normal\n\n";
  cout << "> You will be asked to select an X coordinate (along the bottom)";
  cout << " and a Y coordinate (up the sides), as well as a compass direction";
  cout << ": North, South, East or West. You cannot move diagonally. The ";
  cout << "bottom left coordinate is 1,1 and the top right is 5,5.\n\n";
  cout << "> You will then be asked to confirm your move. Press Y to confirm";
  cout << " or press Q to choose another set of coordinates.\n\n";
  cout << "> Entering 0,0 as a coordinate will end the game and display your";
  cout << " score. A confirmation message will appear if this happens, so you";
  cout << " can change your coordinates if you do not wish to end your game.";
  cout << " If the game is ended, you may have set a new highscore. To check";
  cout << " how many points are required in order to set a new one, select";
  cout << " the highscore option (option 2) from the main menu.\n\n\n";
  //The lines appear in seperate bulleted paragraphs by using the new line
  //escape sequence. These lines instruct the user on the basics of Peg
  //Solitaire, how to play the game and how to use the program
}



//This subprogram is the very first run and asks the player whether they need
//to see the rules or not
void IntroductionToGame(bool& gameActive, bool& startNewGame, bool& makeAMove)
  //all parameters are inout
{
  bool validChar = false; //used to determine inputted character
  char userInput = '\0'; //the letter that the user inputs
  cout << "Welcome to Simple Solitaire!" << endl; //prints out line
  cout << "Would you like to read the instructions?"; //prints out line
  cout << " (Y/N): "; //prints out next to input
  cin >> userInput; //user inputs choice
  if (userInput == 'y' || userInput == 'Y')
  { //if the user inputs Y or y
    validChar = true; //the letter is allowed
    DisplayRules(); //the rules are displayed
  }
  else if (userInput == 'n' || userInput == 'N')
  { //if the user inputs N or n
    validChar = true; //the letter is allowed
  }
  while (validChar == false) //while the letter is not valid/allowed
  {
    cout << "Please input 'Y' if you need the rules or 'N' if you don't";
    cout << "\n"; //prints out instructions
    cin >> userInput;
    if (userInput == 'y' || userInput == 'Y')
    { //if the user enters Y or y, the rules are shown and loop is broken
      DisplayRules();
      break;
    }
    else if (userInput == 'n' || userInput == 'N')
    { //if the user inputs N or n, no rules are displayed and the loop is
      //broken
      break;
    }
  }
}



//This subprogram contains the game
void PlayTheGame(char Board[NUMROWS][NUMCOLUMNS], char pegSpace,
  bool& startNewGame, int& pegsRemaining, bool& validMove,
  bool& gameActive, int& playerCoordinateX,
  int& playerCoordinateY, int& lastMoveX, int& lastMoveY,
  bool& makeAMove, int& newSpaceX, int& newSpaceY,
  char& inputKey, char& directionToMove, int& currentScore,
  int& highscore, int& moveCounter, int& immortalX,
  int& immortalY)
  //all are 'inout' except pegSpace
{
  while (gameActive == true)
  { //while the game is being played
    MakeGrid(Board, pegSpace, startNewGame); //the board is generated
    ShowGrid(Board, pegSpace, pegsRemaining, highscore);
    //the board and UI is
    //shown
    while (makeAMove == true)
    { //while the player is making a move
      validMove = true; //valid move reset to true
      cout << "\nWhat move would you like to make?" << endl;
      //asks user to input a move
      cout << "X: ";
      cin >> playerCoordinateX; //X coordinate is inputted first
      while (!cin >> playerCoordinateX)
      { //if the input is invalid - e.g. a letter is inputted
        cin.clear();  //the input stream is cleared
        cin.ignore(999, '\n'); //all input is discarded
        cout << "Please enter a valid X coordinate: " << endl;
        cin >> playerCoordinateX; //a valid input must be used
      }
      cout << endl; //a new line is started
      if (playerCoordinateX < 0 || playerCoordinateX > 5)
      { //if coordinates are not between 1 and 5, then error is printed out
        cout << "Error 2 - X Coordinate is off the board"; //error message
                                                           //is displayed and
        cout << endl;                                      //a new line printed
        cout << "Please enter a valid coordinate: ";
        cin >> playerCoordinateX; //user asked to re-enter X coordinate
        while (!cin >> playerCoordinateX)
        { //if the input is invalid - e.g. a letter is inputted
          cin.clear();  //the input stream is cleared
          cin.ignore(999, '\n'); //all input is discarded
          cout << "Please enter a valid X coordinate: " << endl;
          cin >> playerCoordinateX; //a valid input must be used
        }
      }
      cout << "Y: ";
      cin >> playerCoordinateY; //the user then inputs the Y coordinate
      while (!cin >> playerCoordinateY)
      { //if the input is invalid - e.g. a letter is inputted
        cin.clear();  //the input stream is cleared
        cin.ignore(999, '\n'); //all input is discarded
        cout << "Please enter a valid Y coordinate: " << endl;
        cin >> playerCoordinateY; //a valid input must be used
      }
      cout << endl; //a new line is printed
      if (playerCoordinateY < 0 || playerCoordinateY > 5)
      { //if coordinates are not between 1 and 5, then error is printed out
        cout << "Error 2 - Y Coordinate is off the board"; //error message is
                                                           //printed out
        cout << "\nPlease enter a valid coordinate: ";
        cin >> playerCoordinateY; //user asked to re-enter the Y coordinate
        while (!cin >> playerCoordinateY)
        { //if the input is invalid - e.g. a letter is inputted
          cin.clear();  //the input stream is cleared
          cin.ignore(999, '\n'); //all input is discarded
          cout << "Please enter a valid X coordinate: " << endl;
          cin >> playerCoordinateX; //a valid input must be used
        }
        cout << endl; //prints out new line
      }

      if (playerCoordinateX == 0 && playerCoordinateY == 0)
      { //if 0,0 is input, the game is stopped
        cout << "The game will be stopped... are you sure?" << endl;
        cout << "Y/N: "; //user asked to confirm exit
        cin >> inputKey; //user inputs Y or N to stop game
        if (inputKey == 'y' || inputKey == 'Y')
        { //if y or Y is input and game is stopped
          gameActive = false; //game loop ends
          startNewGame = false; //resets new game variable
          makeAMove = false;  //move making ends

          //Final Score Calculator
          if (pegsRemaining > 8)
          { //if 9 or more pegs remain, score is 0
            currentScore = 0;
          }
          else if (pegsRemaining == 8)
          { //if 8 pegs remain, score is 10
            currentScore = 10;
          }
          else if (pegsRemaining == 7)
          { //if 7 pegs remain, score is 20
            currentScore = 20;
          }
          else if (pegsRemaining == 6)
          { //if 6 pegs remain, score is 30
            currentScore = 30;
          }
          else if (pegsRemaining == 5)
          { //if 5 pegs remain, score is 40
            currentScore = 40;
          }
          else if (pegsRemaining == 4)
          { //if 4 pegs remain, score is 50
            currentScore = 50;
          }
          else if (pegsRemaining == 3)
          { //if 3 pegs remain, score is 60
            currentScore = 60;
          }
          else if (pegsRemaining == 2)
          { //if 2 pegs remain, score is 70
            currentScore = 70;
          }
          else if (pegsRemaining == 1)
          { //if 1 peg remains, score is 80
            currentScore = 80;
          }
          if (Board[3][3] == 'O' && pegsRemaining == 1)
          { //if one peg is the centre hole (3,3) remains, score is
            //80 with a 20 point bonus (totalling 100)
            currentScore = currentScore + 20;
            cout << "Congratulations, you performed the expert finish";
            cout << " and receive an extra 20 points!" << endl;
            //prints out congratulatory message

          }
          //Score displayer
          cout << "\nYour final score is: " << currentScore << "!" << endl;
          //final score is printed
          if (currentScore > highscore)
          { //if the score from the completed game is higher than the current
            //highscore...
            highscore = currentScore; //...then the highscore is replaced
            cout << "Congratulations! You've set a new high ";
            cout << "score!" << endl;
            //congratulatory message is printed
          }
          cout << "You made " << moveCounter << " moves!\n\n";
          //prints how many moves the user made throughout the game
          break; //breaks from Y input
        }
        else if (inputKey == 'n' || inputKey == 'N')
        { //if the inputted key is n or N
          cout << "Please change your coordinates -" << endl;
          //user is asked to change coordinate
          cout << "X: ";
          cin >> playerCoordinateX; //new X coordinate is inputted
          cout << endl; //new line is printed
          cout << "Y: ";
          cin >> playerCoordinateY; //new Y coordinate is inputted
          cout << endl; //new line is printed
        }
        else
        { //if neither Y or N is inputted, then the user is asked to
          //input a valid key (Y or N)
          cout << "Please input Y or N:" << endl;
          cin >> inputKey; //user can input another key
        }
      } //if for 0,0 is ended

      if (playerCoordinateX == immortalX && playerCoordinateY == immortalY)
      {
        cout << "\nYou have selected the immortal peg!" << endl;
        cout << "This peg can jump over others, but if jumped over, will ";
        cout << "not be removed from the board" << endl;
        //Guidelines tell the player that they have selected the immortal peg
        //and gives brief instructions on what that is
      }      

      {
        cout << "In which direction: N, E, S or W?" << endl;
        cin >> directionToMove;
        cout << endl;
        if (directionToMove == 'n' || directionToMove == 'N' || //if N, E,
          directionToMove == 'e' || directionToMove == 'E' ||   //S or W are
          directionToMove == 's' || directionToMove == 'S' ||   //inputted
          directionToMove == 'w' || directionToMove == 'W')
        {
          lastMoveX = playerCoordinateX; //the last moves are stored so
          lastMoveY = playerCoordinateY; //new peg coordinates can be
        }                                //calculated
        while (directionToMove != 'n' && directionToMove != 'N' && //while N,
          directionToMove != 'e' && directionToMove != 'E' &&  // E, S or W are
          directionToMove != 's' && directionToMove != 'S' &&  //not inputted
          directionToMove != 'w' && directionToMove != 'W')
        { //if a user inputs an invalid direction, then the user is asked to
          //enter a new one
          cout << "Please enter a valid direction: ";
          cin >> directionToMove;
          cout << "\n"; //a new line is printed
          if (directionToMove == 'n' || directionToMove == 'N' || //if N, E,
            directionToMove == 'e' || directionToMove == 'E' ||  //S or W are
            directionToMove == 's' || directionToMove == 'S' ||  //inputted
            directionToMove == 'w' || directionToMove == 'W')
          {
            lastMoveX = playerCoordinateX; //the last moves are stored so
            lastMoveY = playerCoordinateY; //new peg coordinates can be
                                           //calculated
            break; //the invalid loop is broken
          }

        }

        cout << "So, you want peg " << lastMoveX << "," << lastMoveY;
        cout << " to move "; //the user is asked to confirm his/her move
        if (directionToMove == 'n' || directionToMove == 'N')
        { //if the user input 'N', sentence is finished with 'up?'
          cout << "up?" << endl;
        }
        else if (directionToMove == 'e' || directionToMove == 'E')
        { //if the user input 'E', sentence is finished with 'right?'
          cout << "right?" << endl;
        }
        else if (directionToMove == 'w' || directionToMove == 'W')
        { //if the user input 'W', sentence is finished with 'left?'
          cout << "left?" << endl;
        }
        else if (directionToMove == 's' || directionToMove == 'S')
        { //if the user input 'S', sentence is finished with 'down?'
          cout << "down?" << endl;
        }
        cout << "If so, press 'Y' or press 'Q' to choose again:" << endl;
        //Confirmation of move message is prompted
        cin >> inputKey; //the user is asked to input a letter
        cout << "\n" << endl; //a new line is printed and ended
        if (inputKey == 'y' || inputKey == 'Y')
        { //if the user inputs 'Y'
          makeAMove = false; // move is accepted and calculated
        }
        else if (inputKey == 'q' || inputKey == 'Q' ||
          inputKey == 'n' || inputKey == 'N')
        { //if the user inputs 'Q' or 'N' (as a force of habit)
          makeAMove = false;
          makeAMove = true; //loop is reset so a new move can be made
          ShowGrid(Board, pegSpace, pegsRemaining, highscore);
        }
        else
        {
          cout << "Please enter a valid key: ";
          cin >> inputKey;
          if (inputKey == 'y' || inputKey == 'Y')
          { //if the user inputs 'Y'
            makeAMove = false; // move is accepted and calculated
          }
          else if (inputKey == 'q' || inputKey == 'Q')
          { //if the user inputs 'Q'
            makeAMove = false;
            makeAMove = true; //loop is reset so a new move can be made
          }
        }
      }//Make A Move loop ends -------- Moves end

      while (makeAMove == false) //---- Calculations start
      {
        CalculateMoves(playerCoordinateX, newSpaceX,
          directionToMove, Board, playerCoordinateY, newSpaceY,
          immortalX, immortalY);
        //The player's new X Coordinate is calculated
        //as is the peg to be removed

        MoveValidation(Board, playerCoordinateX, playerCoordinateY,
          newSpaceX, newSpaceY, makeAMove, validMove,
          lastMoveX, lastMoveY);  //The move is checked to make sure it is
                                  //valid. If not, a message is displayed

        while (validMove == true)
        { //while the move has been validated and is allowed
          UpdateMoves(Board, playerCoordinateX,
            playerCoordinateY, newSpaceX, newSpaceY,
            lastMoveX, lastMoveY, validMove, immortalX,
            immortalY); //if the move is valid, the
                                              //board is updated
          pegsRemaining--;  //the number of pegs is decreased by 1
          moveCounter++; //increases the number of moves the user has made
          validMove = false; //bool reset to false again
        }
        ShowGrid(Board, pegSpace, pegsRemaining, highscore);//the updated board
        //is then printed
        makeAMove = true; //a new move can now be made
      }//Calculations end
    }//GameActive loop ends 
  }//StartNewGame ends
}//PlayTheGame subprogram ends



//This subprogram displays the main menu and handles the player's choice
void ShowMenu(bool& gameActive, bool& startNewGame, bool& makeAMove,
  char Board[NUMROWS][NUMCOLUMNS], char pegSpace,
  int& currentScore, int& highscore, int pegsRemaining,
  bool validMove, int playerCoordinateX,
  int playerCoordinateY, int lastMoveX, int lastMoveY,
  int newSpaceX, int newSpaceY, char inputKey,
  char directionToMove, int& moveCounter, int& immortalX,
  int& immortalY)
  //gameActive, startNewGame, makeAMove, Board
  //highscore and moveCounter are 'inout'. 
  //The rest of the parameters are 'in'.
{
  int menuInput = '\0'; //menu input set to null
  //menu is then printed out:
  cout << "\n------- MENU -------\n" << endl;
  cout << "1) Play Game" << endl;
  cout << "2) View Highscore" << endl;
  cout << "3) View Rules" << endl;
  cout << "4) Exit Game" << endl;
  cout << "Option: ";
  cin >> menuInput; //user asked to input a number
  if (!cin >> menuInput)
  { //if the input is invalid - e.g. a letter is inputted
    cin.clear();  //the input stream is cleared
    cin.ignore(999, '\n'); //all input is discarded
    cout << "Please enter a valid menu option: " << endl;
    cin >> menuInput; //a valid input must be used
  }
  switch (menuInput)
  { //this switch statement checks the input
  case 1:
    gameActive = true; //starts the game loop
    startNewGame = true;  //starts a new game
    makeAMove = true; //starts the move making stage
    PlayTheGame(Board, pegSpace, startNewGame, pegsRemaining, validMove,
      gameActive, playerCoordinateX, playerCoordinateY, lastMoveX,
      lastMoveY, makeAMove, newSpaceX, newSpaceY,
      inputKey, directionToMove, currentScore, highscore, moveCounter,
      immortalX, immortalY);
    //runs the game subprogram
    break;  //breaks from switch statement
  case 2:
    DisplayHighscores(currentScore, highscore);
    //runs highscore subprogram
    break;  //breaks from switch statement
  case 3:
    DisplayRules(); //runs rules subprogram
    break;  //breaks from switch statement
  case 4:
    exit(0);  //runs successful exit function
    break; //breaks from switch statement
  default:
    cout << "Please enter a valid menu input!" << endl;
    //asks user to enter a valid input
  }
}



//This subprogram is the main program, essentially attaching all other
//subprograms and variables together
void main()
{
  //Variable Declarations-----------------------------------------------------
  srand((unsigned)time(NULL)); //generates a random seed based on system time
  bool gameActive = false; //the game is active if true
  bool makeAMove = false; //a move is being made if true. if false,
                          //a move is being calculated
  bool validMove = true; //a move is valid if true
  bool startNewGame = true; //used to stop game being continued once stopped
  char Board[NUMROWS][NUMCOLUMNS]; //array to store Os and spaces
                                   //and display as a grid
  char pegSpace = ' '; //the character of a space in the5 game
  char directionToMove = '\0'; //user inputted direction to mover (NEWS)
  char inputKey = '\0'; //char to store user input key
  int pegsRemaining = 24; //integer to store peg remaining
  int playerCoordinateX = '\0'; //X coordinate the user
                                //chooses. Converted into new location
  int newSpaceX = '\0'; //integer to work out which peg is skipped over
                        //and deleted on the X axis
  int lastMoveX = '\0'; //integer to store the original user X coordinates
  int playerCoordinateY = '\0'; //X coordinate the user
                                //chooses. Converted into new location
  int newSpaceY = '\0'; //Y coordinate of the deleted peg
  int lastMoveY = '\0'; //the original user Y coordinates
  int highscore = 0; //the game's highest score
  int currentScore = 0; //the game's current score
  int immortalX = rand()% 5+1; //the X coordinate of immortal peg
  int immortalY = rand()% 5+1; //the Y coordinate of immortal peg
  int moveCounter = 0; //number of moves made in the current game
  


  IntroductionToGame(gameActive, startNewGame, makeAMove);
  //the game starts and introduction is run
  ShowMenu(gameActive, startNewGame, makeAMove, Board, pegSpace, currentScore,
    highscore, pegsRemaining, validMove, playerCoordinateX,
    playerCoordinateY, lastMoveX, lastMoveY, newSpaceX,
    newSpaceY, inputKey, directionToMove, moveCounter,
    immortalX, immortalY);
  //menu is then run
  PlayTheGame(Board, pegSpace, startNewGame, pegsRemaining, validMove,
    gameActive, playerCoordinateX, playerCoordinateY, lastMoveX,
    lastMoveY, makeAMove, newSpaceX, newSpaceY,
    inputKey, directionToMove, currentScore, highscore, moveCounter,
    immortalX, immortalY);
  //the game then starts - this subprogram handles all gameplay

  while (gameActive == false)
  { //while the game loop is false (the game is not running)
    ShowMenu(gameActive, startNewGame, makeAMove, Board, pegSpace, 
      currentScore, highscore, pegsRemaining, validMove, playerCoordinateX,
      playerCoordinateY, lastMoveX, lastMoveY, newSpaceX,
      newSpaceY, inputKey, directionToMove, moveCounter,
      immortalX, immortalY);
    //the menu is displayed so the user can make a choice
  }//while loop ends
}//Mains ends