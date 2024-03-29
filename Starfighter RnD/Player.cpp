#include "stdafx.h"
#include "Player.h"



Player::Player(sf::Font font1)
{
	//load the correct texture or load the debug texture if something is wrong
	if (mTexture.loadFromFile("ASSETS/Sprites/Player/Player.png")){}
	else mTexture.loadFromFile("ASSETS/Sprites/debug.png");	//if it fails load placeholder
	mSprite.setTexture(mTexture);

	setPosition(sf::Vector2f(300, 300));
	setOrigin(sf::Vector2f(mTexture.getSize().x / 2, mTexture.getSize().y / 2));
	//setRotationValue(0.05);
	setSpeed(0);
	setVelocity(sf::Vector2f(1, 1));
	setScore(0);
	setHealth(100);

	font = font1;
	setUpText();
	missiles.reserve(10);
	//sf::SoundBuffer buffer;
	// load something into the sound buffer...
	//buffer.loadFromFile("ASSETS/ship acceleration sound 2.wav");
	/*sf::Sound sound;*/
	//sound.setBuffer(buffer);

	isFiring = false;


}//end constructor


Player::~Player()
{
	//blank destructor for now
}

//sets up text for the players info
void Player::setUpText()
{
	sf::Color col = sf::Color::Green;

	scoreText.setFont(font);
	scoreText.setString("Score: ");
	scoreText.setStyle(sf::Text::Italic | sf::Text::Bold);
	scoreText.setPosition(10, 5);
	scoreText.setCharacterSize(20);
	scoreText.setColor(col);
	healthText.setFont(font);
	healthText.setString("Health: ");
	healthText.setStyle(sf::Text::Italic | sf::Text::Bold);
	healthText.setPosition(10, 25);
	healthText.setCharacterSize(20);
	healthText.setColor(col);
}

void Player::Update()
{
	Move();
	//Fire();
	//update the direction(maybe not everytime update is called)
	direction = sf::Vector2f(cos(getRotation()*(3.14/180.0)), sin(getRotation()*(3.14/180.0)));//Fucking cos and sin only take radians, problem solved
	direction /= std::sqrt((direction.x * direction.x) + (direction.y * direction.y));

	//keeping score and health text up to date
	scoreText.setString("Score: "+std::to_string(getScore()));
	healthText.setString("Health: " + std::to_string(getHealth()));

	for (int i = 0; i < missiles.size(); i++)
	{
		Missile* m = missiles.at(i);
		m->Update();
	}
}//end Update()

void Player::Fire(sf::RenderTarget& window, sf::RenderStates state)
{
	missiles.push_back(new Missile(true, direction, getPosition()));
	Missile * e = missiles.at(0);
	e->draw(window, state);
	isFiring = true;
	AudioManager::instance()->sounds.at(0).play();
}

void Player::Move()//may or may not be needed. Could possibly deal with movement in update() only
{
	//detecting keyboard input for player to accelerate foward and then decelerate back to 0
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (getSpeed() < getMaxSpeed())
		{
			speed += 0.027;//fiddle with this number to change acceleration
		}
		
	}
	else
	{
		if (speed > 0)
			speed -= 0.005;//fiddle with this number to change deceleration
		else if (speed < 0)
			speed = 0;
	}

	//For turning the ship
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Turn(-1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Turn(1);
	}
	//update the position
	setPosition(getPosition() + (getDirection() * getSpeed()));

}//end Move()

void Player::Turn(float a)
{
	rotate(a);
}//end Rotate()

void Player::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
	window.draw(scoreText);
	window.draw(healthText);
	for (int i = 0; i < missiles.size(); i++)
	{
		Missile const & m = missiles.at(i);
		m.draw(window,state);
	}
	window.draw(mSprite, getTransform());
}//end Draw()
