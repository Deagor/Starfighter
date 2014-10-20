#pragma once
class Missile
{
public:
	Missile(bool isPlayer);
	~Missile();

	void Update();

private:
	bool mIsPlayer;

	sf::Vector2f mVelocity;
	sf::Vector2f mPosition;
	
	float mSpeed;
	float mDamage;	//Damage missile will cause on hit

	sf::Sprite mSprite;
	sf::Texture mTexture;
};

