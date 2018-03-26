/* Josh Anderson
CIA.cpp */

#include "Agent.h"
#include "CIA.h"
#include "rank.h"
#include<vector>
#include<map>
#include <fstream>
#include <iostream>
#include <cstddef>

const string CIA::TYPE = "CIA";

int CIA::DICE[GameSpace::NUM_ROLL_TYPE][3] = {
//Rage
{2,6,0},
//Max Speed
{1,6,0},
//Willpower
{1,6,6},
//physDam
{1,3,0},
//Defense
{2,4,0}};


CIA::CIA(): Agent("CIA", DEF_RANK, CIA::DICE)
{
    cout << "DEF_CIA" << endl;
}

CIA::CIA(string initName, RankRules::RankType r): Agent(initName, r, DICE)
{
    cout << "PARAM_CIA" << endl;
}

string CIA::Type_Str()
{
    return TYPE;
}

void CIA::Write(ostream& out) const
{
    out << TYPE << "#";
    Agent::Write(out);
}
