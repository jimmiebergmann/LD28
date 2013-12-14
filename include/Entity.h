#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H
#include <SFML\Graphics.hpp>

enum eType
{
	Type_Wolf,
	Type_Player,
	Type_Rabit,
	Type_Tent,
	Type_Turret,
	Type_Fence,
	Type_Trap,
	Type_Bullet,
	Type_Stone,
	Type_Tree
};

class Entity
{
	
public:

	virtual ~Entity(){}


	// Normal functions
	virtual void Update() = 0;
	virtual void Collide() = 0;

	// Get function
	virtual sf::Sprite * GetSprite( )const = 0;
	virtual eType GetType( )const = 0;

private:


};


#endif