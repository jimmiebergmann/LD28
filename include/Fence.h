#ifndef GAME_FENCE_H
#define GAME_FENCE_H

#include <Resources.h>
#include <Entity.h>

class Fence : public Entity
{

public:

	Fence(sf::Vector2f p_position);
	virtual ~Fence();

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
		
	sf::Sprite * m_pSprite;
	

};


#endif