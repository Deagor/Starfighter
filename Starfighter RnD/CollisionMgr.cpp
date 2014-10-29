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

template<typename T>
bool CollisionMgr::CheckCollisionPlayertoEnemy(Player* thePlayer, T* theEnemy)
{
	//locks are for thread safety due to the class being a singleton it will be impossible to have two threads run this
	//method at the same time (i believe) without thread-race issues therefore if two threads are set to run it at once
	//one will be forced to wait
	atomic<bool> collides = false;

	float playerX = thePlayer->getSprite().getPosition().x;
	float playerWidth = playerX + thePlayer->getSprite().getTexture()->getSize().x;
	float playerY = thePlayer->getSprite().getPosition().y;
	float playerHeight = playerY + thePlayer->getSprite().getTexture()->getSize().y;

	float enemyX = theEnemy->getSprite().getPosition().x;
	float enemyWidth = enemyX + theEnemy->getSprite().getTexture()->getSize().x;
	float enemyY = theEnemy->getSprite().getPosition().y;
	float enemyHeight = enemyY + theEnemy->getSprite().getTexture()->getSize().y;

	if ((playerX <= enemyX + enemyWidth) &&
		(playerX + playerWidth >= enemyX) &&
		(playerY + playerHeight >= enemyY) &&
		(playerY <= enemyY + enemyHeight))
	{
		collides = true;
	}
	return collides;
}

template<typename T>
bool CollisionMgr::CheckMissileCollisions(T* object, Missile* theMissile)
{
	//locks are for thread safety due to the class being a singleton it will be impossible to have two threads run this
	//method at the same time (i believe) without thread-race issues therefore if two threads are set to run it at once
	//one will be forced to wait
	locker.lock();
	if (!theMissile->getIsPlayer())	//if its not the players missile (player can't collide with their own missile at this time
	{
		float playerX = thePlayer->getSprite().getPosition().x;
		float playerWidth = playerX + thePlayer->getSprite().getTexture()->getSize().x;
		float playerY = thePlayer->getSprite().getPosition().y;
		float playerHeight = playerY + thePlayer->getSprite().getTexture()->getSize().y;

		float missileX = theMissile->getSprite().getPosition().x;
		float missileWidth = missileX + theMissile->getSprite().getTexture()->getSize().x;
		float missileY = theMissile->getSprite().getPosition().y;
		float missileHeight = missileY + theMissile->getSprite().getTexture()->getSize().y;

		if ((playerX <= missileX + missileWidth) &&
			(playerX + playerWidth >= missileX) &&
			(playerY + playerHeight >= missileY) &&
			(playerY <= missileY + missileHeight))
		{
			locker.unlock();
			return true;
		}
	}
	locker.unlock();
	return false;
}

