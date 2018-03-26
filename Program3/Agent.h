#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED
#include "rank.h"
#include "PlayerClass.h"


class Agent: public PlayerClass
{
    public:
        Agent();
        Agent(string name, RankRules::RankType r, int DICE[][3]);

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

        bool IsMyEnemy(PlayerClass* p) const;
        //Narrative: checks to see if p is an enemy of agent
        //Pre-condition: none.
        //Post-condition: if p is not a fellow agent, true is returned. Else
        //false is returned.

        bool Promotion();
        //Narrative: gives a player a level promotion
        //Pre-condition: none
        //Post-condition: player is promoted, level is increased, health is increased, if level requires
        //a new rank, rank is increased

        void Write(ostream& out) const;

    protected:
        static const RankRules::RankType DEF_RANK;

    private:
        void SetRank(RankRules::RankType r);

        static const int DEF_LEVEL = 1;
        RankRules::RankType pRank;
        int level;
        int DICE [GameSpace::NUM_ROLL_TYPE][3];
};

#endif // AGENT_H_INCLUDED
