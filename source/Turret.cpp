
#include <Turret.h>
#include <Game.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>


static const int g_TurretRange = 500;

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

	Attack( p_pGame );
}

void Turret::Collide( Game * p_pGame, const Entity * p_pOther )
{
	//Collide
}

void Turret::Attack( Game * p_pGame )
{
	float CurrentClosestEnemyDistance = 100000;
	Entity * pCurrentClosestEnemy;
	Game::EntityVector & vec1 = p_pGame->GetEntities();
//	for(BoltVector::iterator i = temp.begin(); i != temp.end(); i++)
	for(Game::EntityVector::iterator i = vec1.begin(); i != vec1.end(); i++)
	{
		if(	CurrentClosestEnemyDistance * CurrentClosestEnemyDistance  >  
		(*i)->GetSprite()->getPosition().x * (*i)->GetSprite()->getPosition().x + 
		(*i)->GetSprite()->getPosition().y * (*i)->GetSprite()->getPosition().y)
		{
			pCurrentClosestEnemy = (*i);
			CurrentClosestEnemyDistance =	(*i)->GetSprite()->getPosition().x * (*i)->GetSprite()->getPosition().x + 
											(*i)->GetSprite()->getPosition().y * (*i)->GetSprite()->getPosition().y;
		}
	}

	// This will happen if the enemy is 
	if( g_TurretRange * g_TurretRange > CurrentClosestEnemyDistance * CurrentClosestEnemyDistance)
	{
	//	p_pGame->CreateTurretullet(pCurrentClosestEnemy);
	}

}


sf::Sprite * Turret::GetSprite( ) const
{
	return m_pSprite;
}

Entity::eType Turret::GetType( ) const
{
	return Type_Turret;
}