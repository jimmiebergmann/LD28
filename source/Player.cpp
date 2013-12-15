#include <Player.h>
#include <MemoryLeak.h>

static float PLAYERSPEED = 0.6;
static float ATTACKDAMAGE = 1;

Player::Player(sf::Vector2f position):
	m_Postition(position),
	m_pIdle(new Animation("Data/Textures/idle.png", 200, 2)),
	m_pWalkUp(new Animation("Data/Textures/walk_up.png", 200, 2)),
	m_pWalkDown(new Animation("Data/Textures/walk_down.png", 200, 2)),
	m_pWalkLeft(new Animation("Data/Textures/walk_left.png", 200, 2)),
	m_pWalkRight(new Animation("Data/Textures/walk_right.png", 200, 2)),
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
	m_pCurrentAnimation = m_pIdle;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_Postition.y-=PLAYERSPEED;
		m_pCurrentAnimation = m_pWalkUp;
		m_eCurrentDirection = eDirection::Type_Up;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_Postition.y+=PLAYERSPEED;
		m_pCurrentAnimation = m_pWalkDown;
		m_eCurrentDirection = eDirection::Type_Down;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Postition.x+=PLAYERSPEED;
		m_pCurrentAnimation = m_pWalkRight;
		m_eCurrentDirection = eDirection::Type_Right;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Postition.x-=PLAYERSPEED;
		m_pCurrentAnimation = m_pWalkLeft;
		m_eCurrentDirection = eDirection::Type_Left;
	}


	m_pCurrentAnimation->update( );


	m_pCurrentAnimation->getSprite( )->setPosition(m_Postition);


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Attack(p_pGame);
				
	}



}

void Player::Collide(Game * p_pGame, Entity * p_pOther)
{
	if(p_pOther->GetType() == Entity::eType::Type_Wolf )
	{
		//take damage
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
	if(m_eCurrentDirection == eDirection::Type_Up)
	{
		m_pWeaponCollision = sf::FloatRect(m_pCurrentAnimation->getSprite()->getPosition()+sf::Vector2f(0, 32), sf::Vector2f(32, 32));
	}

	else if(m_eCurrentDirection == eDirection::Type_Down)
	{
		m_pWeaponCollision = sf::FloatRect(m_pCurrentAnimation->getSprite()->getPosition()+sf::Vector2f(0, -32), sf::Vector2f(32, 32));

	}
	else if(m_eCurrentDirection == eDirection::Type_Right)
	{
		m_pWeaponCollision = sf::FloatRect(m_pCurrentAnimation->getSprite()->getPosition()+sf::Vector2f(32, 0), sf::Vector2f(32, 32));

	}
	else if(m_eCurrentDirection == eDirection::Type_Left)
	{
		m_pWeaponCollision = sf::FloatRect(m_pCurrentAnimation->getSprite()->getPosition()+sf::Vector2f(32, 0), sf::Vector2f(32, 32));

	}
	
	Game::EntityVector& vec1 = p_pGame->GetEntities();
	for(Game::EntityVector::iterator i = vec1.begin(); i != vec1.end(); i++)
	{
		if((*i)->GetType() == Entity::eType::Type_Wolf)
		{
			sf::FloatRect EntityCollision = (*i)->GetSprite()->getGlobalBounds();
			if( m_pWeaponCollision.intersects(EntityCollision) == true)
			{
				(*i)->addDamage(ATTACKDAMAGE);
			}

		}

	}


	
}


int Player::getHealth() const {
	return m_health;
}

bool Player::getAlive() const {
	return m_alive;
}
