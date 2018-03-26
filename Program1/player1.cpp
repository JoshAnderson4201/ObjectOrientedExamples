#include "player1.h"
#include "gamespace.h"
#include "rank.h"
#include "dice.h"
#include <fstream>
#include <iostream>
#include <cstddef>

using namespace std;

const string TypeStr[6] = {"CIA", "DEA", "NSA", "DRUGDEALER", "HITMAN", "LOANSHARK"};
const string RankStr[5] = {"NNE", "ROOKIE", "SPECIAL", "INTEL", "DIR"};

int main()
{
    cout << "hello";
}

PlayerClass::PlayerClass()
{
    SetName("DEFAULT");
    SetType(CIA);
    SetRank(RankRules::ROOKIE);
    //SetStats(50, 1);
}

PlayerClass::PlayerClass(string initName)
{
    if(initName == "")
    {
        SetName("DEFAULT");
        SetType(CIA);
        SetRank(RankRules::ROOKIE);
        SetStats(50, 1);
    }
    else
    {
        SetName(initName);
        SetType(CIA);
        SetRank(RankRules::ROOKIE);
        SetStats(50, 1);
    }
}

PlayerClass::PlayerClass(string initName, PlayerType initType)
{
    if (initType >= 0 && initType < 6)
    {
        if(initName == "")
        {
            SetName("DEFAULT");
            SetType(initType);
            SetRank(RankRules::ROOKIE);
            SetStats(50, 1);
        }
        else
        {
            SetName(initName);
            SetType(initType);
            SetRank(RankRules::ROOKIE);
            SetStats(50, 1);
        }
    }
    else
    {
        if(initName == "")
        {
            SetName("DEFAULT");
            SetType(CIA);
            SetRank(RankRules::ROOKIE);
            SetStats(50, 1);
        }
        else
        {
            SetName(initName);
            SetType(CIA);
            SetRank(RankRules::ROOKIE);
            SetStats(50, 1);
        }
    }
}

PlayerClass::PlayerClass(string initName, PlayerType initType, RankRules::RankType initRank)
{
    if ((initRank >= 0 && initType >= 0) && (initRank < 5 && initType < 6))
    {
        if(initName == "")
        {
            SetName("DEFAULT");
            SetType(initType);
            SetRank(initRank);
            SetStats(50, 1);
        }
        else
        {
            SetName(initName);
            SetType(initType);
            SetRank(initRank);
            SetStats(50, 1);
        }
    }
    else if ((initRank >= 0 && initType >= 0) && (initRank >= 5 && initType < 6))
    {
        if(initName == "")
        {
            SetName("DEFAULT");
            SetType(initType);
            SetRank(RankRules::ROOKIE);
            SetStats(50, 1);
        }
        else
        {
            SetName(initName);
            SetType(initType);
            SetRank(RankRules::ROOKIE);
            SetStats(50, 1);
        }
    }
    else if ((initRank >= 0 && initType >= 0) && (initRank < 5 && initType >= 6))
    {
        if(initName == "")
        {
            SetName("DEFAULT");
            SetType(CIA);
            SetRank(initRank);
            SetStats(50, 1);
        }
        else
        {
            SetName(initName);
            SetType(CIA);
            SetRank(initRank);
            SetStats(50, 1);
        }
    }
    else if ((initRank < 0 && initType >= 0) && (initRank < 5 && initType < 6))
    {
        if(initName == "")
        {
            SetName("DEFAULT");
            SetType(initType);
            SetRank(RankRules::ROOKIE);
            SetStats(50, 1);
        }
        else
        {
            SetName(initName);
            SetType(initType);
            SetRank(RankRules::ROOKIE);
            SetStats(50, 1);
        }
    }
    else if ((initRank >= 0 && initType < 0) && (initRank < 5 && initType < 6))
    {
        if(initName == "")
        {
            SetName("DEFAULT");
            SetType(CIA);
            SetRank(initRank);
            SetStats(50, 1);
        }
        else
        {
            SetName(initName);
            SetType(CIA);
            SetRank(initRank);
            SetStats(50, 1);
        }
    }
    else
    {
        if(initName == "")
        {
            SetName("DEFAULT");
            SetType(CIA);
            SetRank(RankRules::ROOKIE);
            SetStats(50, 1);
        }
        else
        {
            SetName(initName);
            SetType(CIA);
            SetRank(RankRules::ROOKIE);
            SetStats(50, 1);
        }
    }

}

void PlayerClass::SetName(string n)
{
    name = n;
}

void PlayerClass::SetType(PlayerType t)
{
        type = t;
}

void PlayerClass::SetRank(RankRules::RankType r)
{
    int t = Type();
    if (t == DRUGDEALER || t == LOANSHARK || t == HITMAN)
    {
        pRank = RankRules::NNE;
    }
    else if ((t == CIA || t == DEA || t == NSA) && r == RankRules::NNE)
    {
        pRank = RankRules::ROOKIE;
    }
    else
        pRank = r;
}

