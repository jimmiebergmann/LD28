#ifndef GAME_WOLF_H
#define GAME_WOLF_H

#include <Enemy.h>

#include <SFML\System\Vector2.hpp>

class Animation;

class Wolf : public Enemy
{
	
public:

	Wolf(const sf::Vector2f p_position);
	virtual ~Wolf();

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

	Animation* m_pWalkUp;
	Animation* m_pWalkDown;
	Animation* m_pWalkLeft;
	Animation* m_pWalkRight;
	Animation* m_pCurrentAnimation;

	bool m_alive;
	int m_health;

};


#endif // GAME_WOLF_H