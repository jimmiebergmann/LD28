#ifndef GAME_FENCE_H
#define GAME_FENCE_H

#include <Resources.h>
#include <Entity.h>

class Fence : public Entity
{

public:

	Fence(sf::Vector2f p_position);
	virtual ~Fence();

	virtual void Update();
	virtual void Collide();

	virtual sf::Sprite * GetSprite( ) const;
	virtual eType GetType( ) const;

private:

	sf::Sprite * m_sprite;
	
};


#endif