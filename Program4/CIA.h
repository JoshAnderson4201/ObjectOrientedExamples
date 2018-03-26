/* Josh Anderson
CIA.cpp */

#ifndef CIA_H_INCLUDED
#define CIA_H_INCLUDED
#include "Agent.h"
#include "rank.h"

class CIA: public Agent
{
    public:
        CIA(string name, RankRules::RankType r = DEF_RANK);
        string Type_Str();
        void Write(ostream& out) const;
        virtual CIA* Clone() const;

    private:
        CIA();
        static int DICE[GameSpace::NUM_ROLL_TYPE][3];
        static const string TYPE;

};

#endif // CIA_H_INCLUDED
