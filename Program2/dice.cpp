#include "dice.h"

int Dice::Roll(string name, RollType r, int num, int f)
{
    int value;
    cout<< "What would you like " << name << "to Roll for " << ROLL_STR[r] << ":";
    cin >> value;
    return value;
}
