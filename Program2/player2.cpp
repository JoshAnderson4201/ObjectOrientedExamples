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

using namespace std;

const string TypeStr[6] = {"CIA", "DEA", "NSA", "DRUGDEALER", "HITMAN", "LOANSHARK"};
const string RankStr[5] = {"NNE", "ROOKIE", "SPECIAL", "INTEL", "DIR"};

const int STRIKE_TABLE[13][13] =
{
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 1, 2, 2, 3, 3, 3, 3, 3, 5, 5},
{0, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, -1},
{0, 0, 1, 3, 4, 5, 6, 6, 6, 7, 7, -1, -1},
{0, 0, 1, 4, 5, 5, 6, 7, 7, 8, -1, -1, -1},
{0, 0, 2, 4, 6, 7, 8, 9, 9, -1, -1, -1, -1},
{0, 0, 2, 5, 7,	8, 9, 10, -1, -1, -1, -1, -1},
{0, 0, 3, 5, 8, 9, 9, -1, -1, -1, -1, -1, -1},
{0, 0, 3, 5, 9, 9, -1, -1, -1, -1, -1, -1, -1},
{0, 0, 3, 6, 9, -1, -1, -1, -1, -1, -1, -1, -1},
{0, 0, 5, 6, -1, -1, -1, -1, -1, -1, -1, 10, -1},
{0, 0, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, 10},
};
const int MWT[13][13] =
{
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1},
{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1},
{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1},
{0, 0, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1},
{0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1},
{0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1},
{0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1},
{0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
{0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
};


PlayerClass::PlayerClass()
{
    SetName("DEFAULT");
    SetType(CIA);
    SetRank(RankRules::ROOKIE);
    SetStats(50, 1);
}


PlayerClass::PlayerClass(string initName, PlayerType initType, RankRules::RankType initRank): weapon(NULL)
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

PlayerClass::PlayerClass(const PlayerClass& p): weapon(NULL)
{
    CopyIntoMe(p);
}

PlayerClass::~PlayerClass()
{
    delete weapon;
    EmptyArsenal(arsenal);
}

PlayerClass PlayerClass::operator =(const PlayerClass& p)
{
    if (this != &p)
    {
        //CopyIntoMe(p);
    }
    return *this;
}

void PlayerClass::CopyIntoMe(const PlayerClass& p)
{
    EmptyArsenal(arsenal);
    delete weapon;
    weapon = NULL;

    CopyStats(p);
    row = p.Row();
    col = p.Col();
    wallet = p.Wallet();
    name = p.Name();
    status = p.Status();
    history = p.history;
    if (p.weapon)
    {
        weapon = new Weapon(*p.weapon);
    }
    if (Criminal() == true)
    {
        CopyArsenal(p.arsenal);
    }
}

void PlayerClass::CopyStats(const PlayerClass& p)
{
    stats[HEALTH] = p.stats[HEALTH];
    stats[RAGE] = p.stats[RAGE];
    stats[MAXSPEED] = p.stats[MAXSPEED];
    stats[WILLPOWER] = p.stats[WILLPOWER];
    stats[PHYSDAM] = p.stats[PHYSDAM];
    stats[DEFENSE] = p.stats[DEFENSE];
    stats[CURRENTSPEED] = p.stats[CURRENTSPEED];
    stats[MOMENTUM] = p.stats[MOMENTUM];
    stats[LEVEL] = p.stats[LEVEL];
    SetType(static_cast<PlayerType>(p.Type()));
    SetRank(static_cast<RankRules::RankType>(p.Rank()));
    SetDir(static_cast<GameSpace::DirType>(p.Dir()));
}

void PlayerClass::EmptyArsenal(vector <Weapon*> arsenal)
{
    for (int i = 0; i<arsenal.size(); ++i)
    {
        delete arsenal[i];
        arsenal[i] = NULL;
    }
    arsenal.clear();
}

void PlayerClass::CopyArsenal(vector <Weapon*> a)
{
    for(int i = 0; i < a.size(); ++i)
    {
        Weapon* w = new Weapon(*(a[i]));
        arsenal.push_back(w);
    }
}

string PlayerClass::Upper(const string s) const
{
    string newStr = s;
    for (int i = 0; i < s.length(); i++)
    {
        newStr[i] = toupper(s[i]);
    }
    return newStr;
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
    stats[PHYSDAM] = Dice::Roll(name, GameSpace::PHYSDAM, 1, 3);
    stats[DEFENSE] = Dice::Roll(name, GameSpace::DEFENSE, 2, 6);
    stats[CURRENTSPEED] = stats[MAXSPEED];
    stats[MOMENTUM] = stats[MAXSPEED];
    int t = Type();
    if (t == DRUGDEALER || t == LOANSHARK || t == HITMAN)
    {
        stats[LEVEL] = 0;
        wallet = 0;
    }
    else
    {
       stats[LEVEL] = 1;
    }
    row = -1;
    col = -1;
    status = 1;
    direction = GameSpace::NORTH;
    weapon = NULL;
    wallet = 0;
    weaponSkill = 0;
}

void PlayerClass::SetStatus(int s)
{
    status = s;
}

int PlayerClass::UpdateRage(int amount)
{
    if (status == 1)
    {
        stats[RAGE] = stats[RAGE] + amount;
        if (stats[RAGE] < 0)
            stats[RAGE] = 0;
        return stats[RAGE];
    }
    else
        return stats[RAGE];
}

int PlayerClass::UpdateDefense(int amount)
{
    if (Status() == 1)
    {
        stats[DEFENSE] = stats[DEFENSE] + amount;
        if (stats[DEFENSE] < 0)
            stats[DEFENSE] = 0;
        return stats[DEFENSE];
    }
    else
        return stats[DEFENSE];
}

int PlayerClass::UpdateWallet(int amount)
{
    if (Status() == 1 && Criminal() == true)
    {
            wallet = wallet + amount;
            if (wallet < 0)
                wallet = 0;
            return wallet;
    }
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

int PlayerClass::Status() const
{
    return status;
}

int PlayerClass::Wallet() const
{
    return wallet;
}

int PlayerClass::HitScore() const
{
    if (Status() == 1)
    {
        return Dice::Roll(name, GameSpace::HITSCORE, 2, 6);
    }

}

int PlayerClass::HitDamage() const
{
    if (Status() == 1)
    {
        if (weapon == NULL)
            return stats[RAGE] + RollPhysDam();
        else
        {
            return LookUpSkill(weapon) + weapon->RollDamage(name);
        }
    }
    else
        return 0;
}

int PlayerClass::StrikeImpact() const
{
    int result;
    if (Status() == 1)
    {
        if (weapon == NULL)
        {
            if (stats[RAGE] < 2)
                return 0;
            else
            {
                int strike = Dice::Roll(name, GameSpace::STRIKE, 2, 6);
                if (strike < 13)
                {
                    result = STRIKE_TABLE[strike][stats[RAGE]];
                    return result;
                }
            }
        }
        else
        {
            int strike = Dice::Roll(name, GameSpace::STRIKE, 2, 6);
            if (strike < 13)
            {
                result = STRIKE_TABLE[strike][stats[RAGE]];
                return result;
            }
        }
    }
    else
        return 0;
}

string PlayerClass::WeaponName() const
{
    if (weapon != NULL)
        return weapon->Name();
    else
        return "";
}

int PlayerClass::WeaponSkill() const
{
    if (weapon != NULL)
    {
        return LookUpSkill(weapon);
    }
    else
        return 0;
}

bool PlayerClass::HasWeapon() const
{
    if (weapon == NULL)
        return false;
    else
        return true;
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
    if (IsDead() == false && Status() == 1)
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
    if (Status() == 1)
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
        if ((Agent() == true) && (p->Agent() == true))
            return false;
        else if ((Agent() == true) && (p->Agent() == true))
            return true;
        else if ((Criminal() == true) && (p->Agent() == true))
            return true;
        else if ((Criminal() == true) && (p->Criminal() == true))
            return true;
        else if (this == p)
            return false;
    }
    else
        return false;
}

int PlayerClass::ResetCurrentSpeed()
{
    if (Status() == 1)
    {
        stats[CURRENTSPEED] = stats[MAXSPEED];
        return stats[CURRENTSPEED];
    }
    else
        return stats[MAXSPEED];
}

int PlayerClass::ResetMomentum()
{
    if (Status() == 1)
    {
        stats[MOMENTUM] = stats[MAXSPEED];
        return stats[MOMENTUM];
    }
    else
        return stats[MAXSPEED];
}

int PlayerClass::UseMomentum(int hazard)
{
    if (Status() == 1)
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
    if(Status() == 1)
    {
        stats[HEALTH] = 0;
        stats[WILLPOWER] = 0;
        stats[MOMENTUM] = 0;
        stats[CURRENTSPEED] = 0;
        stats[RAGE] = 0;
        InActive();
        return true;
    }
    else if (stats[HEALTH] > 0)
        return false;
    else
        return true;
}

int PlayerClass::Wounded(int damage)
{
    if(Status() == 1)
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
    if(Status() == 1)
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

bool PlayerClass::Promotion()
{
    if (status ==  1 && Agent() == true)
    {
        stats[LEVEL] = stats[LEVEL] + 1;
        if ((pRank == RankRules::ROOKIE && stats[LEVEL] > 4) || (pRank == RankRules::SPECIAL && stats[LEVEL] > 6) ||
            (pRank == RankRules::INTEL && stats[LEVEL] > 4))
        {
            pRank = static_cast<RankRules::RankType>(static_cast<int>(pRank) + 1);
            stats[LEVEL] = 1;
            if (pRank == RankRules::INTEL)
                stats[HEALTH] = stats[HEALTH] + Dice::Roll(name, GameSpace::RAISE, 1, 6);
            else if (pRank == RankRules::DIR)
                stats[HEALTH] = stats[HEALTH] + Dice::Roll(name, GameSpace::RAISE, 1, 8);
            else
                stats[HEALTH] = stats[HEALTH] + Dice::Roll(name, GameSpace::RAISE, 1, 4);
            if (stats[HEALTH] > 50)
                stats[HEALTH] = 50;
            return true;
        }
        else if (pRank == RankRules::DIR && stats[LEVEL] > 7)
        {
            stats[LEVEL] = 7;
            stats[HEALTH] = stats[HEALTH] + Dice::Roll(name, GameSpace::RAISE, 1, 8);
            if (stats[HEALTH] > 50)
                stats[HEALTH] = 50;
            return true;
        }
        else
            if (pRank == RankRules::INTEL)
                stats[HEALTH] = stats[HEALTH] + Dice::Roll(name, GameSpace::RAISE, 1, 6);
            else if (pRank == RankRules::DIR)
                stats[HEALTH] = stats[HEALTH] + Dice::Roll(name, GameSpace::RAISE, 1, 8);
            else
                stats[HEALTH] = stats[HEALTH] + Dice::Roll(name, GameSpace::RAISE, 1, 4);
            if (stats[HEALTH] > 50)
                stats[HEALTH] = 50;
            return true;
    }
    else
        return false;
}

bool PlayerClass::MortalWound()
{
    if (Status() == 1)
    {
        stats[HEALTH] = stats[HEALTH] - 10;
        if (stats[HEALTH] < 0)
        {
            stats[HEALTH] = 0;
            Dead();
        }
        stats[CURRENTSPEED] = stats[CURRENTSPEED] / 2;
        stats[MOMENTUM] = stats[MOMENTUM] /2;
        if (IsAlive() == true)
        {
            int roll = Dice::Roll(name, GameSpace::MORTALWOUND, 2, 6);
            int result = MWT[roll][stats[WILLPOWER]];
            if (result == -1)
            {
                stats[WILLPOWER] = stats[WILLPOWER] - 1;
                if (stats[WILLPOWER] <= 0)
                {
                    Dead();
                }
                return true;
            }
            else
            {
                Dead();
                return false;
            }
        }
        else
            return false;
    }
    else
        if ( IsAlive() == true )
        {
            return true;
        }
        return false;
}

bool PlayerClass::ImprovedSkill(int improvement)
{
    if (weapon != NULL && improvement > 0)
    {
        history[Upper(weapon->Name())] = history[Upper(weapon->Name())] + improvement;
        if (history[Upper(weapon->Name())] < 0)
        {
            history[Upper(weapon->Name())] = 0;
        }
    return true;
    }
    else return false;
}

Weapon* PlayerClass::DropWeapon()
{
    if (weapon != NULL)
    {
        Weapon* oldWeapon = weapon;
        weapon = NULL;
        return oldWeapon;
    }
    else
        return NULL;
}

int PlayerClass::LookUpSkill(Weapon* w) const
{
    map<string, int>::const_iterator i;
    i = history.find(Upper(w->Name()));
    if (i != history.end())
    {
        return i->second;
    }
    else
        return 0;
}

Weapon* PlayerClass::GrabWeapon(Weapon* w)
{
    if (Status() == 1 && w != NULL)
    {
        Weapon* oldWeapon;
        oldWeapon = weapon;
        if (oldWeapon == NULL)
        {
            weapon = w;
            if (LookUpSkill(w) == 0)
            {
                history[Upper(w->Name())] = 1;
            }
            return NULL;
        }
        else if (Agent() == true && oldWeapon != NULL)
        {
            weapon = w;
            if (LookUpSkill(w) == 0)
            {
                history[Upper(w->Name())] = 1;
            }
            return oldWeapon;
        }
        else if (Criminal() == true && oldWeapon != NULL)
        {
            weapon = w;
            if (LookUpSkill(w) == 0)
            {
                history[Upper(w->Name())] = 1;
            }
            arsenal.push_back(oldWeapon);
            return NULL;
        }
    }
    else
        return w;
}

bool PlayerClass::Move()
{

}

bool PlayerClass::Move(int units)
{

}

bool PlayerClass::CanRun() const
{
    return true;
}

bool PlayerClass::Run()
{

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
    if (dir > -1 && dir < 4)
    {
        direction = dir;
        return true;
    }
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
    out << stats[DEFENSE] << "#";
    if (weapon != NULL)
    {
        out << weapon->Name() << "#" << LookUpSkill(weapon) << "#" << endl;
    }
    else
    {
        out << endl;
    }
    if (Criminal() == true && arsenal.empty() == false)
    {
        for (int i = 0; i != arsenal.size(); ++i)
        {
                out << arsenal[i]->Name() << "#" << LookUpSkill(arsenal[i]) << "#";
        }
        out << endl;
    }
}

bool PlayerClass::operator==(const PlayerClass& p) const
{
    GameSpace::Cmp(Name(), p.Name())
}

bool PlayerClass::operator!=(const PlayerClass& p) const
{
    if (Upper(Name()).compare(p.Upper(p.Name())) > 0 || Upper(Name()).compare(p.Upper(p.Name())) < 0)
        return true;
    else
        return false;
}

bool PlayerClass::operator<(const PlayerClass& p) const
{
    if (Upper(Name()).compare(p.Upper(p.Name())) < 0)
        return true;
    else
        return false;
}

bool PlayerClass::operator>(const PlayerClass& p) const
{
    if (Upper(Name()).compare(p.Upper(p.Name())) > 0)
        return true;
    else
        return false;
}

bool PlayerClass::operator<=(const PlayerClass& p) const
{
    if (Upper(Name()).compare(p.Upper(p.Name())) < 0 || Upper(Name()).compare(p.Upper(p.Name())) == 0)
        return true;
    else
        return false;
}

bool PlayerClass::operator>=(const PlayerClass& p) const
{
    if (Upper(Name()).compare(p.Upper(p.Name())) > 0 || Upper(Name()).compare(p.Upper(p.Name())) == 0)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& out, const PlayerClass* c)
{
    if (c != NULL)
    {
        c->Write(out);
        return out;
    }

}
