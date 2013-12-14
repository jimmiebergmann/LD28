#include <GameImp.h>
#include <Config.h>

GameImp::GameImp( )
{
}

GameImp::~GameImp( )
{
}

int GameImp::Run( )
{
	if( Config::Load( "Data/Configs.txt" ) == false )
	{
		return 0;
	}

	// Game loop here plz
	// ...


	// Close the game
	return 0;
}