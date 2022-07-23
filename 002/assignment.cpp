/*
 * File: assignment.cpp
 * File Created: Saturday, 23rd July 2022 5:12:02 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Saturday, 23rd July 2022 5:28:40 pm
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2022 Deep Vertic
 */

#include <SFML/Graphics.hpp>

void	UpdateShape(sf::Shape *pShape, sf::Vector2f *pVelocity)
{
	if (pShape->getGlobalBounds().top < 0 || pShape->getGlobalBounds().top + pShape->getGlobalBounds().height > 600)
	{
		pVelocity->y = -pVelocity->y;
	}
	if (pShape->getGlobalBounds().left < 0 || pShape->getGlobalBounds().left + pShape->getGlobalBounds().width > 800)
	{
		pVelocity->x = -pVelocity->x;
	}

	pShape->move(pVelocity->x, pVelocity->y);
}

int main (void)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tutorial window");
	window.setFramerateLimit(60);

	sf::RectangleShape rectangle(sf::Vector2f(200, 200));
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setPosition(150, 200);
	rectangle.setSize(sf::Vector2f(100, 100));
	sf::Vector2f rectangleVelocity = sf::Vector2f(3, 3);

	sf::CircleShape circle(80, 5);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(400, 200);
	circle.setOutlineThickness(2);
	circle.setOutlineColor(sf::Color::Blue);
	circle.setOrigin(80, 80);
	sf::Vector2f circleVelocity = rectangleVelocity;

	while (window.isOpen())
	{
		
		UpdateShape(&rectangle, &rectangleVelocity);
		UpdateShape(&circle, &circleVelocity);

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