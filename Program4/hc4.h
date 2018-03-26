#ifndef HC4_H_INCLUDED
#define HC4_H_INCLUDED
#include "p3.h"

//Josh Anderson Handle .h

class Player
{

    public:
        enum PlayerType {cia, dea, nsa, drugdealer, hitman, loanshark};

        Player();
        Player(PlayerClass* p);
        Player(string name, Player::PlayerType t = cia, RankRules::RankType r = RankRules::ROOKIE);
        Player(const Player& other);
        ~Player();
        Player& operator=(const Player& other);
        void CopyIntoMe(const Player& other);

        //PayerClass Functions

        //OBSERVERS
        string Name() const;
        //Narrative: returns the player’s name.
        //Pre-condition: none.
        //Post-condition: player’s name is returned to the client.

        int Row() const;
        //Narrative: returns the player’s row.
        //Pre-condition: none.
        //Post-condition: player’s row is returned.

        int Col() const;
        //Narrative: returns the player’s col.
        //Pre-condition: none.
        //Post-condition: player’s col is returned.

        int Health() const;
        //Narrative: returns the player’s health.
        //Pre-condition: none.
        //Post-condition: player’s health is returned to the client.

        int Rage() const;
        //Narrative: returns the player’s rage.
        //Pre-condition: none.
        //Post-condition: player’s rage is returned.

        int WillPower() const;
        //Narrative: returns the player’s will power.
        //Pre-condition: none.
        //Post-condition: player’s will power is returned to the client.

        int MaxSpeed() const;
        //Narrative: returns the player’s max speed.
        //Pre-condition: none.
        //Post-condition: player’s max speed is returned..

        int CurrentSpeed() const;
        //Narrative: returns the player’s current speed.
        //Pre-condition: none.
        //Post-condition: player’s current speed is returned.

        int Momentum() const;
        //Narrative: returns the player’s momentum.
        //Pre-condition: none.
        //Post-condition: player’s momentum is returned.

        int RollPhysDam() const;
        //Narrative: returns the player’s physical damage.
        //Pre-condition: none.
        //Post-condition: player’s physical damage is returned.

        int Defense() const;
        //Narrative: returns the player’s defense value.
        //Pre-condition: none.
        //Post-condition: player’s defense value is returned.

        int Dir() const;
        //Narrative: returns the player’s direction type.
        //Pre-condition: none.
        //Post-condition: player’s direction type is returned.

        bool IsAlive() const;
        //Narrative: checks to see if a player is still alive or not.
        //Pre-condition: none.
        //Post-condition: if player is alive, return true, if not return false.

        bool IsDead() const;
        //Narrative: checks to see if a player is dead or not
        //Pre-condition: none.
        //Post-condition: if player is dead, return true, else return false.

        bool IsActive() const;
        //Narrative: checks to see if a player is active or not
        //Pre-condition: none.
        //Post-condition: returns true if active, false otherwise.

        int WeaponSkill() const;
        //Narrative: returns the player’s weaponskill with current weapon
        //Pre-condition: none.
        //Post-condition: player’s weaponskill with current weapon is returned.

        bool HasWeapon() const;
        //Narrative: checks to see if a player has a weapon equipped
        //Pre-condition: none.
        //Post-condition: if player has a weapon currently equipped, return true, else
        //return false

        virtual void Write(ostream& out) const;
        //Narrative: outputs the player’s data
        //Pre-condition: out must be a valid ostream
        //Post-condition: player’s data successfully output to out

        int RollDice(GameSpace::RollType roll) const;





        //TRANSFORMERS

        bool Active();
        //Narrative: sets the player to be active
        //Pre-condition: none.
        //Post-condition: returns true unless player is dead and cannot be made active.

        bool InActive();
        //Narrative: set the player to be inactive
        //Pre-condition: none.
        //Post-condition: returns true indicating player is inactive

        bool Dead();
        //Narrative: sets attributes to 0 indicating the player is dead
        //Pre-condition: none.
        //Post-condition: returns true indicating a player is dead

        int Wounded(int damage);
        //Narrative: updates and returns the player’s health after taking damage
        //Pre-condition: none.
        //Post-condition: returns the updated health. If health is below 0, player is considered dead and inactive.

        int Invigorate(int vigor);
        //Narrative: updates and returns the player’s health after being invigorated
        //Pre-condition: vigor must be a valid int
        //Post-condition: returns the updated health

        bool Heal();
        //Narrative: heals a player if a turn is passed, also resets their current speed.
        //Pre-condition: none.
        //Post-condition: if the player can be healed, true is returned. Player values should be updated appropriately.

