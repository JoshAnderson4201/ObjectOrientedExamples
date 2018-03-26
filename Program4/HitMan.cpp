/* Josh Anderson
HitMan.cpp */

#include "PlayerClass.h"
#include "Criminal.h"
#include "HitMan.h"
#include "rank.h"
#include<vector>
#include<map>
#include <fstream>
#include <iostream>
#include <cstddef>

const string HitMan::TYPE = "HITMAN";

int HitMan::DICE[GameSpace::NUM_ROLL_TYPE][3] = {
//Rage
{2,6,0},
//Max Speed
{2,6,3},
//Willpower
{1,6,6},
//physDam
{1,3,0},
//Defense
{2,6,0}};

HitMan::HitMan(): Criminal("HitMan", HitMan::DICE)
{
    cout << "DEF_HitMan" << endl;
}

HitMan::HitMan(string initName): Criminal(initName, HitMan::DICE)
{
    cout << "PARAM_HitMan" << endl;
}

string HitMan::Type_Str()
{
    return TYPE;
}

void HitMan::Write(ostream& out) const
{
    out << TYPE << "#";
    Criminal::Write(out);
}

HitMan* HitMan::Clone() const
{
    return new HitMan(*this);
}
