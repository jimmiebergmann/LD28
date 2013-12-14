#include <GameImp.h>
#include <Config.h>
#include <iostream>
#include <MemoryLeak.h>


GameImp::GameImp( ) :
	m_pRenderWindow( NULL )
{
}

GameImp::~GameImp( )
{
}

Game::EntityVector & GameImp::getEntities()
{
	return m_entitys;
}


int GameImp::Run( )
{
	InitMemoryLeak();

	if(!Load()) {
		return Error(sf::String("Could not load resouced"));
	}

	while (m_pRenderWindow->isOpen())
	{
		sf::Event eventA;
		while (m_pRenderWindow->pollEvent(eventA))
		{
			HandleEvent( eventA );
		}
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
	Config::Load( "Data/Configs.txt" );

	sf::Vector2u size = Config::GetScreenSize(); 
	m_pRenderWindow = new sf::RenderWindow(sf::VideoMode(size.x, size.y), "Y.O.G.O. Game");

	return true;
}

void GameImp::Unload()
{
	if( m_pRenderWindow )
	{
		delete m_pRenderWindow;
		m_pRenderWindow = NULL;
	}

}

void GameImp::Update( float p_DeltaTime )
{

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

}