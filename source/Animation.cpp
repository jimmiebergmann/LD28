#include "Animation.h"


// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

Animation::Animation(const std::string& p_filename, int p_timePerFrame, int p_numFrames) : 
	m_timePerFrame(p_timePerFrame),
	m_numFrames(p_numFrames),
	m_currentFrame(0)
{
	m_pSprite = new sf::Sprite;
	m_pTexture = Resources::GetTexture(p_filename);
	m_pSprite->setTexture(*m_pTexture);

	// The rectangle below is used as an "view" for viewing only part of the sprites texture. Parameters are x position, y position, width and height. The width is divided by m_numFrames, this is the number of pixels per frame.
	sf::IntRect textureRect(0, 0, m_pTexture->getSize().x/m_numFrames, m_pTexture->getSize().y);
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

sf::Sprite* Animation::getSprite() const
{
	return m_pSprite;
}

