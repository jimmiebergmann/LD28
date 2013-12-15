#ifndef GAME_TURRET_H
#define GAME_TURRET_H

#include <Tile.h>
#include <Resources.h>
#include <Entity.h>

class Turret : public Entity
{

public:

	Turret(sf::Vector2f p_position);
	virtual ~Turret();

	void Attack( Game * p_pGame );

	// Normal functions
	virtual void Update(Game * p_pGame, float p_deltaTime);
	virtual void Collide(Game * p_pGame, const Entity * p_pOther);
	virtual void addDamage(int p_damage);

	// Get function
	virtual int getHealth() const;
	virtual bool getAlive() const;
	virtual sf::Sprite * GetSprite( ) const;
	virtual eType GetType( ) const;




private:

	int m_turretTimer;
	sf::Sprite * m_pSprite;
	
};


#endif