#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <SFML\Graphics.hpp>

class Game;

class Entity
{
	
public:
	enum eType
	{
		Type_Wolf,
		Type_Player,
		Type_Rabit,
		Type_Tent,
		Type_Turret,
		Type_Fence,
		Type_Trap,
		Type_Bullet
	};

	virtual ~Entity() {};


	// Normal functions
	virtual void Update(Game * p_pGame, float p_deltaTime) = 0;
	virtual void Collide(Game * p_pGame, const Entity * p_pOther) = 0;

	// Get function
	virtual sf::Sprite * GetSprite( )const = 0;
	virtual eType GetType() const = 0;
private:


};


#endif