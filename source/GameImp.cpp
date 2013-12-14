#include <GameImp.h>
#include <Config.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>

#define newAPI new

//private global vairables
static const sf::String g_title = "Y.O.G.O. Game";
static unsigned int g_width = 200;
static unsigned int g_heigth = 300;
static sf::RenderWindow * g_pRenderWindow = 0;

//private global functions
static void g_HandleEvent(GameImp & p_gameImp, sf::Event p_event);
static bool g_Load();
static void g_Unload();
static void g_ErrorLoad(sf::String & p_errorDesc);

GameImp::GameImp( )
{
}

GameImp::~GameImp( )
{
	g_Unload();
}

int GameImp::Run( )
{
	if(!g_Load()) {
		g_ErrorLoad(sf::String("Could not load resouced"));
		return 1;
	}

	g_pRenderWindow = newAPI sf::RenderWindow(sf::VideoMode(g_width, g_heigth), g_title);

	while (g_pRenderWindow->isOpen())
	{
		sf::Event eventA;
		while (g_pRenderWindow->pollEvent(eventA))
		{
			g_HandleEvent(*this, eventA);
		}
	}
	delete g_pRenderWindow;
	return 0;
}

static void g_HandleEvent(GameImp & p_gameImp, sf::Event p_event) {
	switch (p_event.type)
	{
	case sf::Event::Closed:
		g_pRenderWindow->close();
		break;
	default:
		break;
	}
}

static bool g_Load() {
	if( Config::Load( "Data/Configs.txt" ) == false )
	{
		return 0;
	}
	
	return true;
}

static void g_Unload() {


}

static void g_ErrorLoad(sf::String & p_errorDesc) {
	char val;
	std::cout << "Error: " << p_errorDesc.toAnsiString() << std::endl;
	std::cout << "Press any key to conture " << std::endl;
	std::cin >> val;
	g_Unload();
}

Game::EntityVector & GameImp::getEntities() {
	return m_entitys;
}

Game::TileVector & GameImp::getTiles() {
	return m_tiles;
}