// rank.h
// cops and robbers Game
//  - provides look up for Health Die, level needed for a rank Promotion, 
//    
#ifndef _RANKH
#define _RANKH

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "gamespace.h"

using namespace std;
using namespace GameSpace;

class RankRules
{
  public:

// ********************************************* Public Constants      
    static const int NUM_RANKS = 5;
    // Number of different ranks
        
// ********************************************* RankType
    enum RankType {NNE, ROOKIE, SPECIAL, INTEL, DIR};
    // Datatype for describing the ranks
    // NNE: None, ROOKIE, SPECIAL, INTEL:Intelligence, DIR:Director

    static const string RANK_STR[NUM_RANKS];
    // string equivalents for RankType
        
    static RankType StrToRank(string s);
    // Convert string to a RankType
    // pre:  s must have string
    // "NNE", "ROOKIE", "SPECIAL", "INTEL", "DIR" 
    // post: return RankType based on string


// ********************************************* LookUp Methods
    int NumLevels(RankType rank) const;
    // Looks up and returns the number of levels given a rank
    // Pre: Rank must be valid Rank_Type
    // Post: Number of levels within Rank
    
    int HealthDice(RankType rank) const;
    // Looks up the specific rank's Health Dice
    // pre:  rank is valid rank
    // post: returns value for the number of sides of the rank's
    //       health dice
    
// ********************************************* Singleton Methods      
    static RankRules* GetRankRules( );
    // Creates the single RankRules instance (singleton)
    // pre:  none
    // post: a pointer to the instance is returned

    static void DeleteRankRules( );    
    // Deletes the instance of RankRules
    // pre: none
    // post: instance has been deleted

// ********************************************* PRIVATE  
private:
    static RankRules* rules;
    // pointer to the singleton

    RankRules( );  //constructor
    // Creates the instance by loading from file

    ~RankRules( ); //destructor

    //Making singleton non copyable
    RankRules(const RankRules&); //no copy constructor
    RankRules& operator=(const RankRules&); //no assignment

    int rankTable[NUM_RANKS][2]; 
    // Table of XP values for promotion
    
    static const int DICE;       //used for table
    static const int NUM_LEVELS ; //used for table
};


#endif




