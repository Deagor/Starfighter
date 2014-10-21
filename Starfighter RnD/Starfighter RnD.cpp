// Starfighter RnD.cpp : Defines the entry point for the console application.
//
////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

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

#include <iostream>
#include "baseEnemy.h"
#include "Missile.h"
#include "Player.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(800,600,32),"Project");
	sf::RenderWindow *pWindow = &window;

	sf::RenderStates state;
	Missile mistest(true);
	Player p;
	
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
		window.clear();
		mistest.Update();
		// draw frame items here
		mistest.draw(*pWindow,state);
		p.Update();
		p.draw(*pWindow, state);

		// finally, display rendered frame on screen
		window.display();

	}
	return EXIT_SUCCESS;
}

