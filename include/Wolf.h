#ifndef GAME_WOLF_H
#define GAME_WOLF_H

#include <Enemy.h>

#include <SFML\System\Vector2.hpp>

class Wolf : public Enemy
{
	
public:

	Wolf(const sf::Vector2f p_position);
	virtual ~Wolf();


	// Normal functions
	virtual void Update(Game * p_pGame, float p_deltaTime) = 0;
	virtual void Collide(Game * p_pGame, const Entity * p_pOther) = 0;

	// Get function
	virtual sf::Sprite * GetSprite( ) const = 0;
	virtual eType GetType( ) const = 0;

private:

	sf::Vector2f m_position;
	sf::Sprite * m_pSprite;

};


#endif // GAME_WOLF_H