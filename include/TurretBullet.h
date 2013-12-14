#ifndef GAME_TURRETBULLET_H
#define GAME_TURRETBULLET_H

#include <Bullet.h>

#include <SFML\System\Vector2.hpp>

class TurretBullet : public Bullet
{

public:

	TurretBullet(const sf::Vector2f p_position);
	virtual ~TurretBullet();

	// Normal functions
	virtual void Update(Game * p_pGame, float p_deltaTime);
	virtual void Collide(Game * p_pGame, const Entity * p_pOther);

	// Get function
	virtual sf::Sprite * GetSprite( ) const;
	virtual Entity::eType GetType() const;
private:

	sf::Sprite * m_pSprite;

};

#endif // GAME_RABBIT_H


