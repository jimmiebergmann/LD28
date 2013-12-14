#ifndef GAME_BULLET_H
#define GAME_BULLET_H

#include <Resources.h>
#include <Entity.h>

class Bullet : public Entity
{

public:

	virtual ~Bullet(){}

	virtual void Update( Game * p_pGame, float p_deltaTime ) = 0;
	virtual void Collide( Game * p_pGame, const Entity * p_pOther ) = 0;

	virtual sf::Sprite * GetSprite( ) const = 0;
	virtual eType GetType( ) const = 0;

private:
		
};


#endif