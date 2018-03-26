/* Josh Anderson
PlayerClass.cpp */

#include "PlayerClass.h"
#include "gamespace.h"
#include "rank.h"
#include "dice.h"
#include "wpn.h"
#include "gamespace.h"
#include<vector>
#include<map>
#include <fstream>
#include <iostream>
#include <cstddef>


using namespace std;

int PlayerClass::DICE[GameSpace::NUM_ROLL_TYPE][3];

const string PlayerClass::DEF_NAME = "DEFAULT";

const DirType PlayerClass::DEF_DIR = GameSpace::NORTH;

const int PlayerClass::STRIKE_TABLE[13][13] =
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

const int PlayerClass::MWT[13][13] =
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

PlayerClass::PlayerClass(): name(DEF_NAME)
{
    cout << "PC::Def";
}

PlayerClass::PlayerClass(string initName, int fDICE[][3]): weapon(NULL)
{
    SetName(initName);
    SetStats(MAX_HEALTH, DEF_WS, fDICE);
}

PlayerClass::PlayerClass(const PlayerClass& p):weapon(NULL)
{
    CopyIntoMe(p);
}

PlayerClass::~PlayerClass()
{
    delete weapon;
}

PlayerClass& PlayerClass::operator =(const PlayerClass& p)
{
    if (this != &p)
    {
        CopyIntoMe(p);
    }
    return *this;
}

void PlayerClass::CopyIntoMe(const PlayerClass& p)
{
    delete weapon;
    weapon = NULL;

    CopyStats(p);
    if (p.weapon)
    {
        weapon = new Weapon(*p.weapon);
    }
}

void PlayerClass::CopyStats(const PlayerClass& p)
{
    for (int i = 0; i < NUM_STATS; i++)
    {
        stats[i] = p.stats[i];
    }
    SetDir(static_cast<GameSpace::DirType>(p.Dir()));
    row = p.Row();
    col = p.Col();
    name = p.Name();
    status = p.Status();
    history = p.history;
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
//    n = GameSpace::TrimStr(n);
    if (n.length() > 10)
        n = n.substr(0, 10);
    name = n;
    if (name == "")
        throw GameSpace::INVALID_NAME;
}

void PlayerClass::SetHealth(int h)
{
    stats[HEALTH] = h;
}

void PlayerClass::SetStats(int health, int ws, int fDICE[][3])
{

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            PlayerClass::DICE[i][j] = fDICE[i][j];

    for (int s = 0; s <= GameSpace::DEFENSE; s++)
    {
        GameSpace::RollType type = static_cast<GameSpace::RollType>(s);
        stats[s] = Dice::Roll(name, type, DICE[s][0], DICE[s][1]) + DICE[s][2];
    }
    stats[HEALTH] = health;
    stats[WEAPONSKILL] = ws;
    if (stats[RAGE] > 12)
    {
        stats[RAGE] = 12;
    }
    stats[CURRENTSPEED] = stats[MAXSPEED];
    stats[MOMENTUM] = stats[MAXSPEED];
    row = DEF_ROW;
    col = DEF_COL;
    status = 1;
    direction = DEF_DIR;
    weapon = NULL;
}

