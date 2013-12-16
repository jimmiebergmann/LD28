#include <Player.h>
#include <Stone.h>
#include <Turret.h>
#include <Trap.h>
#include <iostream>
#include <MemoryLeak.h>

static float PLAYERSPEED = 0.6;
static float ATTACKDAMAGE = 1;
static float ATTACK_COOLDOWN = 0.3f;

Player::Player(sf::Vector2f position):
	m_Position(position),
	m_pIdle(new Animation("Data/Textures/idle.png", 200, 2)),
	m_pWalkUp(new Animation("Data/Textures/idle.png", 200, 2)),
	m_pWalkDown(new Animation("Data/Textures/idle.png", 200, 2)),
	m_pWalkLeft(new Animation("Data/Textures/idle.png", 200, 2)),
	m_pWalkRight(new Animation("Data/Textures/idle.png", 200, 2)),
	m_pCurrentAnimation(m_pIdle)
{
	m_eCurrentDirection = eDirection::Type_Down;
	m_alive = true;
	m_health = 100;
}

Player::~Player()
{
	if(m_pIdle)
	{
		delete m_pIdle;
		m_pIdle = NULL;

		delete m_pWalkUp;
		m_pWalkUp = NULL;

		delete m_pWalkDown;
		m_pWalkDown = NULL;

		delete m_pWalkLeft;
		m_pWalkLeft = NULL;

		delete m_pWalkRight;
		m_pWalkRight = NULL;

		m_pCurrentAnimation = NULL;
	}
}


void Player::Update(Game * p_pGame, float p_deltaTime)
{
	AddObject(p_pGame);

	m_pCurrentAnimation = m_pIdle;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_Position.y-=PLAYERSPEED;
		m_pCurrentAnimation = m_pWalkUp;
		m_eCurrentDirection = eDirection::Type_Up;
	
		int xt = m_Position.x/32;
		int yt = m_Position.y/32;
		if(p_pGame->GetCollisionData(sf::Vector2u(xt,yt)) == true)
		{
			m_Position.y+=PLAYERSPEED;
		}
		m_pCurrentAnimation->getSprite( )->setPosition(m_Position);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_Position.y+=PLAYERSPEED;
		m_pCurrentAnimation = m_pWalkDown;
		m_eCurrentDirection = eDirection::Type_Down;


		int xt = m_Position.x/32;
		int yt = m_Position.y/32;
		if(p_pGame->GetCollisionData(sf::Vector2u(xt,yt)) == true)
		{
			m_Position.y-=PLAYERSPEED;
		}
		m_pCurrentAnimation->getSprite( )->setPosition(m_Position);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Position.x+=PLAYERSPEED;
		m_pCurrentAnimation = m_pWalkRight;
		m_eCurrentDirection = eDirection::Type_Right;

		int xt = m_Position.x/32;
		int yt = m_Position.y/32;
		if(p_pGame->GetCollisionData(sf::Vector2u(xt,yt)) == true)
		{
			m_Position.x-=PLAYERSPEED;
		}
		m_pCurrentAnimation->getSprite( )->setPosition(m_Position);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Position.x-=PLAYERSPEED;
		m_pCurrentAnimation = m_pWalkLeft;
		m_eCurrentDirection = eDirection::Type_Left;

		int xt = m_Position.x/32;
		int yt = m_Position.y/32;
		if(p_pGame->GetCollisionData(sf::Vector2u(xt,yt)) == true)
		{
			m_Position.x+=PLAYERSPEED;
		}
		m_pCurrentAnimation->getSprite( )->setPosition(m_Position);
	}


	m_pCurrentAnimation->update( );

	m_oldPosition = m_Position;
	m_pCurrentAnimation->getSprite( )->setPosition(m_Position);

	

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Attack(p_pGame);
				
	}



}

