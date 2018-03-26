#include "wpn.h"

Weapon::Weapon(const string wpn)
{
    name = wpn;
}

string Weapon::Name() const
{
    return name;
}

int Weapon::RollDamage(string name) const
{
    return 10;
}

int Weapon::Cost() const
{
    return 10;
}
