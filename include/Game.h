#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <vector>

class Entity;
class Tile;

class Game
{

public:

	typedef std::vector<Entity *> EntityVector;

	virtual ~Game( ) { }
	
	// virtual functions
	virtual EntityVector & getEntities() = 0;

	// get functions

	// set functions

private:

};


#endif