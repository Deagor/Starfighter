#ifndef BASEENEMY_H
#define BASEENEMY_H

class baseEnemy : public sf::Drawable, public sf::Transformable
{
protected:

	sf::Vector2f mVelocity;
	float mSpeed;
	bool containsPowerUP; //if the enemy drops a power up. // power up manager will determine the power that is dropped
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f startPos;
	bool alive;
	sf::Vector2f dir;
	sf::FloatRect mboundingBox;

public:

	
	void setSpeed();
	float getSpeed(){ return mSpeed; }
	sf::Sprite getSprite() { return sprite; }
	bool getAlive(){ return alive; }
	void setAlive(bool isAlive){ alive = isAlive; }
	sf::Vector2f getVelocity(){ return mVelocity; }
	virtual void setVelocity(sf::Vector2f vel){ mVelocity = vel; }
	sf::FloatRect getBoundingBox(){ return mboundingBox; }

	baseEnemy(void);
	~baseEnemy(void);

	bool getContainsPowerUp(){ return containsPowerUP; }

	virtual void setContainsPowerUp();
	virtual void Update(sf::RenderTarget& window);
	virtual void Move(sf::RenderTarget& window);

	
};

#endif