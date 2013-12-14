#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <vector>

class Entity;
class Tile;

class Game
{

public:
	typedef std::vector<Entity *> EntityVector;
	typedef std::vector<Tile *> TileVector;

	virtual ~Game( ) { }
	
	// virtual functions
	virtual EntityVector & getEntities() = 0;
	virtual TileVector & getTiles() = 0;

	// get functions

	// set functions

private:

};


#endif