#include "stdafx.h"
#include "baseEnemy.h"


baseEnemy::baseEnemy()
{
	if (texture.loadFromFile("ASSETS/Sprites/debug.png"))//this is the default debug text
	{

	}
	else
		texture.loadFromFile("");

	sprite.setTexture(texture);
	
}
baseEnemy::~baseEnemy()
{

}

void baseEnemy::setContainsPowerUp()
{
	int randPowerUP = rand() % 100;
	if (randPowerUP == 10)
	{
		containsPowerUP = true;
	}
	else
		containsPowerUP = false;
}
void baseEnemy::Move(sf::RenderTarget& window)
{

}
void baseEnemy::Update(sf::RenderTarget& window)
{

}