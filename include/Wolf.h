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
	virtual void Update(Game * p_pGame, float p_deltaTime);
	virtual void Collide(Game * p_pGame, const Entity * p_pOther);
	virtual void addDamage(int p_damage);

	// Get function
	virtual int getHealth() const;
	virtual bool getAlive() const;
	virtual sf::Sprite * GetSprite( ) const;
	virtual eType GetType( ) const;

private:

	sf::Vector2f m_position;
	sf::Sprite * m_pSprite;

};


#endif // GAME_WOLF_H