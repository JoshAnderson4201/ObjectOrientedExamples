/* Josh Anderson
LoanShark.cpp */

#include "PlayerClass.h"
#include "Agent.h"
#include "LoanShark.h"
#include "rank.h"
#include<vector>
#include<map>
#include <fstream>
#include <iostream>
#include <cstddef>


const string LoanShark::TYPE = "LOANSHARK";

int LoanShark::DICE[GameSpace::NUM_ROLL_TYPE][3] = {
//Rage
{2,6,0},
//Max Speed
{1,6,3},
//Willpower
{1,6,6},
//physDam
{1,3,0},
//Defense
{2,4,2}};

LoanShark::LoanShark(): Criminal("LoanShark", LoanShark::DICE)
{
    cout << "DEF_LoanShark" << endl;
}

LoanShark::LoanShark(string initName): Criminal(initName, LoanShark::DICE)
{
    cout << "PARAM_LoanShark" << endl;
}

string LoanShark::Type_Str()
{
    return TYPE;
}

void LoanShark::Write(ostream& out) const
{
    out << TYPE << "#";
    Criminal::Write(out);
}
