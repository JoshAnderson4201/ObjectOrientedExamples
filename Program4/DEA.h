/* Josh Anderson
DEA.h */

#ifndef DEA_H_INCLUDED
#define DEA_H_INCLUDED
#include "Agent.h"

class DEA: public Agent
{
    public:
        DEA(string name, RankRules::RankType r = DEF_RANK);
        string Type_Str();
        void Write(ostream& out) const;
        virtual DEA* Clone() const;

    private:
        DEA();
        static int DICE[GameSpace::NUM_ROLL_TYPE][3];
        static const string TYPE;

};


#endif // DEA_H_INCLUDED
