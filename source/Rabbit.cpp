#include <Rabbit.h>
#include <Resources.h>

#include <SFML\Graphics\Sprite.hpp>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Rabbit::Rabbit(const sf::Vector2f p_position) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/Rabbit.png"))) 
{
	m_pSprite->setPosition(p_position);
}

Rabbit::~Rabbit()
{

}

void Rabbit::Update(Game * p_pGame, float p_deltaTime)
{

}

void Rabbit::Collide(Game * p_pGame, const Entity * p_pOther)
{
	switch (p_pOther->GetType())
	{
	default:
		break;
	}
}

Entity::eType Rabbit::GetType() const 
{
	return Entity::eType::Type_Rabit;
}

sf::Sprite * Rabbit:: GetSprite( ) const
{
	return m_pSprite;
}