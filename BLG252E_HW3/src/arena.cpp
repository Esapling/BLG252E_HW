/* @Author Enes Fidan
 *	BLG 252E - Assignment 3
 *	Spring 2023
*/
#include "../include/arena.h"

void Arena::addPokemon(char pokemonType, const std::string& pokemon_name, int HP, int damage) {
	// no need to restart terrain twice if its the first time of adding pokemons to the arena
	if (m_ElectricPokemon != NULL && m_PsychicPokemon != NULL)
		restartTerrain();

	if (pokemonType == 'e')
	{
		if (m_ElectricPokemon == NULL)
			m_ElectricPokemon = new ElectricPokemon{ pokemon_name,HP, damage };
		else {
			delete m_ElectricPokemon; //if another pokemon enters the battle while there's already of the same type then delete the first one 
			m_ElectricPokemon = new ElectricPokemon{ pokemon_name,HP, damage };
		}
		// prompt an info that a pokemon entered to the arena
		std::cout << "\n\nElectric Pokemon " << pokemon_name << " has entered the arena." << std::endl;
		std::cout << "Class: Electric\n Name: " << pokemon_name << "\nHp: " << HP << "\nDamage: " << damage << std::endl;
	}
	else if (pokemonType == 'p') {
		if (m_PsychicPokemon == NULL)
			m_PsychicPokemon = new PsychicPokemon{ pokemon_name,HP, damage };
		else {
			delete m_PsychicPokemon;// if another pokemon enters the battle while there's already of the same type then delete the first one
			m_PsychicPokemon = new PsychicPokemon{ pokemon_name,HP, damage };
		}
		// prompt an info that a pokemon entered to the arena
		std::cout << "\n\nPsychic Pokemon " << pokemon_name << " has entered the arena." << std::endl;
		std::cout << "Class: Psychic\nName: " << pokemon_name << "\nHp: " << HP << "\nDamage: " << damage << "\n" << std::endl;
	}
}
void Arena::spawnTerrain()
{
	//this method spawns a terrain of three type in the arena by a certain chance
	int chance = rand() % 100;
	if (chance < 20) // 20% possibilty of being an electric terrain
		m_TerrainType = "electric";
	else if (20 <= chance && chance< 40) // 20% possiblity of being a psychic terrain
		m_TerrainType = "psychic";
	else
		m_TerrainType = "none"; // 60% possiblity of being none 
}
void Arena::restartTerrain() {
	// this method restarts the terrain type after a new pokemon enters the arena 
	spawnTerrain();
	setPokemonsTerrainState();
}
void Arena::setPokemonsTerrainState() {
	// this method sets the terrain states of each pokemon accordingly when new spawning occurs in a battle 
	if (m_TerrainType.compare("electric") == 0)
	{
		m_ElectricPokemon->setTerrainState(true);
		m_PsychicPokemon->setTerrainState(false);
	}
	else if (m_TerrainType.compare("psychic") == 0)
	{
		m_ElectricPokemon->setTerrainState(false);
		m_PsychicPokemon->setTerrainState(true);
	}
	else {
		m_ElectricPokemon->setTerrainState(false);
		m_PsychicPokemon->setTerrainState(false);
	}
}
void Arena::setNumRoundInATerrain() {
	// sets the number of round value which shows that there is a certain terrain in the arena currently
	if (m_TerrainType.compare("none") != 0)
		++m_NumRoundInATerrain; // increment the number by one if pokemons in a certain terrain
	else {
		m_NumRoundInATerrain = 0;  // reset the number if there is no terrain in the arena currently
	}
}
void Arena::printRoundStats(int num_round, int heads)const {
	// this method informs user printing the current status of pokemons in the arena with the current round number
	std::cout << "\n\nRound: " << num_round << std::endl;
	std::cout << "Current Terrain: " << m_TerrainType << std::endl;
	// which one attacks first
	if (heads == 0)
		std::cout << m_ElectricPokemon->getPokemonName() << " goes first." << std::endl;
	else
		std::cout << m_PsychicPokemon->getPokemonName() << " goes first." << std::endl;

	// if one of them has initiated a power up
	if (m_ElectricPokemon->isInPowerUp())
		std::cout << m_ElectricPokemon->getPokemonName() << " has initiated a power up." << std::endl;
	if (m_PsychicPokemon->isInPowerUp())
		std::cout << m_PsychicPokemon->getPokemonName() << " has initiated a power up." << std::endl;

	// their current status 
	std::cout << m_ElectricPokemon->getPokemonName() << " HP: " << m_ElectricPokemon->getHitPoints() << std::endl;
	std::cout << m_PsychicPokemon->getPokemonName() << " HP: " << m_PsychicPokemon->getHitPoints() << std::endl;

	// which one has more hp 
	if (m_ElectricPokemon->getHitPoints() >= m_PsychicPokemon->getHitPoints())
		std::cout << m_ElectricPokemon->getPokemonName() << " is in the lead." << std::endl;
	else
		std::cout << m_PsychicPokemon->getPokemonName() << " is in the lead" << std::endl;
}
void Arena::printMatchResults()const {
	// this method prints the result of the game and prompts the winner
	// since one of them goes first , not possible to have a draw case
	std::cout << "\n\nMatch Results: " << std::endl;
	if (m_ElectricPokemon->getHitPoints() == 0)
		std::cout << m_PsychicPokemon->getPokemonName() << " has won the match." << std::endl;
	else
		std::cout << m_ElectricPokemon->getPokemonName() << " has won the match." << std::endl;
}

