/* @Author Enes Fidan
 *	BLG 252E - Assignment 3
 *	Spring 2023
*/
#include "../include/psychicPokemon.h"

PsychicPokemon::PsychicPokemon(const std::string& name, int hitPoints, int damage)
:Pokemon{name,hitPoints, damage, 0.3f, 5}
{ }

void PsychicPokemon::setConfusingAttackState(bool confusionState) {
    // sets the state showing if a psychic pokemon can confuse its opponent 
    m_isConfusing = confusionState;
}

bool PsychicPokemon::isConfusing() const{
    // returns a boolean that shows if a pokemon can confuse its oppoenent 
    return m_isConfusing;
}


int PsychicPokemon::Attack() {
    
    attemptPowerUp();
    if (isInPowerUp()) // if it is in power up state it confuses its opponent
        setConfusingAttackState(true);
    else // otherwise it cannot confuse its opponent
        setConfusingAttackState(false);

    int damage_amount = getDamage(); // gets regular damage amounnt
    if (getTerrainState()) // if it is its own terraing its damage multiplied by 2
        damage_amount *= 2;
    
    return damage_amount;
}
