#ifndef GAME_STONE_H
#define GAME_STONE_H

#include <Tile.h>
#include <Resources.h>
#include <Entity.h>

class Stone : public Entity
{

public:

	Stone(sf::Vector2f p_position);
	virtual ~Stone();

	virtual void Update();
	virtual void Collide();

	virtual sf::Sprite * GetSprite( ) const;
	virtual eType GetType( ) const;

private:

	sf::Sprite * m_sprite;
	
};


#endif