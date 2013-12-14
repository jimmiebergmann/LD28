#include <Fence.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Fence::Fence(sf::Vector2f p_position)
{
	m_sprite->setPosition( p_position );

//	m_sprite->setTexture(*Resources::GetTexture( "Fence.png" ));
}

Fence::~Fence()
{
	// Shall I unload Texture here?
}

void Fence::Update( Game * p_pGame, float p_deltaTime)
{
	//Update
}

void Fence::Collide( Game * p_pGame, const Entity * p_pOther )
{
	//Collide
}

sf::Sprite * Fence::GetSprite( ) const
{
	return m_sprite;
}

Entity::eType Fence::GetType( ) const
{
	return Type_Fence;
}