bool Arena::checkTerrainSpawnNecessary(){
/*
// this method checks if there is a need to spawn terrain
// if terrain is none the number is reset to 0 otherwise it is incremented
// when there is none terrain or after 5 round in a certain terrain like electric or psychic, spawning is necessary
// resetting it to 0 in none terrain and incrementing it otherwise allows us to apply modulo 5 logic
// so there will be no problem in cases like after first three none terrain in a battle modulo 5 logic will be applicable 
// 0001...5 
// if its modulo 5 is 0 then , 5 round successively passed in the arena with a psychic or electric terrain so we need to spawn again
// even if it spawns an electric terrain after a psychich terrain or vice versa, modulo 5 logic is valid like 1..'5'..6..'10' 
// in the first round a terrain will be spawned since the number is 0 
*/
	if (m_NumRoundInATerrain == 0 || m_NumRoundInATerrain % 5 == 0)	
		return true;
	
	return false;
	
}

bool Arena::endGame(const Pokemon* ptr) {
	// this method takes Pokemon objects (either electric or psychic) and checks their life points
	// if its 0 returns true , false otherwise
	if (ptr->getHitPoints() == 0)
		return true;
	else
		return false;
}

void Arena::simulateBattle() {
	// this method runs a simulation of a battle of two different pokemon types
	if (m_ElectricPokemon == NULL || m_PsychicPokemon == NULL) // if there is no pokemon in the arena properly then returns void
		return;

	int chance; // chance = 0 electric goes first, otherwise psychic
	int num_round = 0; // number of round in a battle
	int damage_electric = 0; // amount of damage given by electric pokemon
	int damage_psychic = 0;// amount of damage given by psychic pokemon

	bool game_is_on = true; // a boolean that will carry out the game 
	bool confusionAttack; // a boolean that shows if a psychic pokemon has confusion attack

	while (game_is_on)
	{
		++num_round;
		if (checkTerrainSpawnNecessary())
		{
			spawnTerrain();
			setPokemonsTerrainState();
		}
		setNumRoundInATerrain();

		chance = rand() % 2;
		if (chance == 0) // probabilty 1/2 of being first attacker for electric or psychich 
		{
			// first electric attacks
			damage_electric = m_ElectricPokemon->Attack();
			m_PsychicPokemon->setHitPoints(damage_electric); 
			
			// after each attack check for dead state or end of the battle 
			if (endGame(m_PsychicPokemon))
			{
				game_is_on = false;
				printRoundStats(num_round, chance); // since we are breaking the loop we should also write the last round values
				break; // not allow the other pokemon to attack if it is dead already
			}
			
			// then psychic attacks
			damage_psychic = m_PsychicPokemon->Attack(); // gets numerical damage amount
			confusionAttack = m_PsychicPokemon->isConfusing(); // gets true if psychich confuses its opponent
			m_ElectricPokemon->setConfused(confusionAttack); // sets the confusion state of electric pokemon
			m_ElectricPokemon->setHitPoints(damage_psychic); // sets the new hp for electric pokemon
			
			if (endGame(m_ElectricPokemon))
				game_is_on = false; // end of the loop or game
		}
		else {
			// first psychic attacks
			damage_psychic = m_PsychicPokemon->Attack(); 
			confusionAttack = m_PsychicPokemon->isConfusing(); // gets true if psychich confuses its opponent
			m_ElectricPokemon->setConfused(confusionAttack); // sets the confusion state of electric pokemon
			m_ElectricPokemon->setHitPoints(damage_psychic); // sets the new hp for electric pokemon
			
			// after each attack check for dead state or end of the battle
			if (endGame(m_ElectricPokemon))  
			{
				game_is_on = false;
				printRoundStats(num_round, chance); // since we are breaking the loop we should also write the last round values
				break; // not allow the other pokemon to attack if it is dead already
			}

			// next electric attacks
			damage_electric = m_ElectricPokemon->Attack(); 
			m_PsychicPokemon->setHitPoints(damage_electric);
			if (endGame(m_PsychicPokemon))
				game_is_on = false; // end of the loop or game
		}
		printRoundStats(num_round, chance);
	}
	printMatchResults(); // at the end of the game writes the result 
	m_NumRoundInATerrain = 0; // at the end reset number so that differenet pokemons can battle after one another without conflicting their own values

}
Arena::~Arena() {
	// destructor to delete allocated pointer objects if they havent deleted yet 
	if (m_ElectricPokemon != NULL)
	{
		delete m_ElectricPokemon;
		m_ElectricPokemon = NULL;
	}
	if (m_PsychicPokemon != NULL)
	{
		delete m_PsychicPokemon;
		m_PsychicPokemon = NULL;
	}
}

