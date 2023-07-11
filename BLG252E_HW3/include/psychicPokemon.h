/* @Author
 * Student Name:  Enes Fidan
 */

#ifndef __PHYSIC_POKEMON_H__
#define __PHYSIC_POKEMON_H__



#include <iostream>
#include "pokemon.h"

class PsychicPokemon : public Pokemon {
public:
    PsychicPokemon() = default;
    // constructor with parameters to initalize arguments
    PsychicPokemon(const std::string&, int, int);
    // setters
    void setConfusingAttackState(bool); // sets confusion attack state to the given value
    // getters
    bool isConfusing()const; // returns confusion attack state of the pokemon object
    int Attack();  // returns damage amount that a pokemon object will give in a round
private:
    bool m_isConfusing{false}; // a boolean which shows if the pokemon object has confusion attack
};

#endif