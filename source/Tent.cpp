#include <Tent.h>
#include <Resources.h>

#include <MemoryLeak.h>

Tent::Tent(const sf::Vector2f p_position) :
	m_position(p_position) {
}

Tent::~Tent()
{

}

void Tent:: Update(Game * p_pGame, float p_deltaTime)
{

}

void Tent::Collide(Game * p_pGame, const Entity * p_pOther)
{
	switch (p_pOther->GetType())
	{
	default:
		break;
	}
}

Entity::eType Tent::GetType() const 
{
	return Entity::eType::Type_Rabit;
}

sf::Sprite * Tent:: GetSprite( ) const
{
	sf::Sprite * pSprite = new sf::Sprite(*Resources::GetTexture("Tent.png"));
	return pSprite;
}