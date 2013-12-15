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
	m_pCurrentAnimation(NULL)
{
	m_pCurrentAnimation = m_pWalkUp;
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
	m_pCurrentAnimation->update();
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
	return m_pCurrentAnimation->getSprite();
}

void Wolf::addDamage(int p_damage) {
	;
}

int Wolf::getHealth() const {
	return true;
}

bool Wolf::getAlive() const {
	return true;
}