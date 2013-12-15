#include <Trap.h>
#include <Resources.h>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Trap::Trap(const sf::Vector2f p_position) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/Trap.png"))) 
{
	m_pSprite->setPosition(p_position);
}

Trap::~Trap()
{
	delete m_pSprite;
}

void Trap:: Update(Game * p_pGame, float p_deltaTime)
{

}

void Trap::Collide(Game * p_pGame, const Entity * p_pOther)
{
	switch (p_pOther->GetType())
	{
	default:
		break;
	}
}

Entity::eType Trap::GetType() const 
{
	return Entity::eType::Type_Trap;
}

sf::Sprite * Trap:: GetSprite( ) const
{
	return m_pSprite;
}
void Trap::addDamage(int p_damage) {
	;
}

int Trap::getHealth() const {
	return true;
}

bool Trap::getAlive() const {
	return true;
}