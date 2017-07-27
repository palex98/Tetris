#include <SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<Windows.h>
#include"figures.h"
#include"matrix.h"
#include"DrawTiles.h"
#include"about.h"
#include"highscore.h"
using namespace sf;

extern int gameField[22][12];
extern char name[100];
extern int score;
extern bool gameOver;
extern int next;

void drawTiles(RenderWindow &window) {

    bool isDrawTiles = true;

	int x, y;

	Font font;
	font.loadFromFile("Font/arial.ttf");

	Text tscore;
	tscore.setFont(font);
	tscore.setCharacterSize(50);
	tscore.setColor(sf::Color::Blue);
	tscore.setStyle(sf::Text::Bold);
	tscore.setPosition(360, 505);

	Texture Background;
	Texture Tile;
	Background.loadFromFile("Screen/background.png");
	Tile.loadFromFile("Screen/tile.png");
	Sprite background(Background);
	Sprite tile(Tile);

	Texture GameOver;
	GameOver.loadFromFile("Screen/gameover.png");
	Sprite gameover(GameOver); 
	gameover.setPosition(0, 190);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)
			{
				int Xm, Ym;
				if (event.key.code == Mouse::Left)
				{
					Vector2i FirstPos = Mouse::getPosition(window);
					Xm = FirstPos.x;
					Ym = FirstPos.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = 0;
					gameOver = false;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
			}
		}

		window.clear();

		while (isDrawTiles) {
			window.draw(background);
			for (int i = 1; i < 21; i++) {
				for (int j = 1; j < 11; j++) {
					if (gameField[i][j]) {
						tile.setPosition((j * 32) - 32, (i * 32) + 5);
						window.draw(tile);
					}
				}
			}

			tscore.setString(std::to_string(score));
			window.draw(tscore);

			switch (next) {
			case 1: {
				tile.setPosition(425, 260);
				window.draw(tile);
				tile.setPosition(393, 291);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				tile.setPosition(457, 291);
				window.draw(tile);
				break;
			}
			case 2: {
				tile.setPosition(393, 260);
				window.draw(tile);
				tile.setPosition(425, 260);
				window.draw(tile);
				tile.setPosition(393, 291);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				break;
			}
			case 3: {
				tile.setPosition(361, 291);
				window.draw(tile);
				tile.setPosition(393, 291);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				tile.setPosition(457, 291);
				window.draw(tile);
				break;
			}
			case 4: {
				tile.setPosition(457, 291);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				tile.setPosition(425, 260);
				window.draw(tile);
				tile.setPosition(393, 260);
				window.draw(tile);
				break;
			}
			case 5: {
				tile.setPosition(393, 291);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				tile.setPosition(425, 260);
				window.draw(tile);
				tile.setPosition(457, 260);
				window.draw(tile);
				break;
			}
			case 6: {
				tile.setPosition(393, 291);
				window.draw(tile);
				tile.setPosition(393, 260);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				tile.setPosition(457, 291);
				window.draw(tile);
				break;
			}
			case 7: {
				tile.setPosition(457, 260);
				window.draw(tile);
				tile.setPosition(393, 291);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				tile.setPosition(457, 291);
				window.draw(tile);
				break;
			}
			case 9: {
				tile.setPosition(393, 260);
				window.draw(tile);
				tile.setPosition(393, 291);
				window.draw(tile);
				tile.setPosition(393, 323);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				break;
			}
			case 10: {
				tile.setPosition(425, 260);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				tile.setPosition(425, 323);
				window.draw(tile);
				tile.setPosition(393, 291);
				window.draw(tile);
				break;
			}
			case 11: {
				tile.setPosition(425, 228);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				tile.setPosition(425, 260);
				window.draw(tile);
				tile.setPosition(425, 323);
				window.draw(tile);
				break;
			}
			case 12: {
				tile.setPosition(393, 323);
				window.draw(tile);
				tile.setPosition(393, 291);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				tile.setPosition(425, 260);
				window.draw(tile);
				break;
			}
			case 13: {
				tile.setPosition(425, 323);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				tile.setPosition(393, 291);
				window.draw(tile);
				tile.setPosition(393, 260);
				window.draw(tile);
				break;
			}
			case 14: {
				tile.setPosition(393, 323);
				window.draw(tile);
				tile.setPosition(425, 323);
				window.draw(tile);
				tile.setPosition(425, 291);
				window.draw(tile);
				tile.setPosition(425, 260);
				window.draw(tile);
				break;
			}
			case 15: {
				tile.setPosition(393, 260);
				window.draw(tile);
				tile.setPosition(393, 291);
				window.draw(tile);
				tile.setPosition(393, 323);
				window.draw(tile);
				tile.setPosition(425, 323);
				window.draw(tile);
				break;
			}
			default:
				break;
			}

			if (gameOver) {
				window.draw(gameover);
			}

		window.display();
		return;
		}
		
	}
}