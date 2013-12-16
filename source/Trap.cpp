#include <Trap.h>
#include <Resources.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Trap::Trap(const sf::Vector2f p_position) :
	ActiveTrap(Resources::GetTexture("Data/Textures/ActiveTrap.png")),
	CloseTrap(Resources::GetTexture("Data/Textures/ClosedTrap.png")),
	m_pSprite(new sf::Sprite),
	m_alive(true),
	m_activeTrap(true)
{
	m_pSprite->setTexture(*ActiveTrap);
	m_pSprite->setPosition(p_position);
}

Trap::~Trap()
{
	delete m_pSprite;
}

void Trap:: Update(Game * p_pGame, float p_deltaTime)
{
	if(m_activeTrap == true)
	{
		m_pSprite->setTexture(*ActiveTrap);
	}
	else if(m_activeTrap == false)
	{
		m_pSprite->setTexture(*CloseTrap);
	}


}

void Trap::Collide(Game * p_pGame, Entity * p_pOther)
{
	switch (p_pOther->GetType())
	{
	case Type_Wolf:
		if( p_pOther->getAlive() == true && m_activeTrap == true && m_alive == true)
		{
			p_pOther->addDamage( 100 );
			this->addDamage( 0 );	// 0 == Set trap to active
		}
		break;

	case Type_Player:
		if( true /*p_pOther->GetDayTime() == DAY */ )
		{
			this->addDamage( 1 );	// 1 == Set trap to active
		}
		break;

	default:
		break;
	}
}

Entity::eType Trap::GetType() const 
{
	return Entity::eType::Type_Trap;
}

sf::Sprite * Trap:: GetSprite( ) const
{
	return m_pSprite;
}
int Trap::addDamage(int p_damage)
{
	if(p_damage == 0)
	{
		m_activeTrap = false;
	}
	else if(p_damage == 1)
	{
		m_activeTrap = true;
	}

	return 0;
}

int Trap::getHealth() const 
{
	return m_health;
}

bool Trap::getAlive() const 
{
	return m_alive;
}