// gamespace.h
// game specific types and functions
// game: cops and robbers

#ifndef _GAMESPACE
#define _GAMESPACE


#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

namespace GameSpace
{

//*****************************************************************************  
// Named constants  

  const string TESTOUTFILE = "tests.out";
  const string MOVE_FILE = "move.out";

  const string AGENTARSENAL_FILE = "agent_arsenal.in";
  const string DICE_FILE = "dice.in";
  const string ENCOUNTER_FILE = "encounters.in";
  const string BOARD_FILE = "grid.in";
  const string MELEE_WPNS_FILE = "melee.in";
  const string RANGE_WPNS_FILE = "range.in";
  const string RANKRULES_FILE = "rank.in";


  const int NUMROWS = 5;
  const int NUMCOLS = 6;
  const bool KEYBD = true;
//  int TestMove = 0;
    
  const string LINE1 = "*************************************************\n";    
  const char DEL = '#';
  

//*****************************************************************************  
// Function manipulating string  

  string Ucase(string str);
  // Converts str to uppercase
  // pre: str is a string
  // post: returns the uppercase version of str
  
  string TrimStr(string str);
  // Trims leading and trailing whitespace and removes extra
  //    whitespace in the middle
  // pre: str is a string
  // post: returns the trimmed string

  bool Cmp(string s1, string s2);
  // Compares 2 strings(non-case sensitive) to determine sorted order
  // pre:
  // post: returns true if s1<=s2

  void Sort(vector<string>& vec);
  // Sorts a vector of strings (not case-sensitive sort)
  // pre:
  // post: vector is in sorted order


//*****************************************************************************  
// enum for dice  
  
  enum RollType {RAGE, MAXSPEED, WILLPOWER, PHYSDAM, DEFENSE, RAISE,
                      HITSCORE, DAMAGE, STRIKE, MORTALWOUND};	 
                      
    // RAGE - Initialize Rage
    // MAXSPEED - Initialize MaxSpeed
    // WILLPOWER - Initialize WillPower
    // PHYSDAM - Initialize physical damage
    // DEFENSE - Initialize Defensive Value
    // RAISE - Increase in level/rank value
    // HITSCORE - HITSCORE value for player in combat
    // DAMAGE - Damage value for player or wpn
    // STRIKE - Strike value for STRIKE table
    // MORTALWOUND - Wound value for MORTAL WOUND table
  
  const int NUM_ROLL_TYPE = 10;
  const string ROLL_STR[NUM_ROLL_TYPE] ={"RAGE", "MAXSPEED", "WILLPOWER", "PHYSDAM", "DEFENSE", "RAISE",
                                         "HITSCORE", "DAMAGE", "STRIKE", "MORTALWOUND"};	 
  RollType StrToRoll(string str);
  // Converts the string RollType to RollType enum

//**********************************************************************
// enum for direction

  enum DirType {NORTH, EAST, SOUTH, WEST};

  const int NUM_DIR_TYPE = 4;
  const string DIR_STR[NUM_DIR_TYPE] = {"NORTH", "EAST", "SOUTH", "WEST"};
  const char DIR_CHAR[NUM_DIR_TYPE] = {'N', 'E', 'S', 'W'};

  DirType StrToDir(string str);
  // Converts string to DirType
  
  DirType CharToDir(char c);
  // Converts char to Dirtype
  
//*****************************************************************************
// Enum for exception handling

  enum ExceptionType {INVALID_GENERAL, INVALID_NAME, INVALID_RANK, INVALID_WPN, INVALID_DIR};
  const int NUM_EX_STR = 5;
  const string EX_STR[NUM_EX_STR] = {"INVALID GENERAL ERROR", "INVALID NAME", "INVALID RANK",
                                     "INVALID WEAPON", "INVALID DIR"};
  
  
//*****************************************************************************  
// File I/O for dice

  void WriteDel(ostream& stream);
  // Writes the delimiter to the output stream
  // pre: stream is open and in good condition
  // post: delimiter has been written
  
  bool ReadNum(istream& stream, int& num,int min,int max);
  // Reads a number, validates range, if valid reads del and returns true
  // pre: stream is open and in good cond, min and max indicate boundaries for num
  // post: valid: returns num, reads passed delimiter (includes \n), returns true
  //       invalid: stops reading and returns false
   
  bool ReadStr(istream& stream, string& str);    
  // Reads string through del, returns true if string length>0 && stream
  // pre: stream is open and in good cond.
  // post: reads str and delimiter (includes \n).  if string length >0 return true
  //		otherwise returns false
  
  bool ReadDel(istream& stream);
  // Reads Del (includes '\n')
  // pre: stream is open and in good cond.
  // post: delimiter is read and stream status is returned

//*****************************************************************************  
// Test output

  void PrintTest(ostream & out, string test="");
  // Prints the test label
  // pre:  out is open and test is prefix for test
  //       if test is new then testnumber is reset
  // post: test label is printed

  void PrintMove(string name, int row, int col, int mom, bool first = false);
  // Prints the move to a file move.out
  // pre:  none
  // post: prints a line to the move.out with the move data
  //
  //   LineNum:PlayerName(Row,Col) Momentum
  //  a line of asterisks is printed when a new player is encountered

  void NewMoveFile( );
  // Removes the move file
  

  string ConvertInt(int num);
  // converts an int to a string
  // pre : num is integer value
  // post: returns as string of num: num = 5, "5"

  
    
};


#endif

