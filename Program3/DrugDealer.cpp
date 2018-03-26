/* Josh Anderson
DrugDealer.cpp */

#include "DrugDealer.h"
#include "rank.h"
#include<vector>
#include<map>
#include <fstream>
#include <iostream>
#include <cstddef>

const string DrugDealer::TYPE = "DRUGDEALER";

int DrugDealer::DICE[GameSpace::NUM_ROLL_TYPE][3] = {
//Rage
{2,6,0},
//Max Speed
{1,6,0},
//Willpower
{1,6,6},
//physDam
{1,3,0},
//Defense
{2,3,4}};

DrugDealer::DrugDealer(): Criminal("DrugDealer", DrugDealer::DICE)
{

    cout << "DEF_DrugDealer" << endl;
}

DrugDealer::DrugDealer(string initName): Criminal(initName, DrugDealer::DICE)
{
    cout << "PARAM_DrugDealer" << endl;
}

string DrugDealer::Type_Str()
{
    return TYPE;
}

void DrugDealer::Write(ostream& out) const
{
    out << TYPE << "#";
    Criminal::Write(out);
}
