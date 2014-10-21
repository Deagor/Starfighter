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

bool CollisionMgr::CheckCollisionPlayertoMissile(Player thePlayer,Missile theMissile)
{
	return false;
}