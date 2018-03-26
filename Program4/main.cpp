#include <iostream>
#include "hc4.h"

using namespace std;

int main()
{
    Player p1("Josh", Player::cia, RankRules::ROOKIE);
    cout << p1.Name();
    cout << p1.IsCriminal();
    cout << p1.IsAgent();
}
