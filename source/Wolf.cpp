#include <Wolf.h>
#include <Resources.h>

#include <SFML\Graphics\Sprite.hpp>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Wolf::Wolf(const sf::Vector2f p_position) :
	m_position(p_position),
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Wolf.png"))) 
{
	m_pSprite->setPosition(m_position);
}

Wolf::~Wolf()
{

}

void Wolf::Update(Game * p_pGame, float p_deltaTime)
{

}

void Wolf::Collide(Game * p_pGame, const Entity * p_pOther)
{
	switch (p_pOther->GetType())
	{
	default:
		break;
	}
}

Entity::eType Wolf::GetType() const 
{
	return Entity::eType::Type_Rabit;
}

sf::Sprite * Wolf:: GetSprite( ) const
{
	return m_pSprite;
}