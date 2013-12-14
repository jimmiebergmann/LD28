#include <Fence.h>


Fence::Fence(sf::Vector2f p_position)
{
	m_sprite->setPosition( p_position );

//	m_sprite->setTexture(*Resources::GetTexture( "Fence.png" ));
}

Fence::~Fence()
{
	// Shall I unload Texture here?
}

void Fence::Update( )
{
	//Update
}

void Fence::Collide( )
{
	//Collide
}

sf::Sprite * Fence::GetSprite( ) const
{
	return m_sprite;
}

eType Fence::GetType( ) const
{
	return Type_Fence;
}