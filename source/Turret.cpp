
#include <Turret.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Turret::Turret(sf::Vector2f p_position) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/TurretBullet.png"))) 
{
	m_pSprite->setPosition( p_position );
}

Turret::~Turret()
{
	if( m_pSprite )
	{
		delete m_pSprite;
		m_pSprite = NULL;
	}
}

void Turret::Update( Game * p_pGame, float p_deltaTime)
{
	//Update
}

void Turret::Collide( Game * p_pGame, const Entity * p_pOther )
{
	//Collide
}

sf::Sprite * Turret::GetSprite( ) const
{
	return m_pSprite;
}

Entity::eType Turret::GetType( ) const
{
	return Type_Turret;
}