/*
 * File: main.cpp
 * File Created: Wednesday, 27th April 2022 6:36:05 am
 * Author: Marek Fischer
 * -----
 * Last Modified: Tuesday, 28th June 2022 5:59:38 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2022 Deep Vertic
 */
#include <SFML/Graphics.hpp>

int main (void)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tutorial window");
	sf::RenderWindow window2(sf::VideoMode(800, 600), "Tutorial window 2");



	while (window.isOpen() || window2.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		while (window2.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window2.close();
		}

		window.clear(sf::Color::Black);
		window2.clear(sf::Color::Green);

		window.display();
		window2.display();
	}

	return (0);
}
