#include <Rabbit.h>
#include <Resources.h>

#include <SFML\Graphics\Sprite.hpp>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Rabbit::Rabbit(const sf::Vector2f p_position) :
<<<<<<< HEAD
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/Rabbit.png"))) 
=======
	m_position(p_position),
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/RabbitTest.png"))) 
>>>>>>> f2b631d7e78b879648ed6cb3716dc81375549669
{
	m_pSprite->setPosition(p_position);
}

Rabbit::~Rabbit()
{
	delete m_pSprite;
	m_pSprite = 0;
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