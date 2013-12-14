#include <GameImp.h>
#include <Config.h>
#include <MemoryLeak.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>

//private global vairables
static const sf::String g_title = "Y.O.G.O. Game";
static sf::RenderWindow * g_pRenderWindow = 0;

//private global functions
static void HandleEvent(GameImp & p_gameImp, sf::Event p_event);
static bool Load();
static void Unload();
static void ErrorLoad(sf::String & p_errorDesc);

GameImp::GameImp( )
{
}

GameImp::~GameImp( )
{
}

int GameImp::Run( )
{
	InitMemoryLeak();

	if(!Load()) {
		ErrorLoad(sf::String("Could not load resouced"));
		return 1;
	}

	while (g_pRenderWindow->isOpen())
	{
		sf::Event eventA;
		while (g_pRenderWindow->pollEvent(eventA))
		{
			HandleEvent(*this, eventA);
		}
	}
	Unload();
	delete g_pRenderWindow;
	return 0;
}

static void HandleEvent(GameImp & p_gameImp, sf::Event p_event)
{
	switch (p_event.type)
	{
	case sf::Event::Closed:
		g_pRenderWindow->close();
		break;
	default:
		break;
	}
}

static bool Load()
{
	Config::Load( "Data/Configs.txt" );

	sf::Vector2u size = Config::GetScreenSize(); 
	g_pRenderWindow = newAPI sf::RenderWindow(sf::VideoMode(size.x, size.y), g_title);

	return true;
}

static void Unload()
{

}

static void ErrorLoad(sf::String & p_errorDesc)
{
	char val;
	std::cout << "Error: " << p_errorDesc.toAnsiString() << std::endl;
	std::cout << "Press any key to conture " << std::endl;
	std::cin >> val;
	Unload();
}

Game::EntityVector & GameImp::getEntities() {
	return m_entitys;
}

Game::TileVector & GameImp::getTiles() {
	return m_tiles;
}