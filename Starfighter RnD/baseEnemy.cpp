#include "stdafx.h"

#include <vector>


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

void baseEnemy::setVelocity(sf::Vector2f vel)
{
	mVelocity = vel;
}
sf::Vector2f baseEnemy::getVelocity()
{
	return mVelocity;
}
float baseEnemy::getSpeed()
{
	return mSpeed;
}
bool baseEnemy::getContainsPowerUp()
{
	return containsPowerUP;
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
void baseEnemy::Move()
{

}

void baseEnemy::Update()
{

}