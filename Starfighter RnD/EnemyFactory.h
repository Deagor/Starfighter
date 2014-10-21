#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

class EnemyFactory
{
public:
	static EnemyFactory* instance();

	void SpawnCannonFodder();
	void SpawnWaveCannonFodder();
	
private:
	EnemyFactory();
	~EnemyFactory();
	static EnemyFactory* mInstance;
};

#endif