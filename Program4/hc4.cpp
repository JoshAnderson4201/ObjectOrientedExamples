#include "p3.h"
#include "hc4.h"
#include <typeinfo>

//Josh Anderson Handle .cpp

Player::Player(): pcPtr(NULL)
{

}

Player::Player(PlayerClass* p): pcPtr(p)
{


}

Player::Player(string name, PlayerType type, RankRules::RankType r): pcPtr(NULL)
{
   switch(type)
   {
        case cia: pcPtr = new CIA(name, r);
            break;
        case dea: pcPtr = new DEA (name, r);
            break;
        case nsa: pcPtr = new NSA(name, r);
            break;
        case drugdealer: pcPtr = new DrugDealer(name);
            break;
        case hitman: pcPtr = new HitMan(name);
            break;
        case loanshark: pcPtr = new LoanShark(name);
            break;
        default: pcPtr = new CIA(name, r);
   }
}

Player::Player(const Player& other):pcPtr(NULL)
{
    CopyIntoMe(other);
}

Player::~Player()
{
    delete pcPtr;
}

Player& Player::operator=(const Player& other)
{
    if (this != &other)
    {
        CopyIntoMe(other);
    }
    return *this;
}

void Player::CopyIntoMe(const Player& other)
{
    delete pcPtr;
    pcPtr = NULL;

    if (other.pcPtr)
        pcPtr = other.pcPtr->Clone();
}

string Player::Name() const
{
    cout << "Made it" << endl;
    if (pcPtr)
        return pcPtr->Name();
    return "";
}

int Player::Row() const
{
    if (pcPtr)
        return pcPtr->Row();
    return 0;
}

int Player::Col() const
{
    if (pcPtr)
        return pcPtr->Col();
    return 0;
}

int Player::Health() const
{
    if (pcPtr)
        return pcPtr->Health();
    return 0;
}

int Player::Rage() const
{
    if (pcPtr)
        return pcPtr->Rage();
    return 0;
}

int Player::WillPower() const
{
    if (pcPtr)
        return pcPtr->WillPower();
    return 0;
}

int Player::MaxSpeed() const
{
    if (pcPtr)
        return pcPtr->MaxSpeed();
    return 0;
}

int Player::CurrentSpeed() const
{
    if (pcPtr)
        return pcPtr->CurrentSpeed();
    return 0;
}

int Player::Momentum() const
{
    if (pcPtr)
        return pcPtr->Momentum();
    return 0;
}

int Player::RollPhysDam() const
{
    if (pcPtr)
        return pcPtr->RollPhysDam();
    return 0;
}

int Player::Defense() const
{
    if (pcPtr)
        return pcPtr->Defense();
    return 0;
}

int Player::Dir() const
{
    if (pcPtr)
        return pcPtr->Dir();
    return 0;
}

bool Player::IsAlive() const
{
    if (pcPtr)
        return pcPtr->IsAlive();
    return 0;
}

bool Player::IsDead() const
{
    if (pcPtr)
        return pcPtr->IsDead();
    return 0;
}

bool Player::IsActive() const
{
    if (pcPtr)
        return pcPtr->IsActive();
    return 0;
}

int Player::WeaponSkill() const
{
    if (pcPtr)
        return pcPtr->WeaponSkill();
    return 0;
}

bool Player::HasWeapon() const
{
    if (pcPtr)
        return pcPtr->HasWeapon();
    return 0;
}

void Player::Write(ostream& out) const
{
    if (pcPtr)
        pcPtr->Write(out);
}

int Player::RollDice(GameSpace::RollType roll) const
{
    if (pcPtr)
        return pcPtr->RollDice(roll);
    return 0;
}

bool Player::Active()
{
    if (pcPtr)
        return pcPtr->Active();
    return 0;
}

bool Player::InActive()
{
    if (pcPtr)
        return pcPtr->InActive();
    return 0;
}

