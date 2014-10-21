#ifndef COLLISIONMGR_H
#define COLLISIONMGR_H

class CollisionMgr
{
public:
	static CollisionMgr* instance();

	bool CheckCollisionPlayertoMissile(Player thePlayer,Missile theMissile);

private:
	CollisionMgr();
	~CollisionMgr();
	static CollisionMgr* mInstance;

};

#endif