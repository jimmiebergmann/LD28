#include <TurretBullet.h>
#include <Turret.h>
#include <Game.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>


static const int g_TurretRange = 100;

Turret::Turret(sf::Vector2f p_position) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/Turret.png"))),
	m_turretTimer(0)
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
	if (m_turretTimer > 60)
	{
		Attack( p_pGame );
		m_turretTimer = 0;
	}

	m_turretTimer++;
}

void Turret::Collide( Game * p_pGame, const Entity * p_pOther )
{
	//Collide
}

void Turret::Attack( Game * p_pGame )
{
	float CurrentClosestEnemyDistance;
	Entity * pCurrentClosestEnemy = NULL;
	const Game::EntityVector & vec1 = p_pGame->GetEntities();
//	for(BoltVector::iterator i = temp.begin(); i != temp.end(); i++)
	for(Game::EntityVector::const_iterator i = vec1.begin(); i != vec1.end(); i++)
	{
		if((*i)->GetType() == Type_Wolf)
		{
			const float & x = (*i)->GetSprite()->getPosition().x - m_pSprite->getPosition().x;
			const float & y = (*i)->GetSprite()->getPosition().y - m_pSprite->getPosition().y;
			if(pCurrentClosestEnemy == NULL)
			{
					pCurrentClosestEnemy = (*i);
					CurrentClosestEnemyDistance = x * x + y * y;
			
			}
			else if(pCurrentClosestEnemy != NULL)
			{
				if(	CurrentClosestEnemyDistance >  x * x + y * y)
				{
					pCurrentClosestEnemy = (*i);
					CurrentClosestEnemyDistance = x * x + y * y;
				}
			}
		}
	}
	if(pCurrentClosestEnemy != NULL)
	{
		// This will happen if the enemy is 
		if(g_TurretRange * g_TurretRange > CurrentClosestEnemyDistance)
		{
			p_pGame->addEntity(new TurretBullet(m_pSprite->getPosition() + sf::Vector2f(16, 16), pCurrentClosestEnemy));
		}
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

void Turret::addDamage(int p_damage) {
	;
}

int Turret::getHealth() const {
	return true;
}

bool Turret::getAlive() const {
	return true;
}