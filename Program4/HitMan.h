/* Josh Anderson
HitMan.h */

#ifndef HITMAN_H_INCLUDED
#define HITMAN_H_INCLUDED
#include "Criminal.h"

class HitMan: public Criminal
{
    public:
        HitMan(string name);
        string Type_Str();
        void Write(ostream& out) const;
        virtual HitMan* Clone() const;

    private:
        HitMan();
        static int DICE[GameSpace::NUM_ROLL_TYPE][3];
        static const string TYPE;

};
#endif // HITMAN_H_INCLUDED
