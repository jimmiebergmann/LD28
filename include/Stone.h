#ifndef GAME_STONE_H
#define GAME_STONE_H

#include <Tile.h>
#include <Resources.h>

class Stone : public Tile
{

public:

	Stone(sf::Vector2f p_position);
	~Stone();

	virtual sf::Sprite * GetSprite( ) const;


private:

	sf::Sprite * m_sprite;
	
};


#endif