/* @Author
 * Student Name:  Enes Fidan
 */

#ifndef __ARENA_H__
#define __ARENA_H__

#include <iostream>
#include "electricPokemon.h"
#include "psychicPokemon.h"

class Arena{
public:
    Arena() =default;
    void addPokemon(char , const std::string& , int , int); // adds a pokemon to the battle arena
	void simulateBattle(); // simulates battle 
    // setters
    void setPokemonsTerrainState(); // sets pokemon terrain states
    void setNumRoundInATerrain(); // set the number m_RoundInATerrain accordingly

    
    bool endGame(const Pokemon*); // returns true if one of the pokemon objects' hp is 0
    
    bool checkTerrainSpawnNecessary(); // returns true if there is a need to spawn terrain
    void spawnTerrain(); // spawns a terrain before battle
    void restartTerrain(); // under some condition , spawns a new terrain in the battle
    
    void printRoundStats(int, int)const; // prints information about the game
    void printMatchResults()const; // prints the result of the game at the end of each battle

    ~Arena(); // destructor to delete pointer objects
private:
    // two pokemon objects for battling in the arena 
    ElectricPokemon* m_ElectricPokemon{NULL};
    PsychicPokemon* m_PsychicPokemon{NULL};
    
    std::string m_TerrainType; // keeps the name of the current terrain in the arena
    int m_NumRoundInATerrain{0}; // an int value to keep track of the number of rounds when the arena in a certain terrain
};


#endif