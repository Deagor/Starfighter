#include <vector>

using namespace std;
class baseEnemy
{
protected:

	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;
	float mSpeed;
	bool containsPowerUP; //if the enemy drops a power up. // power up manager will determine the power that is dropped
	sf::Transform rotationMatrix; // this will be used to determine the rotation of the enemy
	sf::Texture texture;
	sf::Sprite sprite;
	
public:

	baseEnemy(void);
	~baseEnemy(void);
	void setPosition();
	void setVelocity();
	void setTexture();
	void setSprite();
	void setSpeed();
	void setRot();

	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
	float getSpeed();
	bool getContainsPowerUp();
	virtual void setContainsPowerUp();
	virtual void Update(); 
	virtual void Move();
	virtual void Draw(sf::RenderWindow  *);

	
};