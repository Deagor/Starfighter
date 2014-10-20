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