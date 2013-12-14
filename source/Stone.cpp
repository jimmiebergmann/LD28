#include <Stone.h>


Stone::Stone(sf::Vector2f p_position)
{
	m_sprite->setPosition( p_position );

//	m_sprite->setTexture(*Resources::GetTexture( "Stone.png" ));
}

Stone::~Stone()
{
	// Shall I unload Texture here?
}

sf::Sprite * Stone::GetSprite( ) const
{
	return m_sprite;
}

Entity::eType Stone::GetType( ) const
{
	return Type_Stone;
}