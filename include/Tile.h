#ifndef GAME_TILE_H
#define GAME_TILE_H
#include <SFML\Graphics.hpp>

class Tile
{

public:

	Tile();
	virtual ~Tile();

	// Get Functions
	virtual sf::Sprite * GetSprite( ) const = 0;
	


	// Set Functions
	

private:



};


#endif
