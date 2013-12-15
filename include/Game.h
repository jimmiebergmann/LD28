#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/System/Vector2.hpp>
#include <vector>

class Entity;
class Tile;

class Game
{

public:

	typedef std::vector<Entity *> EntityVector;

	virtual ~Game( ) { }
	
	// get functions
	virtual void addEntity(Entity * p_pEntity ) = 0;
	virtual const EntityVector & GetEntities( ) = 0;
	virtual sf::Vector2u GetMapSize( ) const = 0;
	virtual bool GetCollisionData( const sf::Vector2u p_Coordinate ) const = 0;
	
	// set functions

private:

};


#endif