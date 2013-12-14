
#include <TurretBullet.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

TurretBullet::TurretBullet(sf::Vector2f p_position) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/TurretBullet.png"))) 
{
	m_pSprite->setPosition( p_position );
}

TurretBullet::~TurretBullet()
{
	// Shall I unload Texture here?
}

void TurretBullet::Update( Game * p_pGame, float p_deltaTime)
{
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