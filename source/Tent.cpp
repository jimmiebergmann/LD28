#include <Tent.h>
#include <Resources.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Tent::Tent(const sf::Vector2f p_position) :
	m_position(p_position),
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Tent.png"))) 
{
	m_pSprite->setPosition(m_position);
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
	return m_pSprite;
}