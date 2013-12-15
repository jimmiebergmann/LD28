#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include <SFML/System/Vector2.hpp>

class Config
{

public:

	// Public functions
	static bool Load( const char * p_pFilename );

	// Get functions
	static sf::Vector2u GetScreenSize( );
	static int GetTileSize( );


private:

	static sf::Vector2u s_ScreenSize;
	static int s_TileSize;

};


#endif