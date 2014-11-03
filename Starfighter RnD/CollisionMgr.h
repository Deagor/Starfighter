#ifndef COLLISIONMGR_H
#define COLLISIONMGR_H

#include "stdafx.h"

class CollisionMgr
{
public:

	static CollisionMgr* instance()
	{
		static CollisionMgr* mInstance = 0;
		
		if (mInstance == 0)
		{
			mInstance = new CollisionMgr();
		}

		return mInstance;
	}

	template<typename T>
	void CheckCollisionPlayertoEnemy(Player* thePlayer, T* theEnemy)
	{
		sf::FloatRect playerBox = thePlayer->getTransform().transformRect(thePlayer->getSprite().getGlobalBounds());
		sf::FloatRect theEnemyBox = theEnemy->getTransform().transformRect(theEnemy->getSprite().getGlobalBounds());

		if (playerBox.intersects(theEnemyBox))
		{
			HandleCollisionPlayertoEnemy(thePlayer, theEnemy);
		}
	}

	template<typename T>
	void CheckMissileCollisions(T* object, Missile* theMissile)
	{


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
				
			}
		}
		
	}
	


private:

	template<typename T>
	void HandleCollisionPlayertoEnemy(Player* thePlayer, T* theEnemy)
	{
		theEnemy->setAlive(false);
	}

	CollisionMgr()
	{
	}

	~CollisionMgr();

};

#endif