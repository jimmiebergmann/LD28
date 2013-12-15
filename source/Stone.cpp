#include <Stone.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Stone::Stone(sf::Vector2f p_position) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/Stone.png"))) 
{
	m_pSprite->setPosition( p_position );
}

Stone::~Stone()
{
	if( m_pSprite )
	{
		delete m_pSprite;
		m_pSprite = NULL;
	}
}

void Stone::Update( Game * p_pGame, float p_deltaTime )
{
	//Update
}

void Stone::Collide( Game * p_pGame, const Entity * p_pOther)
{
	//Collide
}

sf::Sprite * Stone::GetSprite( ) const
{
	return m_pSprite;
}

Entity::eType Stone::GetType( ) const
{
	return Type_Stone;
}
void Stone::addDamage(int p_damage) {
	;
}

int Stone::getHealth() const {
	return true;
}

bool Stone::getAlive() const {
	return true;
}