void PlayerClass::SetStats(int health, int ws)
{
    stats[HEALTH] = health;
    stats[WEAPONSKILL] = ws;
    stats[RAGE] = Dice::Roll(name, GameSpace::RAGE, 2, 6);
    if (stats[RAGE] > 12)
    {
        stats[RAGE] = 12;
    }
    stats[MAXSPEED] = Dice::Roll(name, GameSpace::MAXSPEED, 2, 6);
    stats[WILLPOWER] = (Dice::Roll(name, GameSpace::WILLPOWER, 1, 6)) + 6;
    //int damageRolls = Dice::Roll(name, GameSpace::PHYSDAM, 1, 3);
    stats[PHYSDAM] = Dice::Roll(name, GameSpace::PHYSDAM, 1, 3);
    stats[DEFENSE] = Dice::Roll(name, GameSpace::DEFENSE, 2, 6);
    stats[CURRENTSPEED] = stats[MAXSPEED];
    stats[MOMENTUM] = stats[MAXSPEED];
    int t = Type();
    if (t == DRUGDEALER || t == LOANSHARK || t == HITMAN)
    {
        stats[LEVEL] = 0;
    }
    else
    {
       stats[LEVEL] = 1;
    }
    row = -1;
    col = -1;
    status = 1;
    direction = GameSpace::NORTH;
}

string PlayerClass::Name() const
{
    return name;
}

int PlayerClass::Health() const
{
    return stats[HEALTH];
}

// zimmer edit PlayerClass::PlayerType PlayerClass::Type() const
int PlayerClass::Type() const
{
    return type;
}

string PlayerClass::Type_Str() const
{
    return TypeStr[type];
}

// zimmer edit RankRules::RankType PlayerClass::Rank() const
int PlayerClass::Rank() const
{
    return pRank;
}

string PlayerClass::Rank_Str() const
{
    return RankStr[pRank];
}

int PlayerClass::MaxSpeed() const
{
    return stats[MAXSPEED];
}

int PlayerClass::CurrentSpeed() const
{
    return stats[CURRENTSPEED];
}

int PlayerClass::Momentum() const
{
    return stats[MOMENTUM];
}

int PlayerClass::Level() const
{
    return stats[LEVEL];
}

int PlayerClass::RollPhysDam() const
{
    return Dice::Roll(name, GameSpace::PHYSDAM, stats[PHYSDAM], 4);
}

int PlayerClass::Row() const
{
    return row;
}

int PlayerClass::Col() const
{
    return col;
}

int PlayerClass::Defense() const
{
    return stats[DEFENSE];
}

int PlayerClass::Rage() const
{
    return stats[RAGE];
}

int PlayerClass::WillPower() const
{
    return stats[WILLPOWER];
}

//zimmer DirType PlayerClass::Dir() const
int  PlayerClass::Dir() const
{
    return direction;
}



bool PlayerClass::Agent() const
{
    if (type == DEA || type == CIA || type == NSA)
        return true;
    else
        return false;
}

bool PlayerClass::Criminal() const
{
    if (type == DRUGDEALER || type == HITMAN || type == LOANSHARK)
        return true;
    else
        return false;
}

bool PlayerClass::IsAlive() const
{
    if (stats[HEALTH] > 0)
        return true;
    else
        return false;
}


bool PlayerClass::IsDead() const
{
    if (stats[HEALTH] <= 0)
        return true;
    else
        return false;
}

bool PlayerClass::Heal()
{
    if (IsDead() == false && status == 1)
    {
        stats[HEALTH] = stats[HEALTH] + 10;
        if (stats[HEALTH] > 50)
            stats[HEALTH] = 50;
        stats[CURRENTSPEED] = stats[MAXSPEED];
        return true;
    }
    else
        return false;
}

bool PlayerClass::IsActive() const
{
    if (status == 1)
    {
        return true;
    }
    else return false;
}

int PlayerClass::SlowDown(int hazard)
{
    if (status==1)
    {
        if (hazard > -1)
        {
        stats[CURRENTSPEED] = stats[CURRENTSPEED] - hazard;
            if (stats[CURRENTSPEED] >= 0)
            {
                if (stats[MOMENTUM] > stats[CURRENTSPEED])
                    stats[MOMENTUM] = stats[CURRENTSPEED];
                return stats[CURRENTSPEED];
            }
            else
            {
                stats[CURRENTSPEED] = 0;
                if (stats[MOMENTUM] > stats[CURRENTSPEED])
                    stats[MOMENTUM] = stats[CURRENTSPEED];
                return stats[CURRENTSPEED];
            }
        }
        else
            return stats[CURRENTSPEED];
    }
    else
        return stats[CURRENTSPEED];
}

