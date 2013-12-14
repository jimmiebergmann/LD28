#ifndef GAME_TENT_H
#define GAME_TENT_H

#include <Entitiy.h>

#include <SFML\Graphics.hpp>

class Tent : public Entity
{

public:

	Tent(const sf::Vector2f p_position);
	virtual ~Tent();

	// Normal functions
	virtual void Update(Game * p_pGame, float p_deltaTime);
	virtual void Collide(Game * p_pGame, const Entity * p_pOther);

	// Get function
	virtual sf::Sprite * GetSprite( ) const;
	virtual Entity::eType GetType() const;
private:

	sf::Vector2f m_position;

};

#endif // GAME_TENT_H