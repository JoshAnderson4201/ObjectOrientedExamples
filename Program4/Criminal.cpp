/* Josh Anderson
Criminal.cpp */

#include "PlayerClass.h"
#include "Criminal.h"
#include "wpn.h"
#include<vector>
#include<map>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <algorithm>

Criminal::Criminal(): PlayerClass("Criminal", DICE), wallet(DEF_WALLET)
{
    cout << "CRIMINAL_DEFAULT" << endl;
}

Criminal::Criminal(string initName, int DICE[][3]): PlayerClass(initName, DICE), wallet(DEF_WALLET)
{
    cout << "CRIMINAL_PARAM" << endl;
}

Criminal::Criminal(const Criminal& c): PlayerClass(c)
{
    CopyIntoMe(c);
}

Criminal::~Criminal()
{
    EmptyArsenal(arsenal);
}

Criminal& Criminal::operator=(const Criminal& c)
{
    if (this != &c)
    {
        CopyIntoMe(c);
        PlayerClass::operator=(c);
    }
    return *this;
}

void Criminal::SetWallet(int amount)
{
    wallet = amount;
}

void Criminal::CopyIntoMe(const Criminal& c)
{
    wallet = c.wallet;
    CopyArsenal(c.arsenal);
    PlayerClass::operator=(c);
}

void Criminal::EmptyArsenal(vector <Weapon*>& arsenal)
{
    for (int i = 0; i<arsenal.size(); ++i)
    {
        delete arsenal[i];
        arsenal[i] = NULL;
    }
    arsenal.clear();
}

void Criminal::CopyArsenal(vector <Weapon*> a)
{
    for(int i = 0; i < a.size(); ++i)
    {
        Weapon* w = new Weapon(*(a[i]));
        arsenal.push_back(w);
    }
}

int Criminal::Wallet() const
{
    return wallet;
}

bool Criminal::IsMyEnemy(PlayerClass* p) const
{
    if (p == NULL || p == this)
        return false;
    return true;
}

vector <string> Criminal::Arsenal() const
{
    vector <string> v;
    if (arsenal.empty() == false)
    {
        for (int i = 0; i != arsenal.size(); ++i)
        {
            v.push_back(arsenal[i]->Name());
        }
    }
    return v;
}

void Criminal::Write(ostream& out) const
{
    out << wallet << "#";
    PlayerClass::Write(out);
    if (arsenal.empty() == false)
    {
        for (int i = 0; i != arsenal.size(); ++i)
        {
                out << arsenal[i]->Name() << "#" << LookUpSkill(arsenal[i]) << "#";
        }
        out << endl;
    }
}

int Criminal::UpdateWallet(int amount)
{
    if (Status() == 1)
    {
        wallet = wallet + amount;
        if (wallet < 0)
            wallet = 0;
        return wallet;
    }
}

Weapon* Criminal::GrabWeapon(Weapon* w)
{
    Weapon* oldWeapon = w;
    if (IsActive() && w)
    {
        oldWeapon = weapon;
        weapon = w;
        if (LookUpSkill(w)==0)
        {
             history[Upper(w->Name())] = 1;
        }
        if (oldWeapon)
        {
            arsenal.push_back(oldWeapon);
            oldWeapon = NULL;
        }
        return oldWeapon;
    }
    else if (w == NULL)
        throw GameSpace::INVALID_WPN;
    return w;
}

bool Criminal::SwapWeapon(string weaponName)
{
    bool found;
    int deleteThis = -1;
    if (IsActive())
    {


        for (int i = 0; i != arsenal.size() && !found; ++i)
        {
            Weapon* newWep = arsenal[i];
            if (newWep->Name() == weaponName)
            {
                GrabWeapon(newWep);
                found = true;
                deleteThis = i;
            }
        }
        if (found)
        {
            arsenal.erase(arsenal.begin() + deleteThis);
        }
        else if (weapon && weapon->Name() == weaponName)
        {
            found = true;
        }
    }
    return found;
}

Weapon* Criminal::BuyWeapon(Weapon* w)
{
    Weapon* retWep = w;
    if (w && wallet >= w->Cost())
    {
        UpdateWallet(-(w->Cost()));
        retWep = GrabWeapon(w);
    }
    else if (w == NULL)
        throw GameSpace::INVALID_WPN;
    return retWep;
}

Weapon* Criminal::SellWeapon(string weaponName)
{
    int deleteThis;
    bool found;
    Weapon* newWep;
    if (IsActive())
    {
        for (int i = 0; i != arsenal.size(); ++i)
        {
            newWep = arsenal[i];
            if (newWep->Name() == weaponName)
            {
                UpdateWallet(newWep->Cost());
                found = true;
                deleteThis = i;
            }
        }
        if (found)
        {
            newWep = arsenal[deleteThis];
            arsenal.erase(arsenal.begin() + deleteThis);
        }
        else if (weapon->Name() == weaponName)
        {
            newWep = weapon;
            weapon = NULL;
        }
        else
            newWep = NULL;
        return newWep;
    }
}