bool Player::Dead()
{
    if (pcPtr)
        return pcPtr->Dead();
    return 0;
}

int Player::Wounded(int d)
{
    if (pcPtr)
        return pcPtr->Wounded(d);
    return 0;
}

int Player::Invigorate(int v)
{
    if (pcPtr)
        return pcPtr->Invigorate(v);
    return 0;
}

bool Player::Heal()
{
    if (pcPtr)
        return pcPtr->Heal();
    return 0;
}

int Player::SlowDown(int h)
{
    if (pcPtr)
        return pcPtr->SlowDown(h);
    return 0;
}

int Player::ResetCurrentSpeed()
{
    if (pcPtr)
        return pcPtr->ResetCurrentSpeed();
    return 0;
}

int Player::ResetMomentum()
{
    if (pcPtr)
        return pcPtr->ResetMomentum();
    return 0;
}

int Player::UseMomentum(int m)
{
    if (pcPtr)
        return pcPtr->UseMomentum(m);
    return 0;
}

int Player::UpdateRage(int a)
{
    if (pcPtr)
        return pcPtr->UpdateRage(a);
    return 0;
}

int Player::UpdateDefense(int a)
{
    if (pcPtr)
        return pcPtr->UpdateDefense(a);
    return 0;
}

bool Player::ImprovedSkill(int i)
{
    if (pcPtr)
        return pcPtr->ImprovedSkill(i);
    return 0;
}

Weapon * Player::DropWeapon()
{
    if (pcPtr)
        return pcPtr->DropWeapon();
    return NULL;
}

Weapon * Player::GrabWeapon(Weapon* w)
{
    if (pcPtr)
        return pcPtr->GrabWeapon(w);
    return w;
}

int Player::HitScore() const
{
    if (pcPtr)
        return pcPtr->HitScore();
    return 0;
}

int Player::HitDamage() const
{
    if (pcPtr)
        return pcPtr->HitDamage();
    return 0;
}

int Player::StrikeImpact() const
{
    if (pcPtr)
        return pcPtr->StrikeImpact();
    return 0;
}

string Player::WeaponName() const
{
    if (pcPtr)
        return pcPtr->WeaponName();
    return "";
}

bool Player::MortalWound()
{
    if (pcPtr)
        return pcPtr->MortalWound();
    return 0;
}

bool Player::SetCell(int nR, int nC)
{
    if (pcPtr)
        return pcPtr->SetCell(nR, nC);
    return 0;
}

bool Player::SetDir(GameSpace::DirType dir)
{
    if (pcPtr)
        return pcPtr->SetDir(dir);
    return 0;
}

bool Player::operator==(const Player& p) const
{
    if ((pcPtr) && (p.pcPtr))
        return *pcPtr == *p.pcPtr;
    return false;
}

bool Player::operator!=(const Player& p) const
{
    if ((pcPtr) && (p.pcPtr))
        return *pcPtr != *p.pcPtr;
    return false;
}

bool Player::operator < (const Player& p) const
{
    if ((pcPtr) && (p.pcPtr))
        return *pcPtr < *p.pcPtr;
    return false;
}

bool Player::operator > (const Player& p) const
{
    if ((pcPtr) && (p.pcPtr))
        return *pcPtr > *p.pcPtr;
    return false;
}

bool Player::operator<=(const Player& p) const
{
    if ((pcPtr) && (p.pcPtr))
        return *pcPtr <= *p.pcPtr;
    return false;
}

bool Player::operator>=(const Player& p) const
{
    if ((pcPtr) && (p.pcPtr))
        return *pcPtr >= *p.pcPtr;
    return false;
}

bool Player::IsMyEnemy(Player& p) const
{
    if (pcPtr)
        return pcPtr->IsMyEnemy(p.pcPtr);
    return false;
}

int Player::Rank() const
{
    Agent* aPtr = dynamic_cast<Agent*>(pcPtr);

    if (aPtr)
        return aPtr->Rank();
    return 0;
}

