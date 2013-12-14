#include <Stone.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Stone::Stone(sf::Vector2f p_position)
{
	m_sprite->setPosition( p_position );

//	m_sprite->setTexture(*Resources::GetTexture( "Stone.png" ));
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
	return m_sprite;
}

Entity::eType Stone::GetType( ) const
{
	return Type_Stone;
}