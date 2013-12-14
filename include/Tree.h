#ifndef GAME_TREE_H
#define GAME_TREE_H
#include <Resources.h>
#include <Entity.h>

class Tree : public Entity
{

public:

	Tree(sf::Vector2f p_position);
	virtual ~Tree();

	virtual void Update();
	virtual void Collide();

	virtual sf::Sprite * GetSprite( ) const;
	virtual eType GetType( ) const;

private:

	sf::Sprite * m_sprite;
	
};


#endif