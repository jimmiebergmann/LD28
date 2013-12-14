#include <Fence.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Fence::Fence(sf::Vector2f p_position) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/Fence.png"))) 
{
	m_pSprite->setPosition( p_position );
}

Fence::~Fence()
{
	if( m_pSprite )
	{
		delete m_pSprite;
		m_pSprite = NULL;
	}
}

void Fence::Update( Game * p_pGame, float p_deltaTime)
{
	//Update
}

void Fence::Collide( Game * p_pGame, const Entity * p_pOther )
{
	//Collide
}

sf::Sprite * Fence::GetSprite( ) const
{
	return m_pSprite;
}

Entity::eType Fence::GetType( ) const
{
	return Type_Fence;
}