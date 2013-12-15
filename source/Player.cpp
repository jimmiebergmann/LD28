#include <Player.h>
#include <MemoryLeak.h>

static float PLAYERSPEED = 0.6;

Player::Player(sf::Vector2f position):
	m_Postition(position),
	m_pIdle(new Animation("Data/Textures/idle.png", 200, 2)),
	m_pWalkUp(new Animation("Data/Textures/walk_up.png", 200, 2)),
	m_pWalkDown(new Animation("Data/Textures/walk_down.png", 200, 2)),
	m_pWalkLeft(new Animation("Data/Textures/walk_left.png", 200, 2)),
	m_pWalkRight(new Animation("Data/Textures/walk_right.png", 200, 2)),
	m_pCurrentAnimation(m_pIdle)
{

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
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_Postition.y+=PLAYERSPEED;
		m_pCurrentAnimation = m_pWalkDown;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Postition.x+=PLAYERSPEED;
		m_pCurrentAnimation = m_pWalkRight;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Postition.x-=PLAYERSPEED;
		m_pCurrentAnimation = m_pWalkLeft;
	}
	m_pCurrentAnimation->update( );

	m_pCurrentAnimation->getSprite( )->setPosition(m_Postition);


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		// Attack();
	}



}

void Player::Collide(Game * p_pGame, const Entity * p_pOther)
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
