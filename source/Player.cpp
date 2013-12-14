#include <Player.h>
#include <MemoryLeak.h>

static float PLAYERSPEED = 2;

Player::Player(sf::Vector2f position):
	m_Postition(position),
	m_Idle(new Animation("Data/Textures/idle.png", 200, 2)),
	m_WalkUp(new Animation("Data/Textures/walk_up.png", 200, 2)),
	m_WalkDown(new Animation("Data/Textures/walk_down.png", 200, 2)),
	m_WalkLeft(new Animation("Data/Textures/walk_left.png", 200, 2)),
	m_WalkRight(new Animation("Data/Textures/walk_right.png", 200, 2)),
	m_CurrentAnimation(m_Idle)
{

}

void Player::Update(Game * p_pGame, float p_deltaTime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_Postition.y-=PLAYERSPEED;
		m_CurrentAnimation = m_WalkUp;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_Postition.y+=PLAYERSPEED;
		m_CurrentAnimation = m_WalkDown;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_Postition.x+=PLAYERSPEED;
		m_CurrentAnimation = m_WalkRight;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_Postition.x-=PLAYERSPEED;
		m_CurrentAnimation = m_WalkLeft;
	}

	m_CurrentAnimation->getSprite.setPosition(m_Postition);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		// Attack();
	}



}

void Player::Collide(Game * p_pGame, const Entity * p_pOther)
{

}

sf::Sprite* Player::GetSprite( ) const
{
	return m_CurrentAnimation->getSprite();
}

Entity::eType Player::GetType( ) const
{
	return Type_Player;
}
