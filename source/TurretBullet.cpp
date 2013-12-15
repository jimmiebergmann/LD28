#include <cmath>

#include <TurretBullet.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

TurretBullet::TurretBullet(sf::Vector2f p_position, Entity * p_enemyTarget) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/TurretBullet.png"))),
	m_alive(true),
	direction(),
	m_frameTimer(0)
{
	m_pSprite->setOrigin(5.0f, 5.0f);
	m_pSprite->setPosition(p_position);
	sf::Vector2f offset(p_enemyTarget->GetSprite()->getGlobalBounds().width, p_enemyTarget->GetSprite()->getGlobalBounds().height);
	direction = p_enemyTarget->GetSprite()->getPosition() + (offset * 0.5f) - m_pSprite->getPosition();
	float len = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	direction *= 1.0f / len;
}

TurretBullet::~TurretBullet()
{
	if( m_pSprite )
	{
		delete m_pSprite;
		m_pSprite = NULL;
	}
}

void TurretBullet::Update( Game * p_pGame, float p_deltaTime)
{
	m_frameTimer++;
	if (m_frameTimer >= 100) {
		m_alive = false;
	}
	m_pSprite->rotate(10.1);

	m_pSprite->move(direction);

}

void TurretBullet::Collide( Game * p_pGame, Entity * p_pOther )
{
	switch (p_pOther->GetType())
	{
	case Type_Wolf:
		if(( p_pOther->getAlive() == true) && (m_alive == true))
		{
			p_pOther->addDamage(1);
			this->addDamage(1);
		}
		break;
	default:
		break;
	}

}

sf::Sprite * TurretBullet::GetSprite( ) const
{
	return m_pSprite;
}

Entity::eType TurretBullet::GetType( ) const
{
	return Type_Bullet;
}

int TurretBullet::addDamage(int p_damage)
{
	m_alive = false;
	return 0;
}

int TurretBullet::getHealth() const 
{
	return m_health;
}

bool TurretBullet::getAlive() const 
{
	return m_alive;
}