#ifndef CRIMINAL_H_INCLUDED
#define CRIMINAL_H_INCLUDED
#include "wpn.h"
#include "PlayerClass.h"

class Criminal: public PlayerClass
{
    public:
        int Wallet() const;
        //Narrative: returns the criminal's wallet
        //Pre-condition: none.
        //Post-condition: returns wallet value

        bool IsMyEnemy(PlayerClass* p)const;
        //Narrative: checks to see if p is an enemy to the current criminal
        //Pre-condition: none.
        //Post-condition: false returned

        vector <string> Arsenal() const;
        //Narrative: creates a string array based off of a criminal's arsenal
        //Pre-condition: criminal must have an arsenal.
        //Post-condition: string array of weapon names returned.

        int UpdateWallet(int amount);
        //Narrative: updates the criminal's wallet
        //Pre-condition: none.
        //Post-condition: players wallet is either decreased or increased by amount
        bool SwapWeapon(string weaponName);
        //Narrative: allows a criminal to swap their equipped weapon with a
        //weapon in the arsenal.
        //Pre-condition: none.
        //Post-condition: criminal's equipped weapon is inserted into arsenal,
        //and passed in weapon is then equipped. If swap is successful, true is returned.

        Weapon* BuyWeapon(Weapon* wpn);
        //Narrative: allows a criminal to buy a weapon
        //Pre-condition: weapon has to be a valid weapon.
        //Post-condition: if the criminal has a high enough wallet value,
        //the passed in weapon is purchased, reducing the wallet value and adding
        //the weapon to the arsenal.

        Weapon* SellWeapon(string weaponName);
        //Narrative: allows a criminal to sell a weapon
        //Pre-condition: none.
        //Post-condition: the criminal sells the passed in weapon, removing it from
        //the arsenal and adding it's cost to the criminal's wallet value.

        virtual Weapon* GrabWeapon(Weapon* w);

        Criminal(const Criminal& c);
        virtual ~Criminal();
        Criminal& operator=(const Criminal& c);

         virtual Criminal* Clone() const = 0;

        void Write(ostream& out) const;

    protected:
        Criminal(string name, int DICE[][3]);


    private:
        Criminal();
        void SetWallet(int amount);
        //Narrative: sets the value of wallet to the passed in amount
        //Pre-condition: none
        //Post-condition: wallet is updated to amount

        void CopyIntoMe(const Criminal& c);
        //Narrative: Copies all of the fields of a criminal into a new criminal object
        //Pre-condition: a criminal must exist to be copied from
        //Post-condition: new criminal has the same data as the other criminal, with its
        //own memory addresses for dynamic data

        void EmptyArsenal(vector <Weapon*>& arsenal);
        //Narrative: Empties the passed in arsenal
        //Pre-condition: a vector of Weapon pointers must be created
        //Post-condition: the vector is empty

        void CopyArsenal(vector<Weapon*> a);
        //Narrative: Copies the arsenal passed in
        //Pre-condition: a vector of Weapon pointers must be created
        //Post-condition: the vector is copied into a new vector

        static const int DEF_WALLET = 0;
        int wallet;
        vector<Weapon*> arsenal;
        int DICE [GameSpace::NUM_ROLL_TYPE][3];
};


#endif // CRIMINAL_H_INCLUDED
