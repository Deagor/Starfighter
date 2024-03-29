#ifndef PLAYER_H
#define PLAYER_H

#include "Missile.h"

class Player : public sf::Drawable, public sf::Transformable
{
private:
	//sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Sprite mSprite;
	sf::Texture mTexture;
	float speed;
	const float maxSpeed = 1.5f;
	sf::Vector2f direction;
	float health;
	float score;

	sf::Text scoreText;
	sf::Text healthText;
	sf::Font font;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	std::vector<Missile *> missiles;
	bool isFiring;

public:
	Player(sf::Font font1);
	~Player();
	void setUpText();
	void Update();
	void Move();
	void Turn(float a);
	void Fire(sf::RenderTarget& window, sf::RenderStates state);
	void draw(sf::RenderTarget& window, sf::RenderStates state) const;

#pragma region Properties
	//start gets
	sf::Vector2f getVelocity(){ return velocity; }
	sf::Sprite getSprite(){ return mSprite; }
	float getSpeed(){ return speed; }
	float getMaxSpeed(){ return maxSpeed; }
	sf::Vector2f getDirection(){ return direction; }
	float getScore(){ return score; }
	float getHealth(){ return health; }
	bool getIsFiring(){ return isFiring; }
	//end gets

	//start sets
	void setVelocity(sf::Vector2f vel){ velocity = vel; }
	void setSpeed(float s){ speed = s; }
	void setScore(float s){ score = s; }
	void setHealth(float h){ health = h; }
	void setIsFiring(bool f){ isFiring = f; }
	//end sets
#pragma endregion

};

#endif