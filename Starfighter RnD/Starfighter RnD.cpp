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
	const int maxNumThreads = std::thread::hardware_concurrency();	//gets the max number of threads the users computer can handle

	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\JingJing.TTF");
	

	sf::RenderWindow window(sf::VideoMode(800,600,32),"Project");
	sf::RenderWindow *pWindow = &window;
	//Menu menu(window.getSize().x, window.getSize().y);//creates the menu

	window.setFramerateLimit(120);
	sf::RenderStates state;
	// if you want the enemies to come down from the top make sure the Y is less then 0  and the x is within the window
	// if you want the enemy to come in from left the x has to be greater then window width or less then zero and the y has to be within the window.
	Cannonfodder e1(sf::Vector2f(775, -1),*pWindow);//testers
	Cannonfodder e2(sf::Vector2f(-50, 10),*pWindow);//testers
	Cannonfodder e3(sf::Vector2f(window.getSize().x +50, 10), *pWindow);//testers

	Player p(font);
	


	
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
			//switch (Event.type)
			//{
			//case sf::Event::KeyReleased:
			//	switch (Event.key.code)
			//	{
			//	case sf::Keyboard::Up:
			//		menu.MoveUp();
			//		break;

			//	case sf::Keyboard::Down:
			//		menu.MoveDown();
			//		break;

			//	case sf::Keyboard::Return:
			//		switch (menu.GetPressedItem())
			//		{
			//		case 0:
			//			break;
			//		case 1:
			//			break;
			//		case 2:
			//			window.close();
			//			break;
			//		}

			//	}
			//}
		}
		//prepare frame
		window.clear(sf::Color::Black);
		
		p.Update();
		e1.Update(*pWindow);
		e2.Update(*pWindow);
<<<<<<< HEAD
		e3.Update(*pWindow);
		//menu.draw(window); // Draws the menu
=======
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (p.getIsFiring() == false)
			{
				p.Fire();
			}
		}
		else p.setIsFiring(false);
>>>>>>> 64285807541ba366627d9af7d30d5ab802f16049
		// draw frame items here

		p.draw(*pWindow, state);
		e1.draw(*pWindow,state);
		e2.draw(*pWindow, state);
		e3.draw(*pWindow, state);
		// finally, display rendered frame on screen
		window.display();

	}
	return EXIT_SUCCESS;
}

