#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <Entity.h>

class Player : public Entity
{
public:
	//Normal functions
	virtual void Update(Game * p_pGame, float p_deltaTime);
	virtual void Collide(Game * p_pGame, const Entity * p_pOther);
	
	// Get Functions
	virtual sf::Sprite * GetSprite( ) const;
	virtual eType GetType ( ) const;
private:
};

#endif