string Player::Rank_Str() const
{
    Agent* aPtr = dynamic_cast<Agent*>(pcPtr);

    if (aPtr)
        return aPtr->Rank_Str();
    return "";
}

int Player::Level() const
{
    Agent* aPtr = dynamic_cast<Agent*>(pcPtr);

    if (aPtr)
        return aPtr->Level();
    return 0;
}

bool Player::Promotion()
{
    Agent* aPtr = dynamic_cast<Agent*>(pcPtr);

    if (aPtr)
        return aPtr->Promotion();
    return 0;
}

int Player::Wallet() const
{
    Criminal* cPtr = dynamic_cast<Criminal*>(pcPtr);

    if (cPtr)
        return cPtr->Wallet();
    return 0;
}

vector <string> Player::Arsenal() const
{
    vector<string> v;
    Criminal* cPtr = dynamic_cast<Criminal*>(pcPtr);

    if (cPtr)
        return cPtr->Arsenal();
    return v;
}

int Player::UpdateWallet(int w)
{
    Criminal* cPtr = dynamic_cast<Criminal*>(pcPtr);

    if (cPtr)
        return cPtr->UpdateWallet(w);
    return 0;
}

bool Player::SwapWeapon(string w)
{
    Criminal* cPtr = dynamic_cast<Criminal*>(pcPtr);

    if (cPtr)
        return cPtr->SwapWeapon(w);
    return false;
}

Weapon* Player::BuyWeapon(Weapon* w)
{
    Criminal* cPtr = dynamic_cast<Criminal*>(pcPtr);

    if (cPtr)
        return cPtr->BuyWeapon(w);
    return w;
}

Weapon* Player::SellWeapon(string w)
{
    Criminal* cPtr = dynamic_cast<Criminal*>(pcPtr);

    if (cPtr)
        return cPtr->SellWeapon(w);
    return NULL;
}

string Player::Type_Str() const
{
    if (typeid(*pcPtr) == typeid(CIA))
        return "CIA";
    else if (typeid(*pcPtr) == typeid(DEA))
        return "DEA";
    else if (typeid(*pcPtr) == typeid(NSA))
        return "NSA";
    else if (typeid(*pcPtr) == typeid(DrugDealer))
        return "DRUGDEALER";
    else if (typeid(*pcPtr) == typeid(HitMan))
        return "HITMAN";
    else if (typeid(*pcPtr) == typeid(LoanShark))
        return "LOANSHARK";
    return "";
}

int Player::Type() const
{
    if (typeid(*pcPtr) == typeid(CIA))
        return cia;
    else if (typeid(*pcPtr) == typeid(DEA))
        return dea;
    else if (typeid(*pcPtr) == typeid(NSA))
        return nsa;
    else if (typeid(*pcPtr) == typeid(DrugDealer))
        return drugdealer;
    else if (typeid(*pcPtr) == typeid(HitMan))
        return hitman;
    else if (typeid(*pcPtr) == typeid(LoanShark))
        return loanshark;
    return 0;
}

bool Player::IsAgent() const
{
    if ((typeid(*pcPtr)== typeid(CIA)) || (typeid(*pcPtr)== typeid(DEA)) || (typeid(*pcPtr)== typeid(NSA)))
        return true;
    return false;
}

bool Player::IsCriminal() const
{
    if ((typeid(*pcPtr)== typeid(DrugDealer)) || (typeid(*pcPtr)== typeid(HitMan)) || (typeid(*pcPtr)== typeid(LoanShark)))
        return true;
    return false;
}

ostream& operator<<(ostream& out, const Player& p)
{
    p.Write(out);

    return out;
}

bool Player::Move()
{
    return false;
}

bool Player::Move(int units)
{
    return false;
}

bool Player::CanRun() const
{
    return true;
}

bool Player::Run()
{
    return false;
}
