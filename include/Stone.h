#ifndef GAME_STONE_H
#define GAME_STONE_H

#include <Tile.h>
#include <Resources.h>
#include <Entity.h>

class Stone : public Entity
{

public:

	Stone(sf::Vector2f p_position);
	virtual ~Stone();

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
	
};


#endif