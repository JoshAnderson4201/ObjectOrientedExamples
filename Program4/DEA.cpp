/* Josh Anderson
DEA.cpp */

#include "Agent.h"
#include "DEA.h"
#include "rank.h"
#include<vector>
#include<map>
#include <fstream>
#include <iostream>
#include <cstddef>

const string DEA::TYPE = "DEA";

int DEA::DICE[GameSpace::NUM_ROLL_TYPE][3] = {
//Rage
{2,6,0},
//Max Speed
{2,6,0},
//Willpower
{1,6,6},
//physDam
{1,3,0},
//Defense
{2,3,0},
};

DEA::DEA(): Agent("DEA", DEF_RANK, DEA::DICE)
{
    cout << "DEF_DEA" << endl;
}

DEA::DEA(string initName, RankRules::RankType r): Agent(initName, r, DEA::DICE)
{
    cout << "PARAM_DEA" << endl;
}

string DEA::Type_Str()
{
    return TYPE;
}

void DEA::Write(ostream& out) const
{
    out << TYPE << "#";
    Agent::Write(out);
}

DEA* DEA::Clone() const
{
    return new DEA(*this);
}
