/* @Author
 * Student Name:  Enes Fidan
 */

#ifndef __ELECTRIC_POKEMON_H__
#define __ELECTRIC_POKEMON_H__

#include <iostream>
#include "pokemon.h"

class ElectricPokemon :  public Pokemon {
public:
    ElectricPokemon() = default;
    // constructor with parameters to initalize arguments
    ElectricPokemon(const std::string&,int , int);
    // setters
    void setTerrainState(bool); // overrided base function to add some extra functionality 
    void setConfused(bool); // sets the confusion state of the pokemon object 
    void setImmuneState(bool); // sets the immune state of the pokemon object
    
    //no getters needed
    
    int Attack();// returns damage amount that a pokemon object will give in a round


private:
    bool m_isConfused{false}; // no confusion at the beginning
    bool m_isImmune{false}; // no immunation at the beginning
    int m_NumRoundInConfusionState{0}; // shows how many rounds passed after a pokemon object confused
};

#endif