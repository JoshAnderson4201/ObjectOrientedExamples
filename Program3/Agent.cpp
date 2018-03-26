/* Josh Anderson
Agent.cpp */

#include "PlayerClass.h"
#include "Agent.h"
#include "CIA.h"
#include "DEA.h"
#include "NSA.h"
#include "rank.h"
#include<vector>
#include<map>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <typeinfo>
using namespace std;

const RankRules::RankType Agent::DEF_RANK = RankRules::ROOKIE;

Agent::Agent(): PlayerClass("AGENT", DICE), pRank(DEF_RANK), level(DEF_LEVEL)
{
    level = 1;
    cout << "DEF_AGENT" << endl;
}

Agent::Agent(string initName, RankRules::RankType r, int DICE[][3]): PlayerClass(initName, DICE)
{
    SetRank(r);
    level = DEF_LEVEL;
    cout << "PARAM_AGENT" << endl;
}

void Agent::SetRank(RankRules::RankType r)
{
    pRank = r;
    if (pRank < 0 || pRank > 4)
        throw GameSpace::INVALID_RANK;
    else if (pRank == RankRules::NNE)
        SetRank(DEF_RANK);
}


//OBSERVERS
int Agent::Rank() const
{
    return pRank;
}

string Agent::Rank_Str() const
{
    return RankRules::RANK_STR[pRank];
}

int Agent::Level() const
{
    return level;
}

bool Agent::IsMyEnemy(PlayerClass* p) const
{
    if (p != NULL)
    {
        if ((typeid(*p) == typeid(CIA) || typeid(*p) == typeid(DEA) || typeid(*p) == typeid(NSA)))
            return false;
        else
            return true;
    }
    return false;

}

bool Agent::Promotion()
{
    if (IsActive())
    {
        level = level + 1;
        if ((pRank == RankRules::ROOKIE && level > 4) || (pRank == RankRules::SPECIAL && level > 6) ||
            (pRank == RankRules::INTEL && level > 4))
        {
            pRank = static_cast<RankRules::RankType>(static_cast<int>(pRank) + 1);
            level = 1;
            if (pRank == RankRules::INTEL)
            {
                SetHealth(Health() + Dice::Roll(Name(), GameSpace::RAISE, 1, 6));
            }
            else if (pRank == RankRules::DIR)
            {
                SetHealth(Health() + Dice::Roll(Name(), GameSpace::RAISE, 1, 8));
            }
            else
            {
                SetHealth(Health() + Dice::Roll(Name(), GameSpace::RAISE, 1, 64));
            }
            if (Health() > MAX_HEALTH)
            {
                SetHealth(MAX_HEALTH);
            }
            return true;
        }
        else if (pRank == RankRules::DIR && level > 7)
        {
            level = 7;
            SetHealth(Health() + Dice::Roll(Name(), GameSpace::RAISE, 1, 8));
            if (Health() > MAX_HEALTH)
            {
                SetHealth(MAX_HEALTH);
            }
            return true;
        }
        else
        {
            if (pRank == RankRules::INTEL)
            {
                SetHealth(Health() + Dice::Roll(Name(), GameSpace::RAISE, 1, 6));
            }
            else if (pRank == RankRules::DIR)
            {
                SetHealth(Health() + Dice::Roll(Name(), GameSpace::RAISE, 1, 8));
            }
            else
            {
                SetHealth(Health() + Dice::Roll(Name(), GameSpace::RAISE, 1, 4));
            }
            if (Health() > MAX_HEALTH)
            {
                SetHealth(MAX_HEALTH);
            }
            return true;
        }
    }
    else
        return false;
}

void Agent::Write(ostream& out) const
{

    out << Rank_Str().at(0) << "#";
    out << level << "#";
    PlayerClass::Write(out);
}
