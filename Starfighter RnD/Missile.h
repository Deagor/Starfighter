#pragma once
class Missile : sf::Drawable, sf::Transformable
{
public:

#pragma region Properties
	bool getIsPlayer(){ return mIsPlayer; }
	float getSpeed(){ return mSpeed; }
	sf::Vector2f getVelocity(){ return mVelocity; }

#pragma endregion
	
	Missile(bool isPlayer,sf::Vector2f direction = sf::Vector2f(1.0f,1.0f));
	~Missile();

	void draw(sf::RenderTarget& window,sf::RenderStates state) const;	//Overrides sf::drawable::draw
	void Update();

private:
	bool mIsPlayer;
	
	sf::Vector2f mVelocity;

	float mSpeed;
	float mDamage;	//Damage missile will cause on hit

	sf::Sprite mSprite;
	sf::Texture mTexture;
};

