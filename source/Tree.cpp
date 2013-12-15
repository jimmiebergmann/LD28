#include <Tree.h>


// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Tree::Tree(sf::Vector2f p_position) :
	m_pSprite(new sf::Sprite(*Resources::GetTexture("Data/Textures/pine.png"))) 
{
	m_pSprite->setOrigin( 0.0f, 32.0f );
	m_pSprite->setPosition( p_position );
}

Tree::~Tree()
{
	if( m_pSprite )
	{
		delete m_pSprite;
		m_pSprite = NULL;
	}
}

void Tree::Update( Game * p_pGame, float p_deltaTime )
{
	//Update
}

void Tree::Collide( Game * p_pGame, Entity * p_pOther )
{
	//Collide
}

sf::Sprite * Tree::GetSprite( ) const
{
	return m_pSprite;
}

Entity::eType Tree::GetType( ) const
{
	return Type_Tree;
}

int Tree::addDamage(int p_damage) {
	return 0;
}

int Tree::getHealth() const {
	return true;
}

bool Tree::getAlive() const {
	return true;
}