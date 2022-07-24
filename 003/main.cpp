/*
 * File: main.cpp
 * File Created: Wednesday, 27th April 2022 6:36:05 am
 * Author: Marek Fischer
 * -----
 * Last Modified: Sunday, 24th July 2022 2:15:25 pm
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2022 Deep Vertic
 */
#include <SFML/Graphics.hpp>
#include <iostream>

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

	bool makeSpin = false;

	while (window.isOpen())
	{

		circle.rotate(0.5f);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::Resized)
			{
				std::cout << "Window width: " << event.size.width << std::endl;
				std::cout << "Window height: " << event.size.height << std::endl;
			}

			if (event.type == sf::Event::LostFocus)
				std::cout << "Bye!" << std::endl;
			if (event.type == sf::Event::GainedFocus)
				std::cout << "Hello!" << std::endl;

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
					makeSpin = true;
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
					makeSpin = false;
			}

			if (event.type == sf::Event::MouseMoved)
			{
				std::cout << "mosue pos: " << event.mouseMove.x << " " << event.mouseMove.y << std::endl;
			}
		}

		if (makeSpin)
			rectangle.rotate(5.0);

		window.clear(sf::Color::Black);

		window.draw(rectangle);
		window.draw(circle);

		window.display();
	}

	return (0);
}

/**
 * 
 * Pick up the code from the last assignment where the figures bounce.
 * Increase the speed by which the figures move when pressing the
 * up arrow key and decrease the speed when pressing the down key.
 * Remember to clamp the values to zero to avoid negative speeds.
 * Good luck! 
 * Bonus: Make the square figure move up,
 * down, left and right when you press W, S, A or D.
 *
 **/