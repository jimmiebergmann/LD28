#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <Entity.h>
#include <Animation.h>
#include <SFML/Window.hpp>
#include <Game.h>

class Player : public Entity
{
public:
	//constructor and destructor
	Player(sf::Vector2f position);
	virtual ~Player();


	// Normal functions
	virtual void Update(Game * p_pGame, float p_deltaTime);
	virtual void Collide(Game * p_pGame, Entity * p_pOther);
	virtual int addDamage(int p_damage);
	void Attack(Game * p_pGame);
	void AddObject(Game * p_pGame);

	// Get function
	virtual int getHealth() const;
	virtual bool getAlive() const;
	virtual sf::Sprite * GetSprite( ) const;
	virtual eType GetType( ) const;

private:

	bool m_alive;
	int m_health;
	sf::Vector2f m_Postition;

	enum eDirection
	{
		Type_Up,
		Type_Down,
		Type_Right,
		Type_Left
	};
	eDirection m_eCurrentDirection;

	sf::Clock m_attackClock;
	sf::Time m_attackTime;
	float m_time;

	sf::FloatRect m_pWeaponCollision;

	Animation* m_pIdle;
	Animation* m_pWalkUp;
	Animation* m_pWalkDown;
	Animation* m_pWalkLeft;
	Animation* m_pWalkRight;
	Animation* m_pCurrentAnimation;
};

#endif