#ifndef GAME_GAME_IMP_H
#define GAME_GAME_IMP_H

#include <Game.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

// Forward declaration
class Player;

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
	static const sf::Color s_clearColor;
	static const sf::Vector2f s_wolfSpawnPoints[ 3 ];

	// private variables
	sf::RenderWindow * m_pRenderWindow;
	EntityVector m_entitys;
	Player * m_pPlayer;
	bool ** m_ppCollisionData;
	sf::Color m_mapColor;
	bool m_spawningWolfs;
	sf::Clock m_wolfSpawnTimer;

};


#endif