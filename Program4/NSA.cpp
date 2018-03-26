/* Josh Anderson
NSA.cpp */

#include "PlayerClass.h"
#include "Agent.h"
#include "NSA.h"
#include "rank.h"
#include<vector>
#include<map>
#include <fstream>
#include <iostream>
#include <cstddef>


const string NSA::TYPE = "NSA";

int NSA::DICE[GameSpace::NUM_ROLL_TYPE][3] = {
//Rage
{2,6,0},
//Max Speed
{1,6,2},
//Willpower
{1,6,6},
//physDam
{1,3,0},
//Defense
{2,4,1}};

NSA::NSA(): Agent("NSA", DEF_RANK, NSA::DICE)
{
    cout << "DEF_NSA" << endl;
}

NSA::NSA(string initName, RankRules::RankType r): Agent(initName, r, NSA::DICE)
{
    cout << "PARAM_NSA" << endl;
}

string NSA::Type_Str()
{
    return TYPE;
}

void NSA::Write(ostream& out) const
{
    out << TYPE << "#";
    Agent::Write(out);
}

NSA* NSA::Clone() const
{
    return new NSA(*this);
}
