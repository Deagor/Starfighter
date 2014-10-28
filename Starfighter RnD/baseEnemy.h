#ifndef BASEENEMY_H
#define BASEENEMY_H

using namespace std;
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
	
public:

	baseEnemy(void);
	~baseEnemy(void);
	virtual void setVelocity(sf::Vector2f);
	void setTexture();
	void setSprite();
	void setSpeed();

	sf::Sprite getSprite();
	sf::Vector2f getVelocity();
	float getSpeed();
	bool getContainsPowerUp();
	virtual void setContainsPowerUp();
	virtual void Update(sf::RenderTarget& window);
	virtual void Move(sf::RenderTarget& window);

	
};

#endif