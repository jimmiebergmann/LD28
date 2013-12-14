#include <Rabbit.h>
#include <Resources.h>
#include <Animation.h>

#include <SFML\Graphics\Sprite.hpp>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Rabbit::Rabbit(const sf::Vector2f p_position) :
	m_position(p_position),
	m_pMoveAnimation(new Animation("Data/Textures/RabbitMovingTest.png", 200, 2)),
	m_pIdleAnimation(new Animation("Data/Textures/RabbitTest.png", 200, 1)) 
{
}

Rabbit::~Rabbit()
{
	if (!m_pMoveAnimation)
	{
		return;
	}
	delete m_pIdleAnimation;
	delete m_pMoveAnimation;
	m_pIdleAnimation = 0;
	m_pMoveAnimation = 0;
}

void Rabbit::Update(Game * p_pGame, float p_deltaTime)
{
	sf::Vector2f velocity(std::rand() % 10, std::rand() % 10);
	m_position += velocity * 0.01f;
	if (velocity.x * velocity.y > 2.5f) {
		m_pCurrentAnimation = m_pMoveAnimation;
	} else {
		m_pCurrentAnimation = m_pIdleAnimation;
	}
	m_pCurrentAnimation->update();
	m_pCurrentAnimation->setPosition(m_position);
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
	return const_cast<sf::Sprite *>(&m_pCurrentAnimation->getSprite());
}