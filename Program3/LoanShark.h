/* Josh Anderson
LoanShark.h */

#ifndef LOANSHARK_H_INCLUDED
#define LOANSHARK_H_INCLUDED
#include "Criminal.h"

class LoanShark: public Criminal
{
    public:
        LoanShark(string name);
        string Type_Str();
        void Write(ostream& out) const;

    private:
        LoanShark();
        static int DICE[GameSpace::NUM_ROLL_TYPE][3];
        static const string TYPE;

};

#endif // LOANSHARK_H_INCLUDED
