#include <Player.h>
#include <MemoryLeak.h>

void Player::Update(Game * p_pGame, float p_deltaTime)
{

}

void Player::Collide(Game * p_pGame, const Entity * p_pOther)
{

}

sf::Sprite* Player::GetSprite( ) const
{
	return NULL;
}

Entity::eType Player::GetType( ) const
{
	return Type_Player;
}