bool PlayerClass::IsMyEnemy(PlayerClass* p) const
{
    if ( p != NULL)
    {
        if ((type == CIA || type == DEA || type == NSA) && (p->type == CIA || p->type == DEA || p->type == NSA))
            return false;
        else if ((type == CIA || type == DEA || type == NSA) && (p->type == HITMAN || p->type == LOANSHARK || p->type == DRUGDEALER))
            return true;
        else if ((type == HITMAN || type == LOANSHARK || type == DRUGDEALER) && (p->type == CIA || p->type == DEA || p->type == NSA))
            return true;
        else if ((type == HITMAN || type == LOANSHARK || type == DRUGDEALER) && (p->type == HITMAN || p->type == LOANSHARK || p->type == DRUGDEALER))
            return true;
        else if ( p == this)
            return false;
    }
    else
        return false;
}

int PlayerClass::ResetCurrentSpeed()
{
    if (status == 1)
    {
        stats[CURRENTSPEED] = stats[MAXSPEED];
        return stats[CURRENTSPEED];
    }
    else
        return stats[MAXSPEED];
}

int PlayerClass::ResetMomentum()
{
    if (status == 1)
    {
        stats[MOMENTUM] = stats[MAXSPEED];
        return stats[MOMENTUM];
    }
    else
        return stats[MAXSPEED];
}

int PlayerClass::UseMomentum(int hazard)
{
    if (status == 1)
    {
        if (hazard > -1)
        {
            stats[MOMENTUM] = stats[MOMENTUM] - hazard;
            if (stats[MOMENTUM] > 0)
            {
                return stats[MOMENTUM];
            }
            else
            {
                stats[MOMENTUM] = 0;
                return stats[MOMENTUM];
            }
        }
        else
            return stats[MOMENTUM];
    }
    else
            return stats[MOMENTUM];
}

bool PlayerClass::Active()
{
    if (IsDead() == false)
    {
        status = true;
        return true;
    }
    else
        return false;
}

bool PlayerClass::InActive()
{
        status = false;
        return true;
}

bool PlayerClass::Dead()
{
    if(status == 1)
    {
        stats[HEALTH] = 0;
        stats[WILLPOWER] = 0;
        stats[MOMENTUM] = 0;
        stats[CURRENTSPEED] = 0;
        stats[RAGE] = 0;
        InActive();
        return true;
    }
    return false;
}

int PlayerClass::Wounded(int damage)
{
    if(status == 1)
    {
        if (damage < 0)
            return stats[HEALTH];
        else
        {
            stats[HEALTH] = stats[HEALTH] - damage;
            if(stats[HEALTH] <= 0)
                Dead();
            else if (stats[WILLPOWER] <=0)
                Dead();
            return stats[HEALTH];
        }
    }
    else
        return stats[HEALTH];
}

int PlayerClass::Invigorate(int vigor)
{
    if(status == 1)
    {
        if (vigor < 0)
            return stats[HEALTH];
        else
            stats[HEALTH] = stats[HEALTH] + vigor;
            if (stats[HEALTH] > 50)
            {
                stats[HEALTH] = 50;
            }
            return stats[HEALTH];
    }
    else
        return stats[HEALTH];
}

bool PlayerClass::SetCell(int newRow, int newCol)
{
    if((newRow > -1) && (newCol > -1))
    {
        row = newRow;
        col = newCol;
        return true;
    }
    else if ((newRow == -1) && (newCol == -1))
    {
        row = newRow;
        col = newCol;
        return true;
    }
    else
        return false;
}


bool PlayerClass::SetDir(DirType dir)
{
    if (dir == direction)
    {
        direction = dir;
        return true;
    }
    else if (dir > -1 && dir < 4)
    {
        direction = dir;
        return true;
    }
    else if (dir > 3)
    {
        direction = GameSpace::NORTH;
        return false;
    }
    else
        direction = GameSpace::NORTH;
        return false;

}



void PlayerClass::Write(ostream& out) const
{
    out << TypeStr[type] << "#";
    string rChar;
    if (pRank == 1)
        rChar = "R";
    else if (pRank == 2)
        rChar = "S";
    else if (pRank == 3)
        rChar = "I";
    else if (pRank == 4)
        rChar = "D";
    else if (pRank == 0)
        rChar = "N";
    out << rChar << "#";
    out << stats[LEVEL] << "#";
    out << status << "#";
    out << name << "#";
    out << "(" <<row << "," << col << "," << GameSpace::DIR_CHAR[direction] << ")" << "#";
    out << stats[HEALTH]<< "#";
    out << stats[RAGE]<< "#";
    out << stats[WILLPOWER]<< "#";
    out << stats[CURRENTSPEED]<< "#";
    out << stats[MOMENTUM]<< "#";
    out << (stats[PHYSDAM]) << "D4" << "#";
    out << stats[DEFENSE] << "#" << endl;
}

ostream& operator<<(ostream& out, const PlayerClass* c)
{
    if (c != NULL)
    {
        c->Write(out);
        return out;
    }

}
