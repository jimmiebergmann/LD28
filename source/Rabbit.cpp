#include <Rabbit.h>
#include <Resources.h>
#include <Animation.h>

#include <SFML\Graphics\Sprite.hpp>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Rabbit::Rabbit(const sf::Vector2f p_position) :
	m_pMoveAnimation(new Animation("Data/Textures/RabbitMovingTest.png", 200, 2)),
	m_pIdleAnimation(new Animation("Data/Textures/RabbitTest.png", 200, 1)),
	m_pCurrentAnimation(NULL)
{
	m_pCurrentAnimation = m_pIdleAnimation;
	m_pCurrentAnimation->getSprite()->setPosition(p_position);

}

Rabbit::~Rabbit()
{
	if (!m_pMoveAnimation)
	{
		return;
	}
	delete m_pIdleAnimation;
	delete m_pMoveAnimation;
	m_pIdleAnimation = NULL;
	m_pMoveAnimation = NULL;
}

void Rabbit::Update(Game * p_pGame, float p_deltaTime)
{
	sf::Vector2f velocity(std::rand() % 10, std::rand() % 10);
	sf::Vector2f position = m_pCurrentAnimation->getSprite()->getPosition();
	position += velocity * 0.01f;
	if (velocity.x * velocity.y > 2.5f) {
		m_pCurrentAnimation = m_pMoveAnimation;
	} else {
		m_pCurrentAnimation = m_pIdleAnimation;
	}
	m_pCurrentAnimation->update();
	m_pCurrentAnimation->getSprite()->setPosition(position);
}

void Rabbit::Collide(Game * p_pGame, const Entity * p_pOther)
{
	switch (p_pOther->GetType())
	{
	case Entity::eType::Type_Wolf:
		//health--;
		break;
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
	return m_pCurrentAnimation->getSprite();
}