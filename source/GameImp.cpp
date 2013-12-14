#include <GameImp.h>
#include <Config.h>
#include <iostream>
#include <Entity.h>
#include <SFML/Graphics/Sprite.hpp>
#include <Rabbit.h>
#include <Tent.h>
#include <Resources.h>
#include <Stone.h>
#include <Tree.h>

#include <MemoryLeak.h>

// Private static
const sf::Vector2u GameImp::s_mapSize = sf::Vector2u( 35, 25 );
const sf::Color GameImp::s_clearColor( 56, 215, 79, 255 );

GameImp::GameImp( ) :
	m_pRenderWindow( NULL ),
	m_ppCollisionData( NULL ),
	m_mapColor( 255, 255, 255, 255 )
{
}

GameImp::~GameImp( )
{
}

Game::EntityVector & GameImp::GetEntities( )
{
	return m_entitys;
}

 sf::Vector2u GameImp::GetMapSize( ) const
 {
	 return s_mapSize;
 }

 bool GameImp::GetCollisionData( const sf::Vector2u p_Coordinate ) const
 {
	 return m_ppCollisionData[ p_Coordinate.x ][ p_Coordinate.y ];
 }

int GameImp::Run( )
{
	InitMemoryLeak();

	// Load the game
	if( !Load( ) ) {
		return Error(sf::String("Could not load resouced"));
	}

	// Start the game loop
	while (m_pRenderWindow->isOpen())
	{
		// Handle the events
		sf::Event e;
		while (m_pRenderWindow->pollEvent(e))
		{
			HandleEvent( e );
		}

		// Update the game
		Update( 0.0f );

		// Render the game
		Render( );

	}

	// Exit the aplication
	Unload();
	return 0;
}

int GameImp::Error( const sf::String & p_errorDesc)
{
	char val;
	std::cout << "Error: " << p_errorDesc.toAnsiString() << std::endl;
	std::cout << "Press any key to conture " << std::endl;
	std::cin >> val;
	
	Unload();
	return 0;
}

bool GameImp::Load()
{
	// Load the config file
	Config::Load( "Data/Configs.txt" );

	// Load the window
	sf::Vector2u & size = Config::GetScreenSize(); 
	m_pRenderWindow = new sf::RenderWindow(sf::VideoMode(size.x, size.y), "Y.O.G.O. Game");

	// Load the collision data
	m_ppCollisionData = new bool * [ s_mapSize.x ];
	for( unsigned int i = 0; i < s_mapSize.x; i++ )
	{
		m_ppCollisionData[ i ] = new bool [s_mapSize.y ];
		for( unsigned int j = 0; j < s_mapSize.y; j++ )
		{
			m_ppCollisionData[ i ][ j ] = false;
		}
	}

	for( unsigned int i = 0; i < s_mapSize.x; i++ )
	{
		for( unsigned int j = 0; j < s_mapSize.y; j++ )
		{
			int val = std::rand() % 10;
			if (val == 9)
			{
				m_entitys.push_back(new Tent(sf::Vector2f(i * 32.0f, j * 32.0f))); 
			}
			else if (val == 8)
			{
				m_entitys.push_back(new Stone(sf::Vector2f(i * 32.0f, j * 32.0f))); 
			}
			else if (val == 7)
			{
				m_entitys.push_back(new Tree(sf::Vector2f(i * 32.0f, j * 32.0f))); 
			}
		}
	}

	m_entitys.push_back(new Rabbit(sf::Vector2f(0, 0)));
	return true;
}

void GameImp::Unload()
{
	if( m_pRenderWindow )
	{
		delete m_pRenderWindow;
		m_pRenderWindow = NULL;
	}

	if( m_ppCollisionData )
	{
		for( unsigned int i = 0; i < s_mapSize.x; i++ )
		{
			delete m_ppCollisionData[ i ];
		}
		
		delete m_ppCollisionData;
		m_ppCollisionData = NULL;
	}
	for(EntityVector::size_type i = 0; i < m_entitys.size( ); i++ )
	{
		delete m_entitys[ i ];
	}
	m_entitys.clear();

	Resources::UnloadResources();
}

void GameImp::Update( float p_DeltaTime )
{
	// Update all the entities
	for( unsigned int i = 0; i < m_entitys.size( ); i++ )
	{
		m_entitys[ i ]->Update( this, p_DeltaTime );
	}

	// Collision check all the entities
	for( unsigned int i = 0; i < m_entitys.size( ); i++ )
	{
		for( unsigned int j = i + 1; j < m_entitys.size( ); j++ )
		{
			sf::FloatRect rect0 = m_entitys[ i ]->GetSprite( )->getGlobalBounds( );
			sf::FloatRect rect1 = m_entitys[ j ]->GetSprite( )->getGlobalBounds( );

			if( rect0.intersects( rect1 ) )
			{
				m_entitys[ i ]->Collide( this, m_entitys[ j ] );
			}
		}
	}
}

void GameImp::HandleEvent( sf::Event p_event)
{
	switch (p_event.type)
	{
	case sf::Event::Closed:
		m_pRenderWindow->close();
		break;
	default:
		break;
	}
}

void GameImp::Render( )
{
	m_pRenderWindow->clear( s_clearColor );

	// Render all the entities
	for( unsigned int i = 0; i < m_entitys.size( ); i++ )
	{
		sf::Sprite * pSprite = m_entitys[ i ]->GetSprite( );
		pSprite->setColor( m_mapColor );
		m_pRenderWindow->draw( *pSprite );
	}

	m_pRenderWindow->display( );
}