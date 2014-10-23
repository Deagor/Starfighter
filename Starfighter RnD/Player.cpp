#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	//load the correct texture or load the debug texture if something is wrong
	if (mTexture.loadFromFile("ASSETS/Sprites/Player/Player.png")){}
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
	//update the direction(maybe not everytime update is called)
	direction = sf::Vector2f(cos(getRotation()), sin(getRotation()));
	direction /= std::sqrt((direction.x * direction.x) + (direction.y * direction.y));
}//end Update()

void Player::Move()//may or may not be needed. Could possibly deal with movement in update() only
{
	//detecting keyboard input for player to accelerate foward and then decelerate back to 0
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
			speed -= 0.1;
		else if (speed < 0)
			speed = 0;
	}

	//For turning the ship
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Turn(-1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Turn(1);
	}
	setPosition(getPosition() + (getDirection() * getSpeed()));
}//end Move()

void Player::Turn(float a)
{
	rotate(a);
}//end Rotate()

void Player::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
	window.draw(mSprite, getTransform());
}//end Draw()
