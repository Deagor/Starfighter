#include "stdafx.h"
#include "CollisionMgr.h"

CollisionMgr* CollisionMgr::mInstance = 0;


//Private Constructor
CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{
}

CollisionMgr* CollisionMgr::instance()
{
	if (mInstance == 0)
	{
		mInstance = new CollisionMgr();
	}
	return mInstance;
}

bool CollisionMgr::CheckCollisionPlayertoMissile(Player* thePlayer,Missile* theMissile)
{
	//locks are for thread safety due to the class being a singleton it will be impossible to have two threads run this
	//method at the same time (i believe) without thread-race issues therefore if two threads are set to run it at once
	//one will be forced to wait
	locker.lock();
	if (!theMissile->getIsPlayer())	//if its not the players missile (player can't collide with their own missile at this time
	{
		float playerX = thePlayer->getSprite().getPosition().x;
		float playerXWidth = playerX + thePlayer->getSprite().getTexture()->getSize().x;
		float playerY = thePlayer->getSprite().getPosition().y;
		float playerYHeight = playerY + thePlayer->getSprite().getTexture()->getSize().y;

		float missileX = theMissile->getSprite().getPosition().x;
		float missileXWidth = missileX + theMissile->getSprite().getTexture()->getSize().x;
		float missileY = theMissile->getSprite().getPosition().y;
		float missileYHeight = missileY + theMissile->getSprite().getTexture()->getSize().y;

		if (missileX <= playerXWidth && missileXWidth >= playerX && missileY <= playerYHeight && missileYHeight >= playerY)
		{
			locker.unlock();
			return true;
		}
	}
	locker.unlock();
	return false;
}