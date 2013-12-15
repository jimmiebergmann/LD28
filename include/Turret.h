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

	virtual void Update( Game * p_pGame, float p_deltaTime );
	virtual void Collide( Game * p_pGame, const Entity * p_pOther );

	void Attack( Game * p_pGame );

	virtual sf::Sprite * GetSprite( ) const;
	virtual eType GetType( ) const;




private:

	sf::Sprite * m_pSprite;
	
};


#endif