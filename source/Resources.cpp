#include "Resources.h"
#include <iostream>

Resources::SoundMap Resources::s_Sounds;
Resources::TextureMap Resources::s_Textures;

sf::Sound * Resources::GetSound( const std::string &filename )
{
	SoundMap::iterator it = s_Sounds.find( filename );

	if( it != s_Sounds.end( ) )
	{
		return it->second.sound;
	}


	sf::SoundBuffer * buffer = new sf::SoundBuffer;
	if( buffer->loadFromFile( filename ) == false )
	{
		std::cout << "Failed to load sound file." << std::endl;
		return NULL;
	}

	sf::Sound * sound = new sf::Sound( );
	sound->setBuffer( *buffer );

	SoundData data;
	data.buffer = buffer;
	data.sound = sound;
	s_Sounds[ filename ] = data;

	return sound;
}

sf::Texture * Resources::GetTexture( const std::string &filename )
{
	TextureMap::iterator it = s_Textures.find( filename );

	if( it != s_Textures.end( ) )
	{
		return it->second;
	}

	sf::Texture * texture = new sf::Texture;
	if( texture->loadFromFile( filename ) == false )
	
	{
		std::cout << "Failed to load sound file." << std::endl;
		return NULL;
	} 
	else 
	{
		return texture;
	}
}

void Resources::UnloadSounds()
{
	for(SoundMap::iterator it = s_Sounds.begin(); it != s_Sounds.end(); it++)
	{
		delete it->second.buffer;
		delete it->second.sound;
	}

}

void Resources::UnloadTextures()
{
	for(TextureMap::iterator it = s_Textures.begin(); it != s_Textures.end(); it++)
	{
		delete it->second;
	}
}

void Resources::UnloadResources()
{
	UnloadSounds();
	UnloadTextures();
}