#include <Stone.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Stone::Stone(sf::Vector2f p_position) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/Stone.png"))) 
{
	m_pSprite->setPosition( p_position );
}

Stone::~Stone()
{
	// Shall I unload Texture here?
}

void Stone::Update( Game * p_pGame, float p_deltaTime )
{
	//Update
}

void Stone::Collide( Game * p_pGame, const Entity * p_pOther)
{
	//Collide
}

sf::Sprite * Stone::GetSprite( ) const
{
	return m_pSprite;
}

Entity::eType Stone::GetType( ) const
{
	return Type_Stone;
}