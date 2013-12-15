#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <Entity.h>
#include <Animation.h>
#include <SFML/Window.hpp>

class Player : public Entity
{
public:
	//constructor and destructor
	Player(sf::Vector2f position);
	virtual ~Player();

	//Normal functions
	virtual void Update(Game * p_pGame, float p_deltaTime);
	virtual void Collide(Game * p_pGame, const Entity * p_pOther);
	void Attack();
	
	// Get Functions
	virtual sf::Sprite * GetSprite( ) const;
	virtual Entity::eType GetType ( ) const;

private:

	sf::Vector2f m_Postition;

	Animation* m_pIdle;
	Animation* m_pWalkUp;
	Animation* m_pWalkDown;
	Animation* m_pWalkLeft;
	Animation* m_pWalkRight;
	Animation* m_pCurrentAnimation;
};

#endif