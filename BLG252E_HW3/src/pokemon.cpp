/* @Author Enes Fidan
 *	BLG 252E - Assignment 3
 *	Spring 2023
*/
#include "../include/pokemon.h"
Pokemon::Pokemon(const std::string& name, int hit_point, int damage_amount,  float powerUp, int recharge)
: m_PokemonName{name}, m_HitPoints{hit_point}, m_Damage{damage_amount}, m_PowerUpChance{powerUp},
m_Recharge{recharge}
{ }

// setters
void Pokemon::setHitPoints(int damageTaken){
    // sets the amount of life points left after taking damages from an opponent
    m_HitPoints -= damageTaken;
    if (m_HitPoints < 0)
        m_HitPoints = 0; // not logical to have negative life points
}

void Pokemon::setPowerState(bool PowerUpState) {
    // sets pokemon's PowerUp state to the given state 
    m_IsInPowerUp = PowerUpState; 
}
void Pokemon::setTerrainState(bool terrainState) {
    // sets the terrain state which shows if a pokemon is in its terrain or not
    m_isInTerrain = terrainState;
}


// getters
const std::string& Pokemon::getPokemonName() const{
    // a const method returns the name of the pokemon
    return m_PokemonName;
}

int Pokemon::getHitPoints() const{
    // a const method returns how many hit points left 
    return m_HitPoints;
}
int Pokemon::getDamage()const{
    // a const method that returns the amount of damages that a pokemon can give
    return m_Damage;
}

float Pokemon::getPowerUpChance() const{
    // a const method that returns the power up fraction which defines a pokemone's ability of increasing its power
    return m_PowerUpChance;
}

int Pokemon::getNumberOfRound() const{
    // a const method that returns how many round it takes for a pokemon to attempt powering up
    return m_Recharge;
}

bool Pokemon::isInPowerUp() const{
    // a const method that returns if a pokemon object is in powerup state or not
    return m_IsInPowerUp;
}
bool Pokemon::getTerrainState() const {
    // a const method that returns if a pokemon object is in its terrain
    return m_isInTerrain;
}

bool Pokemon::checkAvailabilityPowerUp() const{
    // checks if a pokemon is waited enough before its next power up attempt
    // if its first round or it waited more than 3 round than returns true meaining its 'available'
    return (m_NumRoundPassedAfterPowerUp == 0 || m_NumRoundPassedAfterPowerUp > m_Recharge); 
    
}

void Pokemon::attemptPowerUp(){
    //this method lets a pokemon tries to power up
    // if it gets 1 then it powers up and it updates its  

    bool powerUp_state; // a boolean value that states if the pokemon poweredUp or not
    if(checkAvailabilityPowerUp())
    {
        float chance = getPowerUpChance(); 
        bool WinWin = (rand() % 100) <= (chance *100) ; // a random number between 0 to 99
        if (WinWin)  // if winwin percent is smaller than chance that means our chance realized 
        {
            powerUp_state = true;
            m_NumRoundPassedAfterPowerUp = 1; // first round in PowerUp init to 1 not 0 because 0 represents the very first trial and other possible cases
        }
        else
        {
            powerUp_state = false;
            m_NumRoundPassedAfterPowerUp = 0; // pokemon was able to power up but it couldnt , so in the next round it can still try
        }
    }
    else{
        ++m_NumRoundPassedAfterPowerUp; // pokemon wasnt allowed to power up since it didnt wait enough so continue increment the value
        powerUp_state = false;
    }
    setPowerState(powerUp_state);
}


