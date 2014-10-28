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
	window.setFramerateLimit(120);
	sf::RenderStates state;
	Cannonfodder e1(sf::Vector2f(250, -100));//testers
	Cannonfodder e2(sf::Vector2f(-50, 10));//testers

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
		}
		//prepare frame
		window.clear(sf::Color::Black);
		p.Update();
		e1.Update(*pWindow);
		e2.Update(*pWindow);
		// draw frame items here

		p.draw(*pWindow, state);
		e1.draw(*pWindow,state);
		e2.draw(*pWindow, state);

		// finally, display rendered frame on screen
		window.display();

	}
	return EXIT_SUCCESS;
}

