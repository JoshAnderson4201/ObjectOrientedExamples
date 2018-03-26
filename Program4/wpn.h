// wpn.h
// Weapon class for the cops and robbers game


#ifndef _WPN
#define _WPN

#include <string>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

class Weapon
{
  public:

   //*************************************************** Static Methods
    static int LookUpCost(string weaponName);
    // Looks up the cost of a specific wpn
    // pre:  name should be the name of an wpn
    // post: returns the cost of the wpn, zero if not found
    
    
    static bool IsMelee(string weaponName);
    // Returns true if the weapon is melee
    // pre:  none
    // post: returns true if weapon is melee and false otherwise

    static bool IsRange(string weaponName);
    // Returns true if the weapon is range
    // pre:  none
    // post: returns true if weapon is range and false otherwise
    
    
   //*************************************************** Instance Methods
    Weapon(const string wpn);
    // constructor must have name of weapon spelled correctly
    // pre:  wpn must have a name
    // post: wpn is created, if not a match then pistol is set
    
    string Name( ) const;
    // Returns the name of the weapon
    // pre:  none
    // post: name is returned

    int Cost( ) const;
    // Returns the wpn cost
    // pre: none
    // post: the wpn cost is returned
    
    int Range( ) const;
    // Returns the range of the weapon
    // pre:  none
    // post: range of wpn is returned
    
    int RollDamage(string PlayerName ) const;
    // Returns the damage rolled
    // pre:  Must know player's name
    // post: damage is rolled and returned
    
    int Power( ) const;
    // Returns the power of the wpn
    // pre:  none
    // post: power of wpn is returned

    bool IsMelee( ) const;
    // Returns true if the weapon is melee
    // pre:  none
    // post: returns true if weapon is melee and false otherwise

    bool IsRange( ) const;
    // Returns true if the weapon is range
    // pre:  none
    // post: returns true if weapon is range and false otherwise

    void Write(ostream& out) const;
    // Writes the wpn data to an output stream
    // order:
    //       name#type#cost#range#damage#power#
    //         ** type is printed as a string
    //         ** damage is printed as a xd6
    // pre:  stream must be open, headers already printed
    //       if necessary.
    // post: all member data in the wpn object has been inserted
    //       into output stream.



//*******relational operators
    // Relational operators comparing name
    bool operator==(const Weapon &w) const;
    bool operator!=(const Weapon &w) const;
    bool operator<(const Weapon &w) const;
    bool operator<=(const Weapon &w) const;
    bool operator>(const Weapon &w) const;
    bool operator>=(const Weapon &w) const;

    
    

  private:
  
//*******DATA TYPES

    enum WpnType {MELEE, RANGE};    		// type of weapon available

    struct WpnRec				// record for storing wpn data
    {
       WpnType type;
       int cost;
       int range;
       int damage;
       int power;
    };

//*******Private METHODS
    Weapon( );
    // default constructor cannot be used
    
    static void Load( );
    // loads the data from the weapon files
    // pre:  none
    // post: map is loaded

    static bool Read(istream& stream,string& name, WpnRec& data);
    // Reads the wpn object data from an input stream
    // order:
    //       name#type#cost#range#damage#power#
    // pre:  stream must be open.
    // post: data extracted from stream,
    //       if valid - data members have updated value, return true
    //       else data members unchanged, return false

//*******CLASS DATA

    
    static  map<string,WpnRec> wpns;   	// table of wpn data

    static const string DEF_NAME; 		// weapon used for invalid weapon name
    static const int DAM_DICE;    		// dice rolled for weapon damage


//********INSTANCE DATA    
    string name;		  		// name of wpn

};
    
#endif

