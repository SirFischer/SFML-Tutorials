/*
 * File: main.cpp
 * File Created: Wednesday, 27th April 2022 6:36:05 am
 * Author: Marek Fischer
 * -----
 * Last Modified: Tuesday, 28th June 2022 6:21:20 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2022 Deep Vertic
 */
#include <SFML/Graphics.hpp>

int main (void)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tutorial window");
	window.setFramerateLimit(60);

	sf::RectangleShape rectangle(sf::Vector2f(200, 200));
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setPosition(150, 200);
	rectangle.setSize(sf::Vector2f(100, 100));

	sf::CircleShape circle(80, 5);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(400, 200);
	circle.setOutlineThickness(2);
	circle.setOutlineColor(sf::Color::Blue);
	circle.setOrigin(80, 80);

	while (window.isOpen())
	{

		circle.rotate(0.5f);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		window.draw(rectangle);
		window.draw(circle);

		window.display();
	}

	return (0);
}

/**
 * Take both shapes, give them a speed that you will add to their position at every frame
 * and make them bounce on the sides of the window by inverting the velocity of
 * the appropriate axis.
 * Use the getPosition function for the logic.
 * The answer is in the description.
 * 
 * Good luck!
 **/