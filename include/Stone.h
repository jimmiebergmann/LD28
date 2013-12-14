#ifndef GAME_TREE_H
#define GAME_TREE_H
#include <Tile.h>
#include <Resources.h>

class Tree : public Tile
{

public:

	Tree(sf::Vector2f p_position);
	~Tree();

	virtual sf::Sprite * GetSprite( ) const;


private:

	sf::Sprite * m_sprite;
	
};


#endif