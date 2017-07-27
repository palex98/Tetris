#include"highscore.h"
#include <SFML/Graphics.hpp>
#include<fstream>
using namespace sf;

void highscore() {

	int hs;

	RenderWindow hscore(sf::VideoMode(300, 200), "HIGHSCORE");

	Texture Highscore;
	Highscore.loadFromFile("Screen/highscore.png");
	Sprite highscore(Highscore);

	Font font;
	font.loadFromFile("Font/arial.ttf");

	std::ifstream fin("highscore.txt");
	fin >> hs;
	fin.close();

	Text score;
	score.setFont(font);
	score.setCharacterSize(50);
	score.setColor(sf::Color::Blue);
	score.setStyle(sf::Text::Bold);
	score.setPosition(55, 75);
	score.setString(std::to_string(hs));
	hscore.draw(score);

	while (hscore.isOpen())
	{
		sf::Event event;
		while (hscore.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				hscore.close();
		}

		hscore.clear();
		hscore.draw(highscore);
		hscore.draw(score);
		hscore.display();
	}
}