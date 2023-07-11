/* @Author
 * Student Name:  Enes Fidan
 */
#ifndef __POKEMON_H__
#define __POKEMON_H__

#include <iostream>

 // a super class which holds common attributes and methods like name
// hit points or related methods for different pokemon types
class Pokemon{ 
public:
    Pokemon() = default;
    // constructor with parameters
    Pokemon(const std::string& , int, int, float, int);

    // setters
    void setHitPoints(int); // sets the hp level after taking some damage from its opponent 
    void setPowerState(bool); // sets the info about whether a pokemon in Power Up state or not
    void setTerrainState(bool);


    //getters
    const std::string& getPokemonName() const; // returns Pokemon object's name
    bool getTerrainState()const ; // returns if a pokemon in its own terrain
    int getHitPoints() const; // returns Pokemon object's hp(hitPoints) at the moment
    int getDamage()const;  // returns the Regular amount of damage that A pokemon causes to its oppent
    float getPowerUpChance() const;  // returns the chance of a pokemon to power up 
    int getNumberOfRound() const; // returns how many rounds that a pokemon must wait to reattempt after powering up
    bool isInPowerUp() const; // returns boolean if a pokemon is currently in power up state
    bool checkAvailabilityPowerUp() const; // returns boolean if a pokemon is suitable to power up
    
    
    void attemptPowerUp(); // pokemon object tries to power up if it is meeting the some conditions

private:
    const std::string m_PokemonName;
    int m_HitPoints; // lifeline of a pokemon 
    const int m_Damage; // how much Regular damage a pokemon causes to its po
    const float m_PowerUpChance; // a float represents chance of a pokemon to power up
    const int m_Recharge;  // round number that a pokemon must wait after a successfull power up
    int m_NumRoundPassedAfterPowerUp{0}; //a number that  shows how many rounds passed after a power up
    bool m_IsInPowerUp{false}; // bolean represents if a pokemon is in power up
    bool m_isInTerrain{false}; // a boolean shows a pokemon object in its terrain

};





#endif