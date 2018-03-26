#include "player2.h"
#include "gamespace.h"
#include "rank.h"
#include "dice.h"
#include "wpn.h"
#include<vector>
#include<map>
#include <fstream>
#include <iostream>
#include <cstddef>

int main()
{
    PlayerClass p ("hh13", PlayerClass::HITMAN, RankRules::INTEL);
   // cout << p;
    PlayerClass q ("LL15", PlayerClass::LOANSHARK);
    //*q = *p;
}