void PlayerClass::SetStatus(int s)
{
    status = s;
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

string PlayerClass::WeaponName() const
{
    if (weapon != NULL)
        return weapon->Name();
    else
        return "";
}

bool PlayerClass::UpdateDice(GameSpace::RollType roll, int newDice[3])
{
    DICE[roll][0] = newDice[0];
    DICE[roll][1] = newDice[1];
    DICE[roll][2] = newDice[2];
}


string PlayerClass::Name() const
{
    return name;
}

int PlayerClass::Row() const
{
    return row;
}

int PlayerClass::Col() const
{
    return col;
}

int  PlayerClass::Dir() const
{
    return direction;
}

int PlayerClass::Health() const
{
    return stats[HEALTH];
}

int PlayerClass::Rage() const
{
    return stats[RAGE];
}

int PlayerClass::WillPower() const
{
    return stats[WILLPOWER];
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

int PlayerClass::RollPhysDam() const
{
    return Dice::Roll(name, GameSpace::PHYSDAM, stats[PHYSDAM], 4);
}

int PlayerClass::Defense() const
{
    return stats[DEFENSE];
}

int PlayerClass::Status() const
{
    return status;
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

bool PlayerClass::IsActive() const
{
    return (Status() == 1);
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
    return (weapon != NULL);
}

void PlayerClass::Write(ostream& out) const
{
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
}

int PlayerClass::RollDice(GameSpace::RollType roll) const
{
    return Dice::Roll(name, roll, DICE[roll][0], DICE[roll][1]) + DICE[roll][2];
}


//TRASNFORMERS



bool PlayerClass::Active()
{
    if (!IsDead())
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
    if(IsActive())
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
    if(IsActive())
    {
        if (damage > -1)
        {
            stats[HEALTH] = stats[HEALTH] - damage;
            if(stats[HEALTH] <= 0)
                Dead();
            else if (stats[WILLPOWER] <=0)
                Dead();
        }
    }
    return stats[HEALTH];
}

int PlayerClass::Invigorate(int vigor)
{
    if(IsActive())
    {
        if (vigor > -1)
        {
            stats[HEALTH] = stats[HEALTH] + vigor;
            if (stats[HEALTH] > MAX_HEALTH)
            {
                stats[HEALTH] = MAX_HEALTH;
            }
        }
    }
    return stats[HEALTH];
}

bool PlayerClass::Heal()
{
    if (!IsDead() && IsActive())
    {
        stats[HEALTH] = stats[HEALTH] + 10;
        if (stats[HEALTH] > MAX_HEALTH)
            stats[HEALTH] = MAX_HEALTH;
        stats[CURRENTSPEED] = stats[MAXSPEED];
        return true;
    }
}

int PlayerClass::SlowDown(int hazard)
{
    if (IsActive())
    {
        if (hazard > -1)
        {
        stats[CURRENTSPEED] = stats[CURRENTSPEED] - hazard;
            if (stats[CURRENTSPEED] >= 0)
            {
                if (stats[MOMENTUM] > stats[CURRENTSPEED])
                    stats[MOMENTUM] = stats[CURRENTSPEED];
            }
            else
            {
                stats[CURRENTSPEED] = 0;
                if (stats[MOMENTUM] > stats[CURRENTSPEED])
                    stats[MOMENTUM] = stats[CURRENTSPEED];
            }
        }
    }
    return stats[CURRENTSPEED];
}

int PlayerClass::ResetCurrentSpeed()
{
    if (IsActive())
    {
        stats[CURRENTSPEED] = stats[MAXSPEED];
    }
    return stats[CURRENTSPEED];
}

int PlayerClass::ResetMomentum()
{
    if (IsActive())
    {
        stats[MOMENTUM] = stats[MAXSPEED];
    }
    return stats[MOMENTUM];
}

int PlayerClass::UseMomentum(int hazard)
{
    if (IsActive())
    {
        if (hazard > -1)
        {
            stats[MOMENTUM] = stats[MOMENTUM] - hazard;
            if (stats[MOMENTUM] < 0)
            {
               stats[MOMENTUM] = 0;
            }
        }
    }
    return stats[MOMENTUM];
}

bool PlayerClass::SetCell(int newRow, int newCol)
{
    bool okay;
    if((newRow > -1) && (newCol > -1))
    {
        row = newRow;
        col = newCol;
        okay = true;
    }
    else if ((newRow == -1) && (newCol == -1))
    {
        row = newRow;
        col = newCol;
        okay = true;
    }
    else
    {
        throw GameSpace::INVALID_CELL;
        okay = false;
    }
    return okay;
}

bool PlayerClass::SetDir(DirType dir)
{
    if (dir > -1 && dir < 4)
    {
        direction = dir;
        return true;
    }
    else
        throw GameSpace::INVALID_DIR;
}

int PlayerClass::UpdateRage(int amount)
{
    if (IsActive())
    {
        stats[RAGE] = stats[RAGE] + amount;
        if (stats[RAGE] < 0)
        {
            stats[RAGE] = 0;
        }
    }
    return stats[RAGE];
}

int PlayerClass::UpdateDefense(int amount)
{
    if (IsActive())
    {
        stats[DEFENSE] = stats[DEFENSE] + amount;
        if (stats[DEFENSE] < 0)
            stats[DEFENSE] = 0;
        return stats[DEFENSE];
    }
    else
        return stats[DEFENSE];
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

Weapon* PlayerClass::GrabWeapon(Weapon* w)
{
    if (IsActive() && w != NULL)
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
        else if (oldWeapon != NULL)
        {
            weapon = w;
            if (LookUpSkill(w) == 0)
            {
                history[Upper(w->Name())] = 1;
            }
            return oldWeapon;
        }
    }
    else if (w == NULL)
        throw GameSpace::INVALID_WPN;
    return w;
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
                result = 0;
            else
            {
                int strike = Dice::Roll(name, GameSpace::STRIKE, 2, 6);
                if (strike < 13)
                {
                    result = STRIKE_TABLE[strike][stats[RAGE]];
                }
            }
        }
        else
        {
            int strike = Dice::Roll(name, GameSpace::STRIKE, 2, 6);
            if (strike < 13)
            {
                result = STRIKE_TABLE[strike][stats[RAGE]];
            }
        }
    return result;
    }
    else
        return 0;
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






bool PlayerClass::operator==(const PlayerClass& p) const
{
//     return GameSpace::Cmp(Name(), p.Name());
}

bool PlayerClass::operator!=(const PlayerClass& p) const
{
    return (Upper(Name()).compare(p.Upper(p.Name())) > 0 || Upper(Name()).compare(p.Upper(p.Name())) < 0);
}

bool PlayerClass::operator<(const PlayerClass& p) const
{
    return (Upper(Name()).compare(p.Upper(p.Name())) < 0);
}

bool PlayerClass::operator>(const PlayerClass& p) const
{
    return (Upper(Name()).compare(p.Upper(p.Name())) > 0);
}

bool PlayerClass::operator<=(const PlayerClass& p) const
{
    return (Upper(Name()).compare(p.Upper(p.Name())) < 0 || Upper(Name()).compare(p.Upper(p.Name())) == 0);
}

bool PlayerClass::operator>=(const PlayerClass& p) const
{
    return (Upper(Name()).compare(p.Upper(p.Name())) > 0 || Upper(Name()).compare(p.Upper(p.Name())) == 0);
}

ostream& operator<<(ostream& out, const PlayerClass* c)
{
    if (c != NULL)
    {
        c->Write(out);
        return out;
    }

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
    return true;
}




