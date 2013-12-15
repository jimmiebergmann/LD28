#ifndef GAME_TENT_H
#define GAME_TENT_H

#include <Entity.h>

#include <SFML\Graphics.hpp>

class Tent : public Entity
{

public:
	
	Tent(const sf::Vector2f p_position);
	virtual ~Tent();

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

	sf::Sprite * m_pSprite;

};

#endif // GAME_TENT_H