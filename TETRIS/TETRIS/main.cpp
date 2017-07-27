#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<ctime>
#include <windows.h>
#include"matrix.h"
#include"figures.h"
#include"DrawTiles.h"
#include"GameOver.h"
#include"DeleteLine.h"
#include"save.h"
#include"about.h"
using namespace sf;

char name[100];
int score = 0;
bool gameOver = false; 
int next;

int main(){

	srand((int)time(NULL));

	int random, default_x = 2, default_y = 6;
	int marker, n = 0;

	system("title TETRIS");

RenderWindow window(VideoMode(520, 676), "TETRIS");
window.setFramerateLimit(60);

Texture Background;
Background.loadFromFile("Screen/background.png");

Texture Tile;
Tile.loadFromFile("Screen/tile.png");

Sprite background(Background);
Sprite tile(Tile);

std::ifstream fin("marker.txt");
fin >> marker;
fin.close();

std::ofstream foutg("marker.txt");
foutg << n;
foutg.close();


if (marker) {

	loadGame();

	std::ifstream scor("score.txt");
	scor >> score;
	scor.close();
}

	//next = rand() % 15 + 1;

	while (window.isOpen())
	{
		Event event;
	while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

	///////--------START-------////////
	while (!gameOver) {

		random = next;

		next = rand() % 15 + 1;

		switch (random) {
		case 1: {
			figure_1(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 2: {
			figure_2(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 3: {
			figure_3(window, default_x - 1, default_y - 1);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 4: {
			figure_4(window, default_x, default_y);
			score += 10; 
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 5: {
			figure_5(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 6: {
			figure_6(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 7: {
			figure_7(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 8: {
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 9: {
			figure_9(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 10: {
			figure_10(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 11: {
			figure_11(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 12: {
			figure_12(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 13: {
			figure_13(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 14: {
			figure_14(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		case 15: {
			figure_17(window, default_x, default_y);
			score += 10;
			checkFullLine(window);
			checkGameOver();
			break;
		}
		default:
			checkFullLine(window);
			checkGameOver();
			break;
		}
	}

	drawTiles(window);
	}

	return 0;
}