#include "stdafx.h"

Cannonfodder::Cannonfodder(sf::Vector2f position)
{
	setPosition(position);
	startPos = position;
	texture.loadFromFile("ASSETS/Sprites/Enemy/Cannon fodder.png");//this is the default debug text
	sprite.setTextureRect(sf::IntRect(0, 0, 52, 64));
	sprite.setTexture(texture);
	sprite.setScale(.8, .8);

	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	
	mSpeed = 1.0f;
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
	
	if (getPosition().x < 0)
	{
		offset = 0;
		mVelocity = sf::Vector2f(1, .3);
		mSpeed = 1;
	}
	
}
void Cannonfodder::Move(sf::RenderTarget& window)
{
	//sf::Vector2f topGoingDown = sf::Vector2f(0, 1);
	//sf::Vector2f bottomUp = sf::Vector2f(0, -1);
	sf::Vector2f leftGoingRight =sf::Vector2f(1, 0);
	sf::Vector2f rightGoingLeft = sf::Vector2f(-1, 0);

	if (offset != 0)
	{
		if (getPosition().x+texture.getSize().x/2 < startPos.x + texture.getSize().x / 2 - offset || getPosition().x  >startPos.x + texture.getSize().x / 2 + offset)
			mVelocity.x *= -1;
	}
	else
	{
		if (getPosition().x + texture.getSize().x / 2 >= window.getSize().x && ((mVelocity.x * rightGoingLeft.x + mVelocity.y * rightGoingLeft.y) < 0)||
			(getPosition().x - texture.getSize().x / 2 <= 0 && (mVelocity.x * leftGoingRight.x + mVelocity.y * leftGoingRight.y)<0))//this is for the collision against a wall the velocity is needed to determine the right collision.
		{
				mVelocity.x *= -1;
		}

	}
		


	auto velNor = sqrt((mVelocity.x * mVelocity.x) + (mVelocity.y * mVelocity.y));
	mVelocity /= velNor;
	setPosition(getPosition() + mVelocity * mSpeed);
	dir = sf::Vector2f(acos(mVelocity.x), asin(mVelocity.y));
	auto angle = dir.x*(180 / 3.14);
	sprite.setRotation(angle);
}
void Cannonfodder::Update(sf::RenderTarget& window)
{
	
	Move(window);
}
void Cannonfodder::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
	if (alive)
		window.draw(sprite,getTransform());
}