#include <GameImp.h>
#include <Config.h>
#include <iostream>
#include <Entity.h>
#include <SFML/Graphics/Sprite.hpp>
#include <Rabbit.h>
#include <Tent.h>
#include <Resources.h>
#include <Player.h>
#include <Stone.h>
#include <Tree.h>
#include <Fence.h>
#include <Trap.h>
#include <Wolf.h>
#include <Turret.h>

#include <MemoryLeak.h>

// Private static

const sf::Vector2u GameImp::s_mapSize = sf::Vector2u( 16, 16 );
const sf::Color GameImp::s_clearColor( 56, 215, 79, 255 );
const sf::Vector2f GameImp::s_wolfSpawnPoints[ 3 ] =
{
	sf::Vector2f( 2 * Config::GetTileSize( ), 2  * Config::GetTileSize( )),
	sf::Vector2f( 2 * Config::GetTileSize( ), ( s_mapSize.y / 2 ) * Config::GetTileSize( ) ),
	sf::Vector2f( 2 * Config::GetTileSize( ), ( s_mapSize.y - 3 ) * Config::GetTileSize( ) )
};

sf::Clock g_dayCycle;

GameImp::GameImp( ) :
	m_pRenderWindow( NULL ),
	m_pPlayer( NULL ),
	m_ppCollisionData( NULL ),
	m_mapColor( 255, 255, 255, 255 ),
	m_spawningWolfs( false )
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
	if( !Load( ) )
	{
		return Error(sf::String("Could not load resouced"));
	}

	int framCount = 0;
	sf::Clock clocl;
	float fps = 0;
	// Start the game loop
	while (m_pRenderWindow->isOpen())
	{
		// Handle the events
		sf::Event e;
		while (m_pRenderWindow->pollEvent(e))
		{
			HandleEvent( e );
		}
		framCount++;
		if (clocl.getElapsedTime().asSeconds() > 0.5f) {
			fps = framCount / clocl.getElapsedTime().asSeconds();
			clocl.restart();
			framCount = 0;
			std::cout << fps << std::endl;
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
	if (!Resources::Load()) {
		return false;
	}
	// Load the config file
	Config::Load( "Data/Configs.txt" );

	// Load the window
	sf::Vector2u & size = Config::GetScreenSize(); 
	m_pRenderWindow = new sf::RenderWindow(sf::VideoMode(size.x, size.y), "Y.O.G.O. Game");
	
	m_pRenderWindow->setFramerateLimit(60);

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
	m_pPlayer = new Player(sf::Vector2f(250, 200));
	m_entitys.push_back(new Rabbit(sf::Vector2f(0, 0)));
	m_entitys.push_back(new Stone(sf::Vector2f(5*32, 5*32)));
	m_entitys.push_back(m_pPlayer);
	//m_entitys.push_back(new Wolf(sf::Vector2f(700, 700)));

	m_entitys.push_back(new Tent(sf::Vector2f(32.0f,32.0f))); 

	for( unsigned int i = 0; i < s_mapSize.x; i++ )
	{
		for( unsigned int j = 0; j < s_mapSize.y; j++ )
		{

			int val = std::rand() % 10;
			if ((val == 9) && (m_ppCollisionData[i][j] == false))
			{
				addEntity(new Tree(sf::Vector2f(i * 32.0f, j * 32.0f))); 
			}
		}
	}
	m_entitys.push_back(new Turret(sf::Vector2f(60, 60)));

	sf::View t(m_pRenderWindow->getView());
	t.zoom( 1.0f / Config::GetZoom( ) );
	m_pRenderWindow->setView(t);
	return true;
}

void GameImp::addEntity( Entity * p_pEntity )
{
	m_entitys.push_back(p_pEntity);
		int x = p_pEntity->GetSprite()->getPosition().x/32;
		int y = p_pEntity->GetSprite()->getPosition().y/32;
	m_ppCollisionData[x][y] = true;
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

	Resources::Unload();
}

void GameImp::Update( float p_DeltaTime )
{
	// Reset the wolf spawn timer
	if( sf::Keyboard::isKeyPressed( sf::Keyboard::O ) )
	{
		m_spawningWolfs = true;
		m_wolfSpawnTimer.restart( );
	}

	// Spawn wolfs
	if( m_spawningWolfs )
	{
		if( m_wolfSpawnTimer.getElapsedTime( ).asSeconds( ) >= 1.0f )
		{
			for( int i = 0; i < 3; i++ )
			{
				m_entitys.push_back( new Wolf( s_wolfSpawnPoints[ i ] ) ); 
			}

			m_wolfSpawnTimer.restart( );
		}
	}


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
				//m_entitys[ j ]->Collide( this, m_entitys[ i ] );
			}
		}
	}
		// Update all the entities
	EntityVector tempVector;

	for( unsigned int i = 0; i < m_entitys.size( ); i++ )
	{
		Entity & entity = *m_entitys[ i ];
		if(entity.getAlive()) 
		{
			tempVector.push_back(m_entitys[ i ]);
		}
		else if (m_entitys[ i ] != m_pPlayer) 
		{
			delete m_entitys[ i ];
		}
	}
	m_entitys = tempVector;
}

