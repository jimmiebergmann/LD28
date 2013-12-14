#include "Animation.h"


// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Animation::Animation(const std::string& filename, int timePerFrame, int numFrames) : 
	m_timePerFrame(timePerFrame),
	m_numFrames(numFrames),
	m_currentFrame(0)
{
	m_pSprite = new sf::Sprite;
	m_texture = *Resources::GetTexture(filename);
	m_pSprite->setTexture(m_texture);

	// The rectangle below is used as an "view" for viewing only part of the sprites texture. Parameters are x position, y position, width and height. The width is divided by m_numFrames, this is the number of pixels per frame.
	sf::IntRect textureRect(0, 0, m_texture.getSize().x/m_numFrames, m_texture.getSize().y);
	m_pSprite->setTextureRect(textureRect);
}

Animation::~Animation()
{
	delete m_pSprite;
}

void Animation::update()
{
	// If timer is higher than the limit, switch to next frame
	if(m_frameTimer.getElapsedTime().asMilliseconds() > m_timePerFrame)
	{
		// Restart the timer
		m_frameTimer.restart();

		m_currentFrame++;

		// Wrap around if we're at the end of the sprite-sheet
		if(m_currentFrame >= m_numFrames)
		{
			m_currentFrame = 0;
		}

		// Get a copy of the old texture rect
		sf::IntRect currentRect = m_pSprite->getTextureRect();
		// Set x-position (left) of the rectangle. The assignment gives 0 for the first frame, 1*width for the second etc.
		currentRect.left = currentRect.width * m_currentFrame;

		m_pSprite->setTextureRect(currentRect);
	}
}

void Animation::setPosition(const sf::Vector2f& position)
{
	m_pSprite->setPosition(position);
}

sf::Sprite* Animation::getSprite() const
{
	return m_pSprite;
}

