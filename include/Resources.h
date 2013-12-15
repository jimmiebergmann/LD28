#ifndef GAME_RESOURCES_H
#define GAME_RESOURCES_H

#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <unordered_map>
#include <string>


class Resources
{
public:

	static bool Load();
	static bool LoadSounds( const std::string &filename );
	static bool LoadTextures( const std::string &filename );
	static sf::Sound * GetSound( const std::string & filename );
	static sf::Texture * GetTexture( const std::string & filename );
	static void UnloadSounds();
	static void UnloadTextures();
	static void UnloadResources();

private:

	struct SoundData
	{
		sf::SoundBuffer * buffer;
		sf::Sound * sound;
	};

	typedef std::unordered_map< std::string, SoundData > SoundMap;
	static SoundMap s_Sounds;

	typedef std::unordered_map< std::string, sf::Texture* > TextureMap;
	static TextureMap s_Textures;

};
#endif
