#include <cmath>

#include <TurretBullet.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

TurretBullet::TurretBullet(sf::Vector2f p_position, Entity * p_enemyTarget) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/TurretBullet.png"))),
	m_pEnemyTarget(p_enemyTarget)
{
	m_pSprite->setPosition( p_position );
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

	sf::Vector2f diraction = m_pEnemyTarget->GetSprite()->getPosition() - m_pSprite->getPosition();
	float len = std::sqrt(diraction.x * diraction.x + diraction.y * diraction.y);
	if (len < 32.0f) {
		//alive = false;
	}
	diraction *= 1.0f / len;

	m_pSprite->setOrigin(5.0f, 5.0f);
	m_pSprite->rotate(10.1);
	//m_pSprite->setOrigin(0.0f, 0.0f);

	m_pSprite->move(diraction);

	//Update
}

void TurretBullet::Collide( Game * p_pGame, const Entity * p_pOther )
{
	//Collide
}

sf::Sprite * TurretBullet::GetSprite( ) const
{
	return m_pSprite;
}

Entity::eType TurretBullet::GetType( ) const
{
	return Type_Turret;
}

void TurretBullet::addDamage(int p_damage) {
	;
}

int TurretBullet::getHealth() const {
	return true;
}

bool TurretBullet::getAlive() const {
	return true;
}