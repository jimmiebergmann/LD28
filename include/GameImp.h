#ifndef GAME_GAME_IMP_H
#define GAME_GAME_IMP_H

#include <Game.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class GameImp : public Game
{

public:

	// Construcotrs / destructor
	GameImp( );
	virtual ~GameImp( );

	// virtual functions
	virtual EntityVector & getEntities();

	// Public functions
	int Run( );
	
	// get functions
	// ..

	// set functions
	// ..

private:

	// Private functions
	int Error( const sf::String & p_errorDesc);
	bool Load();
	void Unload();
	void Update( float p_DeltaTime );
	void HandleEvent( sf::Event p_event);
	void Render( );

	// private variables
	sf::RenderWindow * m_pRenderWindow;
	EntityVector m_entitys;
};


#endif