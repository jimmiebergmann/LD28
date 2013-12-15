#include "Resources.h"
#include <iostream>

// MemoryLeak.h filen !ALLTID SIST!
#include <MemoryLeak.h>

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
	TextureMap::iterator & it = s_Textures.find( filename );

	return it->second;
}

void Resources::UnloadSounds()
{
	for(SoundMap::iterator it = s_Sounds.begin(); it != s_Sounds.end(); it++)
	{
		delete it->second.buffer;
		delete it->second.sound;
	}
	
	s_Sounds.clear( );

}

void Resources::UnloadTextures()
{
	for(TextureMap::iterator it = s_Textures.begin(); it != s_Textures.end(); it++)
	{
		delete it->second;
	}
	s_Textures.clear( );
}

void Resources::Unload()
{
	UnloadSounds();
	UnloadTextures();
}

bool Resources::LoadSounds( const std::string &filename )
{
	return true;
}

bool Resources::LoadTextures( const std::string &filename ) 
{
	TextureMap::iterator it = s_Textures.find( filename );

	if( it != s_Textures.end( ) )
	{
		return true;
	}

	sf::Texture * texture = new sf::Texture;
	if(texture->loadFromFile( filename ) == false)
	{
		std::cout << "Failed to load sound file." << std::endl;
		delete texture;
		return false;
	}
	std::cout << "ok: " << filename << std::endl;
	s_Textures[filename] = texture;
	return true;
}

bool Resources::Load()
{
	bool succ = true;
	succ = LoadTextures("Data/Textures/RabbitMovingTest.png");
	succ = LoadTextures("Data/Textures/RabbitTest.png");
	succ = LoadTextures("Data/Textures/idle.png");
	succ = LoadTextures("Data/Textures/walk_up.png");
	succ = LoadTextures("Data/Textures/walk_down.png");
	succ = LoadTextures("Data/Textures/walk_left.png");
	succ = LoadTextures("Data/Textures/walk_right.png");
	succ = LoadTextures("Data/Textures/Tent.png");
	succ = LoadTextures("Data/Textures/Stone.png");	
	succ = LoadTextures("Data/Textures/Trap.png");	
	succ = LoadTextures("Data/Textures/pine.png");
	succ = LoadTextures("Data/Textures/Turret.png");	
	succ = LoadTextures("Data/Textures/TurretBullet.png");
	succ = LoadTextures("Data/Textures/wolf_up.png");
	succ = LoadTextures("Data/Textures/wolf_down.png");
	succ = LoadTextures("Data/Textures/wolf_left.png");
	succ = LoadTextures("Data/Textures/wolf_right.png");
	succ = LoadTextures("Data/Textures/Grass.png");
	succ = LoadTextures("Data/Textures/Fence.png");
	
	if (!succ) {
		Resources::Unload();
	}
	return succ;
}

