#include <Config.h>
#include <fstream>
#include <iostream>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

sf::Vector2u Config::s_ScreenSize( 800, 600 );
int Config::s_TileSize =  32;
float Config::s_Zoom = 2.0f;


// Public functions
bool Config::Load( const char * p_pFilename )
{
	// Open the config file
	std::ifstream fin( p_pFilename );
	if( !fin.is_open( ) )
	{
		std::cout << "[Config::Load] Can not open the config file." << std::endl;
		return false;
	}

	// Temporary varaibles
	sf::Vector2u screenSize;
	int tileSize = 0;
	float zoom = 0;

	// Read the screen size
	if( fin.eof( ) )
	{
		std::cout << "[Config::Load] Incomplete config file(0)." << std::endl;
		return false;
	}
	fin >> screenSize.x;
	if( fin.eof( ) )
	{
		std::cout << "[Config::Load] Incomplete config file(1)." << std::endl;
		return false;
	}
	fin >> screenSize.y;

	// Read the tile size
	if( fin.eof( ) )
	{
		std::cout << "[Config::Load] Incomplete config file(2)." << std::endl;
		return false;
	}
	fin >> tileSize;

	// Read the zoom 
	if( fin.eof( ) )
	{
		std::cout << "[Config::Load] Incomplete config file(3)." << std::endl;
		return false;
	}
	fin >> zoom;

	// Check for weird inputs
	// ...
	if( screenSize.x > 3000 || screenSize.y > 3000 )
	{
		std::cout << "[Config::Load] To high screen resolution." << std::endl;
		return false;
	}

	if( tileSize > 128 )
	{
		std::cout << "[Config::Load] Too large tile." << std::endl;
		return false;
	}

	if( zoom <= 0.0f )
	{
		std::cout << "[Config::Load] Too small zoom." << std::endl;
		return false;
	}

	// Everything is okey now
	s_ScreenSize = screenSize;
	s_TileSize = tileSize;
	s_Zoom = zoom;

	return true;
}

// Get functions
sf::Vector2u Config::GetScreenSize( )
{
	return s_ScreenSize;
}

int Config::GetTileSize( )
{
	return s_TileSize;
}

float Config::GetZoom( )
{
	return s_Zoom;
}