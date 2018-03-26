#include "wpn.h"

Weapon::Weapon(const string wpn)
{
    name = wpn;
}

string Weapon::Name() const
{
    return name;
}
