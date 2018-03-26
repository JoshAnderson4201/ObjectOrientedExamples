#ifndef PLAYER1_H_INCLUDED
#define PLAYER1_H_INCLUDED
#include "gamespace.h"
#include "rank.h"
#include "dice.h"
#include <fstream>
#include <iostream>

using namespace GameSpace;
using namespace std;

class PlayerClass
{
    public:

        bool status;
        //Bool value representing if a player is Acitve or not

        enum PlayerType {CIA, DEA, NSA, DRUGDEALER, HITMAN, LOANSHARK};
        //Enumerator representing PlayerType

        enum PlayerStats {RAGE, MAXSPEED,  WILLPOWER, PHYSDAM, DEFENSE, LEVEL, HEALTH, WEAPONSKILL, CURRENTSPEED, MOMENTUM};
        //Enumerator representing Player stats for use in the stats array



        //Constructors
        PlayerClass();
        //Narrative: creates a new player.
        //Pre-condition: none.
        //Post-condition: a new Player object has been made.

        PlayerClass(string n);
        //Narrative: creates a new player, allows client to input a string for the player’s name.
        //Pre-condition: initName is a string.
        //Post-condition: a new Player object has been made and its name is initName.

        PlayerClass(string n, PlayerType t);
        //Narrative: creates a new player, allows client to input a string for the player’s name and a player type.
        //Pre-condition: name is a string, initType is a PlayerType.
        //Post-condition: a new Player object has been made and its name is initName and its type is initType.


        PlayerClass(string n, PlayerType t, RankRules::RankType r);
        //Narrative: creates a new player, allows client to input a string for the player’s name, a player type, and a player rank.
        //Pre-condition: name is a string, initType is a PlayerType, initRank is a RankType.
        //Post-condition: a new Player object has been made and its name is initName, its type is initType, and its rank is initRank.




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

        bool SetCell(int newRow, int newCol);
        //Narrative: updates the player’s current coordinates
        //Pre-condition: newRow/newCol must be valid ints
        //Post-condition: if coordinates are both > -1, coordinates are set. If both are -1, coordinates are set. Otherwise coordinates are not set.

        bool SetDir(DirType dir);
        //Narrative: updates the player’s direction
        //Pre-condition: dir must be a valid DirType
        //Post-condition: dir type is changed successfully, true is returned if new direciton




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


    private:

        string name;
        int row, col;
        PlayerType type;
        DirType direction;
        RankRules::RankType pRank;
        int stats[10];
        //Array of integers representing a player's stats
};

ostream& operator<<(ostream& out, const PlayerClass* c);
//Narrative: output the player data
//Pre-condition: out must be a valid ostream, c must be a valid player
//Post-condition: data is output in the correct format


#endif // PLAYER1_H_INCLUDED
