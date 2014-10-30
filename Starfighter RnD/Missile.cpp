#include "stdafx.h"
#include "Missile.h"


Missile::Missile(bool isPlayer, sf::Vector2f direction, sf::Vector2f pos) : mSpeed(2.5)	//Speed needs to be tweaked further in Sprint
{
	mIsPlayer = isPlayer;
	if (mIsPlayer)
	{
		if (mTexture.loadFromFile(""))
		{
		}
		else
		{
			mTexture.loadFromFile("ASSETS/Sprites/debug.png");	//if it fails load placeholder
		}
	}
	else	//is enemy missile
	{
		if (mTexture.loadFromFile(""))
		{
		}
		else
		{
			mTexture.loadFromFile("ASSETS/Sprites/debug.png");	 //if it fails load placeholder
		}
	}
	mSprite.setTexture(mTexture);
	setPosition(pos);
	mVelocity = direction * mSpeed;
}

void Missile::draw(sf::RenderTarget& window,sf::RenderStates state) const
{
	window.draw(mSprite,getTransform());
}


void Missile::Update()
{
	setPosition((getPosition() + mVelocity));
}

Missile::~Missile()
{

}
