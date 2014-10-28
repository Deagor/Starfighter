#ifndef CANNONFODDER_H
#define CANNONFODDER_H

#include "stdafx.h"

class Cannonfodder : public baseEnemy
{
private:
	int stage; //if it's in it second stage it will fire
	float offset;
	
public:
	Cannonfodder(sf::Vector2f);
	~Cannonfodder(void);
	void setStartVelocity();
	void Move(sf::RenderTarget& window);
	void Update(sf::RenderTarget& window);
	void Fire();
	void draw(sf::RenderTarget& window, sf::RenderStates state) const;

};
#endif