#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <string>
#include "Resources.h"

class Animation
{
public:
	Animation(const std::string& p_filename, int p_timePerFrame, int p_numFrames);
	~Animation();

	void update();
	sf::Sprite* getSprite() const;

private:

	sf::Clock m_frameTimer;
	sf::Texture * m_pTexture;
	sf::Sprite * m_pSprite;
	int m_timePerFrame;
	int m_numFrames;
	int m_currentFrame;

};
#endif