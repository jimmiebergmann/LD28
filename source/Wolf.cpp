#include <Wolf.h>
#include <Resources.h>
#include <Animation.h>

#include <SFML\Graphics\Sprite.hpp>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Wolf::Wolf(const sf::Vector2f p_position) :
	m_pWalkUp(new Animation("Data/Textures/wolf_up.png", 200, 2)),
	m_pWalkDown(new Animation("Data/Textures/wolf_down.png", 200, 2)),
	m_pWalkLeft(new Animation("Data/Textures/wolf_left.png", 200, 2)),
	m_pWalkRight(new Animation("Data/Textures/wolf_right.png", 200, 2)),
	m_pCurrentAnimation(NULL),
	m_health(3)
{
	int a = rand() % 4;
	Animation * ani[4] = {m_pWalkUp, m_pWalkDown, m_pWalkLeft, m_pWalkRight}; 
	m_pCurrentAnimation = ani[a];
	m_pCurrentAnimation->getSprite()->setPosition(p_position);
}

Wolf::~Wolf()
{
	if( m_pWalkUp )
	{
		delete m_pWalkUp;
		delete m_pWalkDown;
		delete m_pWalkLeft;
		delete m_pWalkRight;
		m_pWalkUp = NULL;
		m_pWalkDown = NULL;
		m_pWalkLeft = NULL;
		m_pWalkRight = NULL;
		m_pCurrentAnimation = NULL;
	}
}

void Wolf::Update(Game * p_pGame, float p_deltaTime)
{
	sf::Vector2f pos = m_pCurrentAnimation->getSprite()->getPosition();
	if (m_pCurrentAnimation == m_pWalkUp)
	{
		m_pCurrentAnimation = m_pWalkUp;
		pos += sf::Vector2f(0, -0.1f);
	}
	else if (m_pCurrentAnimation == m_pWalkDown)
	{
		m_pCurrentAnimation = m_pWalkDown;
		pos += sf::Vector2f(0, 0.1f);
	}
	else if (m_pCurrentAnimation == m_pWalkLeft)
	{
		m_pCurrentAnimation = m_pWalkLeft;
		pos += sf::Vector2f(-0.1f, 0);
	}
	else if (m_pCurrentAnimation == m_pWalkRight)
	{
		m_pCurrentAnimation = m_pWalkRight;
		pos += sf::Vector2f(0.1f, 0);
	}
	m_pCurrentAnimation->getSprite()->setPosition(pos);
	m_pCurrentAnimation->update();
}

void Wolf::Collide(Game * p_pGame, Entity * p_pOther)
{
	switch (p_pOther->GetType())
	{
	case Type_Bullet:
	if( p_pOther->getAlive() == true)
		{
			p_pOther->addDamage( 100 );
			this->addDamage(1);
		}
		break;

	default:
		break;
	}
}

Entity::eType Wolf::GetType() const 
{
	return Entity::eType::Type_Wolf;
}

sf::Sprite * Wolf:: GetSprite( ) const
{
	return m_pCurrentAnimation->getSprite();
}

int Wolf::addDamage(int p_damage)
{
	m_health -= p_damage;

	if(m_health <= 0)
	{
		m_health = false;
	}

	return m_health;
}

int Wolf::getHealth() const {
	return true;
}

bool Wolf::getAlive() const {
	return true;
}