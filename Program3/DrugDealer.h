/* Josh Anderson
DrugDealer.h */

#ifndef DRUGDEALER_H_INCLUDED
#define DRUGDEALER_H_INCLUDED
#include "Criminal.h"

class DrugDealer: public Criminal
{
    public:
        DrugDealer(string name);
        string Type_Str();
        void Write(ostream& out) const;

    private:
        DrugDealer();
        static int DICE[GameSpace::NUM_ROLL_TYPE][3];
        static const string TYPE;

};

#endif // DRUGDEALER_H_INCLUDED