void GameImp::HandleEvent( sf::Event p_event)
{
	switch (p_event.type)
	{
	case sf::Event::Closed:
		m_pRenderWindow->close();
		break;
	case sf::Event::Resized:
		m_pRenderWindow->setSize(sf::Vector2u(p_event.size.width, p_event.size.height));
		break;
	default:
		break;
	}
}

void GameImp::Render( )
{
	m_pRenderWindow->setView(sf::View(CameraUpdate(), m_pRenderWindow->getView().getSize()));

	

	m_mapColor = sf::Color(127, 127, 127, 255);
	float dayNight = g_dayCycle.getElapsedTime().asSeconds();
	while (dayNight > 10.0f) {
		dayNight -= 10.0f;
	}
	float mornigTwilight = std::cos(g_dayCycle.getElapsedTime().asSeconds() * 0.5f);
	if ((dayNight >= 0) && (dayNight <= 2)) {
		m_mapColor.r += -64 + int(std::sin(dayNight / 2) * 192);
		m_mapColor.g += -64 + int(std::sin(dayNight / 2) * 192);
		m_mapColor.b += 128;
	} else if ((dayNight >= 2) && (dayNight <= 5)) {
		m_mapColor.r += 128;
		m_mapColor.g += 128;
		m_mapColor.b += 128;
	} else if ((dayNight >= 5) && (dayNight <= 7)) {
		m_mapColor.r += 128 - int(std::sin((dayNight - 5) / 2) * 192);
		m_mapColor.g += 128 - int(std::sin((dayNight - 5) / 2) * 192);
		m_mapColor.b += 128;
	} else if ((dayNight >= 7) && (dayNight <= 10)) {
		m_mapColor.r += -64;
		m_mapColor.g += -64;
		m_mapColor.b += 128;
	}
	
	
	sf::Texture * tex = Resources::GetTexture("Data/Textures/Grass.png");
	tex->setRepeated(true);
	sf::Sprite backgrond(*tex, sf::IntRect(sf::Vector2i(), sf::Vector2i(s_mapSize * 32U)));
	backgrond.setColor( m_mapColor );
	m_pRenderWindow->clear( m_mapColor );
	m_pRenderWindow->draw(backgrond);
	// Render all the entities
	for( unsigned int i = 0; i < m_entitys.size( ); i++ )
	{
		
		sf::Sprite * pSprite = m_entitys[ i ]->GetSprite( );
		pSprite->setColor( m_mapColor );
		m_pRenderWindow->draw( *pSprite );
	}

	m_pRenderWindow->display( );
}


sf::Vector2f GameImp::CameraUpdate( )
{

	int ViewX = m_pPlayer->GetSprite()->getPosition().x;
	
	if(m_pPlayer->GetSprite()->getPosition().x < Config::GetScreenSize().x / (Config::GetZoom( ) * 2 ))
	{
		ViewX = Config::GetScreenSize().x / (Config::GetZoom( ) * 2 );
	}

	
	if(m_pPlayer->GetSprite()->getPosition().x > s_mapSize.x * Config::GetTileSize() - Config::GetScreenSize().x / (Config::GetZoom( ) * 2 ))
	{
		ViewX = s_mapSize.x * Config::GetTileSize() - Config::GetScreenSize().x / (Config::GetZoom( ) * 2 );
	}

	
	int ViewY = m_pPlayer->GetSprite()->getPosition().y;
	
	if(m_pPlayer->GetSprite()->getPosition().y < Config::GetScreenSize().y / (Config::GetZoom( ) * 2 ))
	{
		ViewY = Config::GetScreenSize().y / (Config::GetZoom( ) * 2 );
	}

	if(m_pPlayer->GetSprite()->getPosition().y > s_mapSize.y * Config::GetTileSize() - Config::GetScreenSize().y / (Config::GetZoom( ) * 2 ))
	{
		ViewY = s_mapSize.y * Config::GetTileSize() - Config::GetScreenSize().y / (Config::GetZoom( ) * 2 );
	}
	

	return sf::Vector2f(ViewX, ViewY);
}