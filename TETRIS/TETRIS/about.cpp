#include <SFML/Graphics.hpp>
#include"about.h"
using namespace sf;

void about() {

	RenderWindow aboutw(sf::VideoMode(400, 350), "ABOUT");

	Texture About;
	About.loadFromFile("Screen/about.png");
	Sprite about(About);

	while (aboutw.isOpen())
	{
		sf::Event event;
		while (aboutw.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				aboutw.close();
		}

		aboutw.clear();
		aboutw.draw(about);
		aboutw.display();
	}
}