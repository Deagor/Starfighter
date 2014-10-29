#ifndef COLLISIONMGR_H
#define COLLISIONMGR_H

class CollisionMgr
{
public:
	static CollisionMgr* instance();


	template<typename T>
	bool CheckCollisionPlayertoEnemy(Player* thePlayer, T* theEnemy);

	template<typename T>
	bool CheckMissileCollisions(T* object, Missile* theMissile);
	

private:
	CollisionMgr();
	~CollisionMgr();
	static CollisionMgr* mInstance;
	std::mutex locker;

};

#endif