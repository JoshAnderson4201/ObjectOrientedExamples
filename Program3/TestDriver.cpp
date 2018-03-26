#include "DrugDealer.h"
#include "CIA.h"
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


int main()
{
    Weapon* uzi = new Weapon("uzi");
    Weapon* ak = new Weapon("ak-47");
    Weapon* bn = new Weapon("Brass Knuckles");
    Weapon* uz = new Weapon("UZI");
    PlayerClass* p1;
    DrugDealer* d1;
    p1 = new DrugDealer("Josh");
    d1 = dynamic_cast<DrugDealer*>(p1);
    d1->GrabWeapon(uzi);
    d1->GrabWeapon(bn);
    d1->GrabWeapon(ak);
    d1->GrabWeapon(uz);

    cout << d1->UpdateWallet(50) << endl;
    cout << d1->BuyWeapon(uzi);
    cout << d1->Wallet() << endl;

}
