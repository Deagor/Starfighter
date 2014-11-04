// Starfighter RnD.cpp : Defines the entry point for the console application.
//
////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

//SFML
#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")


int main()
{

	srand(time(NULL));
	const int MENU = 0, PLAYGAME = 1, OPTIONS = 2, EXIT = 3;
	int gamestate = 0;
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\JingJing.TTF");


	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Project");
	sf::RenderWindow *pWindow = &window;
	Menu menu(window.getSize().x, window.getSize().y);//creates the menu

	window.setFramerateLimit(120);
	sf::RenderStates state;

	// if you want the enemies to come down from the top make sure the Y is less then 0  and the x is within the window
	// if you want the enemy to come in from left the x has to be greater then window width or less then zero and the y has to be within the window.
	Cannonfodder e1(sf::Vector2f(775, -1), *pWindow);//testers

	std::vector<Cannonfodder> enemies;
	enemies.push_back(e1);

	Player p(font);
	AudioManager::instance()->LoadSounds();
	while (window.isOpen())
	{
		// Process events
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Close window :: Exit
			if (Event.type == sf::Event::Closed)
				window.close();
			// Escape key :
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();


			switch (Event.type)
			{
			case sf::Event::KeyReleased:
				switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem() && gamestate == 0)
					{
					case 0:
						gamestate = 1;
						break;
					case 1:
						gamestate = 2;
						break;
					case 2:
						window.close();
						break;
					}

				}
			}
		}
		if (gamestate == 0)
		{
			window.clear(sf::Color::Black);
			menu.draw(window); // Draws the menu
		}
		if (gamestate == 1)
		{
			//Keyboard checks
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (p.getIsFiring() == false)
				{
					p.Fire();
					/*AudioManager::instance()->sounds.at(0).play();*/
				}
			}
			else { p.setIsFiring(false); }

			//prepare frame
			window.clear(sf::Color::Magenta);

			p.Update();
			enemies.at(0).Update(*pWindow);
			//menu.draw(window); // Draws the menu






			//Misc (collision checks and such)
			for each (Cannonfodder e in enemies)
			{
				CollisionMgr::instance()->CheckCollisionPlayertoEnemy(&p, &e);
			}


			//Draws
			p.draw(*pWindow, state);
			enemies.at(0).draw(*pWindow, state);
			// finally, display rendered frame on screen

		}

		window.display();

	}
	return EXIT_SUCCESS;
}

