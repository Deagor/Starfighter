#ifndef COLLISIONMGR_H
#define COLLISIONMGR_H

#include "stdafx.h"

class CollisionMgr
{
public:

	static CollisionMgr* instance()
	{
		static CollisionMgr* mInstance = 0;
		
		if (mInstance == 0)	//Explict use of operator ==(CollisionMgr,int) to avoid ambiguity error
		{
			mInstance = new CollisionMgr();
		}

		return mInstance;
	}

	template<typename T>
	void CheckCollisionPlayertoEnemy(Player* thePlayer, T* theEnemy)
	{
		//locks are for thread safety due to the class being a singleton it will be impossible to have two threads run this
		//method at the same time (i believe) without thread-race issues therefore if two threads are set to run it at once
		//one will be forced to wait

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
			
		}
	}

	template<typename T>
	void CheckMissileCollisions(T* object, Missile* theMissile)
	{
		//locks are for thread safety due to the class being a singleton it will be impossible to have two threads run this
		//method at the same time (i believe) without thread-race issues therefore if two threads are set to run it at once
		//one will be forced to wait
		locker.lock();
		if (!theMissile->getIsPlayer())	//if its not the players missile (player can't collide with their own missile at this time
		{
			float objectX = object->getSprite().getPosition().x;
			float objectWidth = objectX + object->getSprite().getTexture()->getSize().x;
			float objectY = object->getSprite().getPosition().y;
			float objectHeight = objectY + object->getSprite().getTexture()->getSize().y;

			float missileX = theMissile->getSprite().getPosition().x;
			float missileWidth = missileX + theMissile->getSprite().getTexture()->getSize().x;
			float missileY = theMissile->getSprite().getPosition().y;
			float missileHeight = missileY + theMissile->getSprite().getTexture()->getSize().y;

			if ((objectX <= missileX + missileWidth) &&
				(objectX + objectWidth >= missileX) &&
				(objectY + objectHeight >= missileY) &&
				(objectY <= missileY + missileHeight))
			{
				locker.unlock();
				return true;
			}
		}
		locker.unlock();
		return false;
	}
	
	template<typename T>
	void HandleCollisionPlayertoEnemy(Player* thePlayer, T* theEnemy)
	{

	}

private:
	CollisionMgr()
	{
	}

	~CollisionMgr();

	std::mutex locker;

};

#endif