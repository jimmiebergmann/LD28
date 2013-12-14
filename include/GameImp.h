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
	virtual EntityVector & GetEntities( );
	virtual sf::Vector2u GetMapSize( ) const;
	virtual bool GetCollisionData( const sf::Vector2u p_Coordinate ) const;

	// Public functions
	int Run( );
	
	// get functions
	// ..

	// set functions
	// ..

private:

	// Private functions
	int Error( const sf::String & p_errorDesc);
	bool Load( );
	void Unload( );
	void Update( float p_DeltaTime );
	void HandleEvent( sf::Event p_event);
	void Render( );

	// Private static
	static const sf::Vector2u s_mapSize;

	// private variables
	sf::RenderWindow * m_pRenderWindow;
	EntityVector m_entitys;
	bool ** m_ppCollisionData;
};


#endif