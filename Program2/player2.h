#ifndef PLAYER2_H_INCLUDED
#define PLAYER2_H_INCLUDED
#include "gamespace.h"
#include "rank.h"
#include "dice.h"
#include "wpn.h"
#include<vector>
#include<map>
#include <fstream>
#include <iostream>

using namespace GameSpace;
using namespace std;

class PlayerClass
{
    public:

        enum PlayerType {CIA, DEA, NSA, DRUGDEALER, HITMAN, LOANSHARK};
        //Enumerator representing PlayerType

        enum PlayerStats {RAGE, MAXSPEED,  WILLPOWER, PHYSDAM, DEFENSE, LEVEL, HEALTH, WEAPONSKILL, CURRENTSPEED, MOMENTUM};
        //Enumerator representing Player stats for use in the stats array


        //Constructor
        PlayerClass(string initName, PlayerType initType = CIA, RankRules::RankType initRank = RankRules::ROOKIE);
        //Narrative: creates a new player, allows client to input a string for the player’s name, a player type, and a player rank.
        //Pre-condition: name is a string, initType is a PlayerType, initRank is a RankType.
        //Post-condition: a new Player object has been made and its name is initName, its type is initType, and its rank is initRank.

        //Copy Constructor
        PlayerClass(const PlayerClass& p);

        //Destructor
        ~PlayerClass();

        //Overloaded Assignment Operator
        PlayerClass operator =(const PlayerClass& p);




        //Helper Functions
        void EmptyArsenal(vector <Weapon*> arsenal);
        //Narrative: Empties the passed in arsenal
        //Pre-condition: a vector of Weapon pointers must be created
        //Post-condition: the vector is empty

        void CopyArsenal(vector <Weapon*> arsenal);
        //Narrative: Copies the arsenal passed in
        //Pre-condition: a vector of Weapon pointers must be created
        //Post-condition: the vector is copied into a new vector

        void CopyIntoMe(const PlayerClass& p);
        //Narrative: Copies all of the fields of a player into a new player object
        //Pre-condition: a player must exist to be copied from
        //Post-condition: new player has the same data as the other player, with its
        //own memory addresses for dynamic data

        void CopyStats(const PlayerClass& p);
        //Narrative: Copies player stats
        //Pre-condition: a player object with stats must exist
        //Post-condition: old player stats are copied into the new player

        string Upper(const string s) const;
        //Narrative: Converts a string to uppercase
        //Pre-condition: none
        //Post-condition: the string is returned in uppercase

        int LookUpSkill(Weapon* w) const;
        //Narrative: looks up the skill level of a certain weapon
        //Pre-condition: weapon can't be NULL, and a weapon history must exist
        //Post-condition: the player's skill with that weapon is returned



        //Transformers
        void SetName(string n);
        //Narrative: Sets the player’s name
        //Pre-condition: none.
        //Post-condition: player’s name is updated

        void SetType(PlayerType t);
        //Narrative: sets the player’s type
        //Pre-condition: none.
        //Post-condition: player’s type is updated.

        void SetRank(RankRules::RankType r);
        //Narrative: sets the player’s rank
        //Pre-condition: none.
        //Post-condition: player’s rank is updated.

        void SetStats(int h, int l);
        //Narrative: sets the player’s stats
        //Pre-condition: none.
        //Post-condition: player’s stats are updated.

        void SetStatus(int w);
         //Narrative: sets the player’s status
        //Pre-condition: none.
        //Post-condition: player’s status is updated.

        bool SetCell(int newRow, int newCol);
        //Narrative: updates the player’s current coordinates
        //Pre-condition: newRow/newCol must be valid ints
        //Post-condition: if coordinates are both > -1, coordinates are set. If both are -1, coordinates are set. Otherwise coordinates are not set.

        bool SetDir(DirType dir);
        //Narrative: updates the player’s direction
        //Pre-condition: dir must be a valid DirType
        //Post-condition: dir type is changed successfully, true is returned if new direciton

        int UpdateRage(int amount);
        //Narrative: Updates the player's rage value
        //Pre-condition: none
        //Post-condition: player's rage increases/decreases by amount passed in

        int UpdateDefense(int amount);
        //Narrative: Updates the player's defense value
        //Pre-condition: none
        //Post-condition: player's defense increases/decreases by amount passed in

        int UpdateWallet(int amount);
        //Narrative: Updates the player's wallet value
        //Pre-condition: none
        //Post-condition: player's wallet increases/decreases by amount passed in




        //Observers
        string Name() const;
        //Narrative: returns the player’s name.
        //Pre-condition: none.
        //Post-condition: player’s name is returned to the client.

        int Health() const;
        //Narrative: returns the player’s health.
        //Pre-condition: none.
        //Post-condition: player’s health is returned to the client.

        int Type() const;
        //Narrative: returns the player’s type.
        //Pre-condition: none.
        //Post-condition: player’s type is returned to the client.

        string Type_Str() const;
        //Narrative: returns the player’s type as a string.
        //Pre-condition: none.
        //Post-condition: player’s type is returned as the corresponding string.

        int WillPower() const;
        //Narrative: returns the player’s will power.
        //Pre-condition: none.
        //Post-condition: player’s will power is returned to the client.

        int Rank() const;
        //Narrative: returns the player’s rank.
        //Pre-condition: none.
        //Post-condition: player’s rank is returned as the corresponding string.

        string Rank_Str() const;
        //Narrative: returns the player’s rank as a string.
        //Pre-condition: none.
        //Post-condition: player’s name is returned to the client.

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

