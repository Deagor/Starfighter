#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	//load the correct texture or load the debug texture if something is wrong
	if (mTexture.loadFromFile("ASSETS/Sprites/Player/Player.png")){ }
	else mTexture.loadFromFile("ASSETS/Sprites/debug.png");	//if it fails load placeholder
	mSprite.setTexture(mTexture);
	setPosition(sf::Vector2f(300, 300));
	setOrigin(sf::Vector2f(mTexture.getSize().x / 2, mTexture.getSize().y / 2));
	setRotationValue(0.05);
	setSpeed(0);
	setVelocity(sf::Vector2f(1, 1));
}//end constructor


Player::~Player()
{
	//blank destructor for now
}

void Player::Update()
{
	Move();
	Turn();
}//end Update()

void Player::Move()//may or may not be needed. Could possibly deal with movement in update() only
{
	//detecting keyboard input for player to accelerate foward and then decelerate
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (getSpeed() < getMaxSpeed())
		{
			speed += 0.1;
		}
	}
	else
	{
		if (speed > 0)
			speed -= 0.01;
	}
	
}//end Move()

void Player::Turn()
{
	rotate(getRotationValue());
	sf::Vector2f directionVect(cos(getRotation()), sin(getRotation()));
	directionVect /= std::sqrt((directionVect.x * directionVect.x) + (directionVect.y * directionVect.y));
}//end Rotate()

void Player::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
	window.draw(mSprite, getTransform());
}//end Draw()
