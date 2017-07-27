#include <SFML/Graphics.hpp>
#include"pause.h"
using namespace sf;

void pause() {
	RenderWindow pause(sf::VideoMode(400, 300), "ABOUT");

	Texture Pause;
	Pause.loadFromFile("Screen/pause.png");
	Sprite spause(Pause);

	while (pause.isOpen())
	{
		sf::Event event;
		while (pause.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				pause.close();

			if (Keyboard::isKeyPressed(Keyboard::Space)) { pause.close(); }
		}

		pause.clear();
		pause.draw(spause);
		pause.display();
	}
}