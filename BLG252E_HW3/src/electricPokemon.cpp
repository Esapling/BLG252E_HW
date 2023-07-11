/* @Author Enes Fidan
 *	BLG 252E - Assignment 3
 *	Spring 2023
*/
#include "../include/electricPokemon.h"

ElectricPokemon::ElectricPokemon(const std::string& name, int hitPoints, int damage)
:Pokemon{name, hitPoints, damage, 0.2f, 3}
{  }

// setters

void ElectricPokemon::setTerrainState(bool terrainState) {
    // overrides base function so that immun state can also be assigned at the same time
    Pokemon::setTerrainState(terrainState);
    setImmuneState(terrainState); // if terrain state is true then immune state is also true, they are the same
}

void ElectricPokemon::setConfused(bool confusionAttack) {
    // this method sets the state m_isConfused to true or false 
    // by analyzing the immune state of the pokemon and number of round in a confusion state
    // it resets the number of round in confusion state to 0 if the pokemon is not in confusion
    // the number is not incremented here , its incremented in attack method so that for three rounds  
    // electric pokemon will not have any damage to its opponent
    
   
    if (m_isImmune) // if its immune then it cannot be confused
        m_isConfused = false;
    else 
    {
        if(m_NumRoundInConfusionState == 0) // if it is not in confusion it can be set to given state
            m_isConfused = confusionAttack; // set the state to the given value
        else 
        {
            if (m_NumRoundInConfusionState == 3) // if it waited enough then end the process
            {
                m_NumRoundInConfusionState = 0; // ends the process since it waited for three consecutive rounds
                m_isConfused = confusionAttack; // after 3rd round ,the opponent can still confuse the electric pokemon ,set it to the given state
            }
            else
                m_isConfused = true; // effect of confusion must continue for 3 rounds, doesnt matter what new attack is
        }
    }
    if (m_isConfused == false)
        m_NumRoundInConfusionState = 0;  // reset to 0 if its not in confusion
}



void ElectricPokemon::setImmuneState(bool immuneState) {
    // sets the immune state of the pokemon with given state
    m_isImmune = immuneState; 
}
// getters

int ElectricPokemon::Attack()
{
    // if its in confusion no damage a pokemon can give and returns 0 but it can still attempt to power up
    // else it can power up in that case it its regular damage multiplied by given factor 3 
    // otherwise it returns its regular damage
    
    attemptPowerUp(); // whether or not its confused 

    int damage_amount = getDamage();
    if (m_isConfused) {
        // if its confused then no damage it can give
        damage_amount = 0;
        ++m_NumRoundInConfusionState;

    } else if(isInPowerUp()) // if not then it can multiply its damage by 3 if its powered up
        damage_amount = getDamage() * 3;
    
    return damage_amount;
}
