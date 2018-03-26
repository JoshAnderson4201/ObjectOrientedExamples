/* Josh Anderson
NSA.h */

#ifndef NSA_H_INCLUDED
#define NSA_H_INCLUDED
#include "Agent.h"

class NSA: public Agent
{
    public:
        NSA(string name, RankRules::RankType r = DEF_RANK);
        string Type_Str();
        void Write(ostream& out) const;
        virtual NSA* Clone() const;

    private:
        NSA();
        static int DICE[GameSpace::NUM_ROLL_TYPE][3];
        static const string TYPE;

};

#endif // NSA_H_INCLUDED
