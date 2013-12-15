#ifndef GAME_TURRETBULLET_H
#define GAME_TURRETBULLET_H

#include <Bullet.h>

#include <SFML\System\Vector2.hpp>

class TurretBullet : public Bullet
{

public:

	TurretBullet(const sf::Vector2f p_position, Entity * p_enemyTarget);
	virtual ~TurretBullet();
	
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

	Entity * m_pEnemyTarget;
	sf::Sprite * m_pSprite;

};

#endif // GAME_RABBIT_H


