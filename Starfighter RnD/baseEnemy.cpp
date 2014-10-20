#include "stdafx.h"
#include "baseEnemy.h"


baseEnemy::baseEnemy()
{
	if (texture.loadFromFile("ASSETS/sprite/debugEnemy.png"))//this is the default debug text
	{

	}
	else
		texture.loadFromFile("");

	sprite.setTexture(texture);
	
}
baseEnemy::~baseEnemy()
{

}
sf::Vector2f baseEnemy::getPosition()
{
	return mPosition;
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
void baseEnemy::Draw(sf::RenderWindow *window)
{
	window->draw(sprite);
}
void baseEnemy::Update()
{

}