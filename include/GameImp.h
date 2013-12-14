#ifndef GAME_GAME_IMP_H
#define GAME_GAME_IMP_H

#include <Game.h>

class GameImp : public Game
{

public:
	// Construcotrs / destructor
	GameImp( );
	virtual ~GameImp( );

	// Public functions
	int Run( );
	
	// virtual functions
	virtual EntityVector & getEntities();
	virtual TileVector & getTiles();

	// get functions

	// set functions

private:
	EntityVector m_entitys;
	TileVector  m_tiles;
};


#endif