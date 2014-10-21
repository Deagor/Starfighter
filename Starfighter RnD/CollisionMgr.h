#pragma once
class CollisionMgr
{
public:
	static CollisionMgr* instance();
	bool CheckCollision();

private:
	CollisionMgr();
	~CollisionMgr();
	static CollisionMgr* mInstance;

};

