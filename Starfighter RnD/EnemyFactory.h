#pragma once
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

