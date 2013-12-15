#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <Entity.h>
#include <Animation.h>
#include <SFML/Window.hpp>

class Player : public Entity
{
public:

	Player(sf::Vector2f position);

	//Normal functions
	virtual void Update(Game * p_pGame, float p_deltaTime);
	virtual void Collide(Game * p_pGame, const Entity * p_pOther);
	void Attack();
	
	// Get Functions
	virtual sf::Sprite * GetSprite( ) const;
	virtual Entity::eType GetType ( ) const;
private:
	sf::Vector2f m_Postition;



	Animation* m_Idle;
	Animation* m_WalkUp;
	Animation* m_WalkDown;
	Animation* m_WalkLeft;
	Animation* m_WalkRight;
	Animation* m_CurrentAnimation;
};

#endif