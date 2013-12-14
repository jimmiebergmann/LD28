#include <Tree.h>




Tree::Tree(sf::Vector2f p_position)
{
	m_sprite->setPosition( p_position );

//	m_sprite->setTexture(*Resources::GetTexture(" Tree.png" ));
}

Tree::~Tree()
{
	// Shall I unload Texture here?
}

sf::Sprite * Tree::GetSprite( ) const
{
	return m_sprite;
}

Entity::eType Tree::GetType( ) const
{
	return Type_Tree;
}