void Player::Collide(Game * p_pGame, Entity * p_pOther)
{
	switch (p_pOther->GetType())
	{
	case Type_Trap:
		if( true /*p_pOther->GetDayTime() == DAY */ )
		{
			p_pOther->addDamage( 1 );	// 1 == Set trap to active
		}
		break;
	
	case Type_Tree:

		//m_pCurrentAnimation->getSprite( )->setPosition(m_oldPosition);
		if(m_eCurrentDirection == eDirection::Type_Right)
		{
			m_Position.x-=PLAYERSPEED;
		}
		else if(m_eCurrentDirection == eDirection::Type_Left)
		{
			m_Position.x+=PLAYERSPEED;
		}
		else if(m_eCurrentDirection == eDirection::Type_Up)
		{
			m_Position.y+=PLAYERSPEED;
		}
		else if(m_eCurrentDirection == eDirection::Type_Down)
		{
			m_Position.y-=PLAYERSPEED;
		}
		break;

	default:
		break;
	}

}

sf::Sprite* Player::GetSprite( ) const
{
	return m_pCurrentAnimation->getSprite();
}

Entity::eType Player::GetType( ) const
{
	return Type_Player;
}

int Player::addDamage(int p_damage) {
	return 0;
}

void Player::Attack(Game * p_pGame )
{
	m_attackTime = m_attackClock.getElapsedTime();
	m_time = m_attackTime.asSeconds();


	if(m_eCurrentDirection == eDirection::Type_Up )
	{
		m_pWeaponCollision = sf::FloatRect(m_pCurrentAnimation->getSprite()->getPosition()+sf::Vector2f(0, -32), sf::Vector2f(32, 32));
	}
	else if(m_eCurrentDirection == eDirection::Type_Down )
	{
		m_pWeaponCollision = sf::FloatRect(m_pCurrentAnimation->getSprite()->getPosition()+sf::Vector2f(0, 32), sf::Vector2f(32, 32));
	}
	else if(m_eCurrentDirection == eDirection::Type_Right)
	{
		m_pWeaponCollision = sf::FloatRect(m_pCurrentAnimation->getSprite()->getPosition()+sf::Vector2f(32, 0), sf::Vector2f(32, 32));
	}
	else if(m_eCurrentDirection == eDirection::Type_Left)
	{
		m_pWeaponCollision = sf::FloatRect(m_pCurrentAnimation->getSprite()->getPosition()+sf::Vector2f(-32, 0), sf::Vector2f(32, 32));

	}
	
	if(m_time > ATTACK_COOLDOWN)
	{
		const Game::EntityVector& vec1 = p_pGame->GetEntities();
		for(Game::EntityVector::const_iterator i = vec1.begin(); i != vec1.end(); i++)
		{
			if((*i)->GetType() == Entity::eType::Type_Wolf)
			{
				sf::FloatRect EntityCollision = (*i)->GetSprite()->getGlobalBounds();
				if( m_pWeaponCollision.intersects(EntityCollision) == true)
				{
					(*i)->addDamage(ATTACKDAMAGE);
					break;
				}

			}

		}
		m_attackClock.restart();
	}

	
}

void Player::AddObject(Game * p_pGame)
{
	// add a stone
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
	{

		int x = m_Position.x/32;
		int y = m_Position.y/32;
		if(p_pGame->GetCollisionData(sf::Vector2u(x,y)) == false)
		{
			p_pGame->addEntity( new Stone(sf::Vector2f(x*32,y*32)));
		}
	}

	//add a turret
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
	{
		int x = m_Position.x/32;
		int y = m_Position.y/32;
		if(p_pGame->GetCollisionData(sf::Vector2u(x,y)) == false)
		{
		p_pGame->addEntity( new Turret(sf::Vector2f(x*32,y*32)));
		}
	}

	//add a trap
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
	{
		int x = m_Position.x/32;
		int y = m_Position.y/32;
		if(p_pGame->GetCollisionData(sf::Vector2u(x,y)) == false)
		{
		p_pGame->addEntity( new Trap(sf::Vector2f(x*32,y*32)));
		}
	}
}


int Player::getHealth() const {
	return m_health;
}

bool Player::getAlive() const {
	return m_alive;
}
