#include "stdafx.h"
#include "EnemyFactory.h"

EnemyFactory* EnemyFactory::mInstance = 0;

//private constructor
EnemyFactory::EnemyFactory()
{
}

EnemyFactory* EnemyFactory::instance()
{
	if (mInstance == 0)
	{
		mInstance = new EnemyFactory();
	}
	return mInstance;
}

EnemyFactory::~EnemyFactory()
{
}

void EnemyFactory::SpawnCannonFodder()
{

}

void EnemyFactory::SpawnWaveCannonFodder()
{
}