#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

class EnemyFactory
{
public:

	static EnemyFactory* instance()
	{
		static EnemyFactory* mInstance = 0;
		if (mInstance == 0)
		{
			mInstance = new EnemyFactory();
		}
		return mInstance;
	}

	void SpawnCannonFodder();
	void SpawnWaveCannonFodder();
	
private:
	EnemyFactory();
	~EnemyFactory();
	static EnemyFactory* mInstance;
};

#endif