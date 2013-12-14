#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H
#include <Entity.h>

class Enemy : public Entity
{
	
public:

	virtual ~Enemy(){}


	// Normal functions
	virtual void Update(Game * p_pGame, float p_deltaTime) = 0;
	virtual void Collide(Game * p_pGame, const Entity * p_pOther) = 0;

	// Get function
	virtual sf::Sprite * GetSprite( ) const = 0;
	virtual eType GetType( ) const = 0;

private:


};


#endif