#ifndef GAME_TREE_H
#define GAME_TREE_H
#include <Resources.h>
#include <Entity.h>

class Tree : public Entity
{

public:

	Tree(sf::Vector2f p_position);
	virtual ~Tree();

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
	sf::Texture * ActiveTrap;
	sf::Texture * CloseTrap;

};


#endif