#ifndef GAME_TRAP_H
#define GAME_TRAP_H

#include <Entity.h>

#include <SFML\Graphics.hpp>

class Trap : public Entity
{
	
public:
	
	Trap(const sf::Vector2f p_position);
	virtual ~Trap();

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
	int m_health;
	bool m_activeTrap;
	bool m_alive;

};

#endif // GAME_TENT_H