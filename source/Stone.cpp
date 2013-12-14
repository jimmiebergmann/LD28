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

void Stone::Update( )
{
	//Update
}

void Stone::Collide( )
{
	//Collide
}

sf::Sprite * Stone::GetSprite( ) const
{
	return m_sprite;
}

eType Stone::GetType( ) const
{
	return Type_Stone;
}