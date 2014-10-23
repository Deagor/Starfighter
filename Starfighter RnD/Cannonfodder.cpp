#include "stdafx.h"

Cannonfodder::Cannonfodder(sf::Vector2f position)
{
	setPosition(position);
	setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	startPos = position;
	mSpeed = 1.0f;
	texture.loadFromFile("ASSETS/Sprites/debug.png");//this is the default debug text
	sprite.setTexture(texture);
	alive = true;
	setStartVelocity();
	

}
Cannonfodder::~Cannonfodder()
{

}
void Cannonfodder::setStartVelocity()
{
	int randVel = rand() % 2;
	if (getPosition().y < 0 && randVel == 0)
	{
		mVelocity = sf::Vector2f(.7, 1);
		offset = 50;
	}
	else if (getPosition().y < 0 && randVel == 1)
	{
			mVelocity = sf::Vector2f(-.7, 1);
			offset = 50;
	}
	else if (getPosition().x < 0)
	{
		offset = 500;
		mVelocity = sf::Vector2f(1, .2);
		mSpeed = 2;
	}
	
}
void Cannonfodder::Move()
{

	if (getPosition().x < startPos.x + texture.getSize().x / 2 - offset || getPosition().x  >startPos.x + texture.getSize().x / 2 + offset)
		mVelocity.x *= -1;

	setPosition(getPosition() + mVelocity * mSpeed);
}
void Cannonfodder::Update()
{
	
	Move();
}
void Cannonfodder::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
	if (alive)
		window.draw(sprite,getTransform());
}