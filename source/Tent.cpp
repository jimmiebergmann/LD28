#include <Tent.h>
#include <Resources.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Tent::Tent(const sf::Vector2f p_position) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/Tent.png"))) 
{
	m_pSprite->setPosition(p_position);
}

Tent::~Tent()
{
	if( m_pSprite )
	{
		delete m_pSprite;
		m_pSprite = NULL;
	}
}

void Tent:: Update(Game * p_pGame, float p_deltaTime)
{

}

void Tent::Collide(Game * p_pGame, const Entity * p_pOther)
{
	switch (p_pOther->GetType())
	{
	default:
		break;
	}
}

Entity::eType Tent::GetType() const 
{
	return Entity::eType::Type_Tent;
}

sf::Sprite * Tent:: GetSprite( ) const
{
	return m_pSprite;
}
void Tent::addDamage(int p_damage) {
	;
}

int Tent::getHealth() const {
	return true;
}

bool Tent::getAlive() const {
	return true;
}