        int Rage() const;
        //Narrative: returns the player’s rage.
        //Pre-condition: none.
        //Post-condition: player’s rage is returned.

        int Level() const;
        //Narrative: returns the player’s level.
        //Pre-condition: none.
        //Post-condition: player’s level is returned.

        int RollPhysDam() const;
        //Narrative: returns the player’s physical damage.
        //Pre-condition: none.
        //Post-condition: player’s physical damage is returned.

        int Row() const;
        //Narrative: returns the player’s row.
        //Pre-condition: none.
        //Post-condition: player’s row is returned.

        int Col() const;
        //Narrative: returns the player’s col.
        //Pre-condition: none.
        //Post-condition: player’s col is returned.

        int Defense() const;
        //Narrative: returns the player’s defense value.
        //Pre-condition: none.
        //Post-condition: player’s defense value is returned.

        int Dir() const;
        //Narrative: returns the player’s direction type.
        //Pre-condition: none.
        //Post-condition: player’s direction type is returned.

        int Status() const;
        //Narrative: returns the player’s status
        //Pre-condition: none.
        //Post-condition: player’s status is returned

        int Wallet() const;
        //Narrative: returns the player’s wallet amount
        //Pre-condition: none.
        //Post-condition: player’s wallet amount is returned.

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

        int WeaponSkill() const;
        //Narrative: returns the player’s weaponskill with current weapon
        //Pre-condition: none.
        //Post-condition: player’s weaponskill with current weapon is returned.

        bool HasWeapon() const;
        //Narrative: checks to see if a player has a weapon equipped
        //Pre-condition: none.
        //Post-condition: if player has a weapon currently equipped, return true, else
        //return false

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

        bool Agent() const;
        //Narrative: determines if a player is an agent or not.
        //Pre-condition: none.
        //Post-condition: if the player is an agent, return true, else return false.

        bool Criminal() const;
        //Narrative: determines if a player is a criminal or not.
        //Pre-condition: none.
        //Post-condition: if the player is a criminal, return true, else return false.

        bool IsMyEnemy(PlayerClass* p) const;
        //Narrative: checks to see if a player is an enemy or not
        //Pre-condition: none.
        //Post-condition: returns true if p is an enemy, false otherwise.

        void Write(ostream& out) const;
        //Narrative: outputs the player’s data
        //Pre-condition: out must be a valid ostream
        //Post-condition: player’s data successfully output to out




        bool Heal();
        //Narrative: heals a player if a turn is passed, also resets their current speed.
        //Pre-condition: none.
        //Post-condition: if the player can be healed, true is returned. Player values should be updated appropriately.

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

        int Wounded(int damage);
        //Narrative: updates and returns the player’s health after taking damage
        //Pre-condition: none.
        //Post-condition: returns the updated health. If health is below 0, player is considered dead and inactive.

        int Invigorate(int vigor);
        //Narrative: updates and returns the player’s health after being invigorated
        //Pre-condition: vigor must be a valid int
        //Post-condition: returns the updated health

        bool Promotion();
        //Narrative: gives a player a level promotion
        //Pre-condition: none
        //Post-condition: player is promoted, level is increased, health is increased, if level requires
        //a new rank, rank is increased

        bool MortalWound();
        //Narrative: processes a player that has suffered a mortal wound
        //Pre-condition: StrikeImpact() == -1
        //Post-condition: the player is either dead, or health, current speed, momentum, and willpower
        //are all altered. If the player is still alive, return true, false if dead.

        bool ImprovedSkill(int improvement);
        //Narrative: increases the skill of the currently equipped weapon
        //Pre-condition: player must be holding a weapon
        //Post-condition: the player's skill with that weapon is increased by the improvement amount

        Weapon * DropWeapon();
        //Narrative: a player drops the current weapon he has equipped
        //Pre-condition: none
        //Post-condition: weapon dropped is returned, or NULL is returned if inactive
        //or no weapon is equipped

        Weapon * GrabWeapon(Weapon* weapon);
        //Narrative: player picks up a weapon
        //Pre-condition: none
        //Post-condition: if player has skill with that weapon, this skill is used. If
        //the player is an agent, then they return their previously equipped weapon. If
        //the player is a criminal, the previous weapon is added to the arsenal.

        bool Move();
        bool Move(int units);
        bool CanRun() const;
        bool Run();

        //Compare two players by name
        bool operator==(const PlayerClass& p) const;
        bool operator!=(const PlayerClass& p) const;
        bool operator<(const PlayerClass& p) const;
        bool operator>(const PlayerClass& p) const;
        bool operator<=(const PlayerClass& p) const;
        bool operator>=(const PlayerClass& p) const;


    private:

        PlayerClass();
        //Narrative: creates a new player.
        //Pre-condition: none.
        //Post-condition: a new Player object has been made.

        bool status;
        //Bool value representing if a player is Acitve or not

        string name;
        int row, col, wallet, weaponSkill;
        PlayerType type;
        DirType direction;
        RankRules::RankType pRank;
        int stats[10];
        //Array of integers representing a player's stats

        Weapon* weapon;
        vector <Weapon*> arsenal;
        map<string, int> history;
};

ostream& operator<<(ostream& out, const PlayerClass* c);
//Narrative: output the player data
//Pre-condition: out must be a valid ostream, c must be a valid player
//Post-condition: data is output in the correct format


#endif // PLAYER1_H_INCLUDED
