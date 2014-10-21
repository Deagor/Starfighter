#ifndef PLAYER_H
#define PLAYER_H

class Player : sf::Drawable, sf::Transformable
{
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	float rotationValue;
	int health;
	sf::Sprite mSprite;
	sf::Texture mTexture;
	float speed;
	const float maxSpeed = 5;
public:
	Player();
	~Player();
	void Update();
	void Move();
	void Turn();
	void draw(sf::RenderTarget& window, sf::RenderStates state) const;

#pragma region Properties
	//start gets
	//sf::Vector2f getPosition(){ return position; }
	sf::Vector2f getVelocity(){ return velocity; }
	float getRotationValue(){ return rotationValue; }
	int getHealth(){ return health; }
	float getSpeed(){ return speed; }
	float getMaxSpeed(){ return maxSpeed; }
	//end gets

	//start sets
	//void setPosition(sf::Vector2f pos){ position = pos; }
	void setVelocity(sf::Vector2f vel){ velocity = vel; }
	void setRotationValue(float rot){ rotationValue = rot; }
	void setHealth(int h){ health = h; }
	void setSpeed(float s){ speed = s; }
	//end sets
#pragma endregion

};

#endif