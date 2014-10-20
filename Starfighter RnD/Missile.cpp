#include "stdafx.h"
#include "Missile.h"


Missile::Missile(bool isPlayer)
{
	mIsPlayer = isPlayer;
	if (mIsPlayer)
	{
		if (mTexture.loadFromFile(""))
		{
			mSprite.setTexture(mTexture);
		}
		else
		{
			mTexture.loadFromFile("ASSETS/sprite/debugEnemy.png");
		}
	}

	mSprite.setTexture(mTexture);
}


Missile::~Missile()
{
}