        int SlowDown(int hazard);
        //Narrative: updates and returns the player’s current speed
        //Pre-condition: none.
        //Post-condition: updated current speed is returned.

        int ResetCurrentSpeed();
        //Narrative: resets and returns current speed
        //Pre-condition: none.
        //Post-condition: returns the updated current speed

        int ResetMomentum();
        //Narrative: resets and returns momentum
        //Pre-condition: none.
        //Post-condition: returns the updated momentum

        int UseMomentum(int m);
        //Narrative: updates and returns the player’s momentum
        //Pre-condition: none.
        //Post-condition: returns the updated momentum

        int UpdateRage(int amount);
        //Narrative: Updates the player's rage value
        //Pre-condition: none
        //Post-condition: player's rage increases/decreases by amount passed in

        int UpdateDefense(int amount);
        //Narrative: Updates the player's defense value
        //Pre-condition: none
        //Post-condition: player's defense increases/decreases by amount passed in

        bool ImprovedSkill(int improvement);
        //Narrative: increases the skill of the currently equipped weapon
        //Pre-condition: player must be holding a weapon
        //Post-condition: the player's skill with that weapon is increased by the improvement amount

        Weapon * DropWeapon();
        //Narrative: a player drops the current weapon he has equipped
        //Pre-condition: none
        //Post-condition: weapon dropped is returned, or NULL is returned if inactive
        //or no weapon is equipped

        Weapon * GrabWeapon(Weapon* w);
        //Narrative: player picks up a weapon
        //Pre-condition: none
        //Post-condition: if player has skill with that weapon, this skill is used. If
        //the player is an agent, then they return their previously equipped weapon. If
        //the player is a criminal, the previous weapon is added to the arsenal.




        //COMBAT

        int HitScore() const;
        //Narrative: returns the player’s hit score
        //Pre-condition: none.
        //Post-condition: player’s hit score is returned.

        int HitDamage() const;
        //Narrative: returns the player’s hit damage
        //Pre-condition: none.
        //Post-condition: player’s hit damage is returned.

        int StrikeImpact() const;
        //Narrative: returns the player’s strike impact
        //Pre-condition: none.
        //Post-condition: player’s strike impact is returned.

        string WeaponName() const;
        //Narrative: returns the player’s weapon's name
        //Pre-condition: none.
        //Post-condition: player’s weapon's name is returned.

        bool MortalWound();
        //Narrative: processes a player that has suffered a mortal wound
        //Pre-condition: StrikeImpact() == -1
        //Post-condition: the player is either dead, or health, current speed, momentum, and willpower
        //are all altered. If the player is still alive, return true, false if dead.

        bool SetCell(int newRow, int newCol);
        //Narrative: updates the player’s current coordinates
        //Pre-condition: newRow/newCol must be valid ints
        //Post-condition: if coordinates are both > -1, coordinates are set. If both are -1, coordinates are set. Otherwise coordinates are not set.

        bool SetDir(DirType dir);
        //Narrative: updates the player’s direction
        //Pre-condition: dir must be a valid DirType
        //Post-condition: dir type is changed successfully, true is returned if new direciton




        bool Move();
        bool Move(int units);
        bool CanRun() const;
        bool Run();





        //Compare two players by name
        bool operator==(const Player& p) const;
        bool operator!=(const Player& p) const;
        bool operator<(const Player& p) const;
        bool operator>(const Player& p) const;
        bool operator<=(const Player& p) const;
        bool operator>=(const Player& p) const;

        bool IsMyEnemy(Player& p) const;

        //Agent Functions

        int Rank() const;
        //Narrative: returns the agent rank
        //Pre-condition: none.
        //Post-condition: agent rank returned
        string Rank_Str() const;
        //Narrative: returns the agent rank as a string
        //Pre-condition: none.
        //Post-condition: string representing rank returned

        int Level() const;
        //Narrative: returns the agent's level
        //Pre-condition: none.
        //Post-condition: agent level returned

        bool Promotion();
        //Narrative: gives a player a level promotion
        //Pre-condition: none
        //Post-condition: player is promoted, level is increased, health is increased, if level requires
        //a new rank, rank is increased

        //Criminal Functions

        int Wallet() const;
        //Narrative: returns the criminal's wallet
        //Pre-condition: none.
        //Post-condition: returns wallet value

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


        //Derived Functions

        string Type_Str() const;

        int Type() const;
        bool IsAgent() const;
        bool IsCriminal() const;

    private:

        PlayerClass* pcPtr;

};

ostream& operator<<(ostream& out, const Player& p);

#endif // HC4_H_INCLUDED
