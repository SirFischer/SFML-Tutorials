/*
 * File: main.cpp
 * File Created: Wednesday, 27th April 2022 6:36:05 am
 * Author: Marek Fischer
 * -----
 * Last Modified: Saturday, 11th June 2022 12:01:28 pm
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2022 Deep Vertic
 */
#include <SFML/Graphics.hpp>

int main (void)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tutorial window");

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		window.display();
	}

	return (0);
}


/**
 * 
 * Try opening two windows at once and make it so that each window
 * can be closed individually.
 * 
 **/