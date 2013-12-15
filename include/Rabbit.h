#ifndef GAME_RABBIT_H
#define GAME_RABBIT_H

#include <Entity.h>

#include <SFML\System\Vector2.hpp>

class Animation;

class Rabbit : public Entity
{

public:

	Rabbit(const sf::Vector2f p_position);
	virtual ~Rabbit();


	// Normal functions
	virtual void Update(Game * p_pGame, float p_deltaTime);
	virtual void Collide(Game * p_pGame, Entity * p_pOther);
	virtual int addDamage(int p_damage);

	// Get function
	virtual int getHealth() const;
	virtual bool getAlive() const;
	virtual sf::Sprite * GetSprite( ) const;
	virtual eType GetType( ) const;
private:

	Animation *		m_pMoveAnimation;
	Animation *		m_pIdleAnimation;
	Animation *		m_pCurrentAnimation;

};

#endif // GAME_RABBIT_H


