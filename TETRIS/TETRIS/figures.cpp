#include <SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include"figures.h"
#include"DrawTiles.h"
#include"move.h"
using namespace sf;

extern int gameField[22][12];

void figure_1(RenderWindow &window, int x, int y) {

	if (y == 10) {
		gameField[x - 1][y] = gameField[x + 1][y] = 0;
		y--;
		gameField[x][y - 1] = gameField[x - 1][y] = 1;
	}
	else {
		gameField[x + 1][y] = 0;
		gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = gameField[x - 1][y] = 1;
	}
	move_1(window, x, y);

}

void figure_2(RenderWindow &window, int x, int y) {

	gameField[x][y - 1] = gameField[x][y] = gameField[x - 1][y - 1] = gameField[x - 1][y] = 1;
	move_2(window, x, y);

}

void figure_3(RenderWindow &window, int x, int y) {
	
	if (y != 1 && y != 9 && y != 10) {
		gameField[x + 1][y] = gameField[x - 1][y] = gameField[x + 2][y] = 0;
		gameField[x][y + 2] = gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = 1;
	}
	else if (y == 1) {
		gameField[x - 1][y] = gameField[x + 1][y] = gameField[x + 2][y] = 0;
		gameField[x][y + 1] = gameField[x][y + 2] = gameField[x][y + 3] = 1;
		y++;
	}
	else if (y == 9) {
		gameField[x - 1][y] = gameField[x + 1][y] = gameField[x + 2][y] = 0;
		gameField[x][y + 1] = gameField[x][y - 1] = gameField[x][y - 2] = 1;
		y--;
	}
	else if (y == 10) {
		gameField[x - 1][y] = gameField[x + 1][y] = gameField[x + 2][y] = 0;
		gameField[x][y - 1] = gameField[x][y - 2] = gameField[x][y - 3] = 1;
		y -= 2;
	}
	move_3(window, x, y);
}

void figure_4(RenderWindow &window, int x, int y) {

	if (y == 1) {
		y++;
		gameField[x - 1][y] = gameField[x + 1][y - 1] = gameField[x][y - 1] = 0;
		gameField[x][y] = gameField[x][y + 1] = gameField[x - 1][y] = gameField[x - 1][y - 1] = 1;
	}
	else {
		gameField[x - 1][y + 1] = gameField[x + 1][y] = 0;
		gameField[x][y] = gameField[x][y + 1] = gameField[x - 1][y] = gameField[x - 1][y - 1] = 1;
	}
	move_4(window, x, y);
}

void figure_5(RenderWindow &window, int x, int y) {
	
	if (y == 10) {
		y--;
		gameField[x][y + 1] = gameField[x + 1][y + 1] = 0;
		gameField[x - 1][y + 1] = gameField[x][y - 1] = 1;
	}
	else {
		gameField[x - 1][y - 1] = gameField[x + 1][y] = 0;
		gameField[x][y] = gameField[x][y - 1] = gameField[x - 1][y] = gameField[x - 1][y + 1] = 1;
	}
	move_5(window, x, y);
}

void figure_6(RenderWindow &window, int x, int y) {

	if (y == 10) {
		gameField[x - 1][y] = gameField[x + 1][y] = gameField[x + 1][y - 1] = 0;
		gameField[x][y - 1] = gameField[x][y - 2] = gameField[x - 1][y - 2] = 1;
		y--;
	}
	else {
		gameField[x + 1][y] = gameField[x + 1][y - 1] = gameField[x - 1][y] = 0;
		gameField[x][y] = gameField[x][y - 1] = gameField[x][y + 1] = gameField[x - 1][y - 1] = 1;
	}
	move_6(window, x, y);
}

void figure_7(RenderWindow &window, int x, int y) {

	if (y == 10) {
		gameField[x - 1][y - 1] = gameField[x - 1][y] = gameField[x + 1][y] = 0;
		y--;
		gameField[x][y] = gameField[x][y - 1] = gameField[x][y + 1] = gameField[x - 1][y + 1] = 1;
	}
	else {
		gameField[x - 1][y - 1] = gameField[x - 1][y] = gameField[x + 1][y] = 0;
		gameField[x][y] = gameField[x][y - 1] = gameField[x][y + 1] = gameField[x - 1][y + 1] = 1;
	}
	move_7(window, x, y);
}

void figure_8(RenderWindow &window, int x, int y) {

	if (y == 1) {
		gameField[x - 1][y] = gameField[x + 1][y] = 0;
		y++;
		gameField[x][y + 1] = gameField[x + 1][y] = 1;
	}
	else {
		gameField[x - 1][y] = 0;
		gameField[x][y - 1] = 1;
	}
	move_8(window, x, y);
}

void figure_9(RenderWindow &window, int x, int y) {

	gameField[x][y - 1] = 0;
	gameField[x + 1][y] = gameField[x][y] = gameField[x - 1][y] = gameField[x][y + 1] = 1;
	move_9(window, x, y);
}

void figure_10(RenderWindow &window, int x, int y) {

	gameField[x][y + 1] = 0;
	gameField[x - 1][y] = gameField[x][y - 1] = gameField[x + 1][y] = gameField[x][y] = 1;
	move_10(window, x, y);
}

void figure_11(RenderWindow &window, int x, int y) {

	gameField[x][y + 1] = gameField[x][y + 2] = gameField[x][y - 1] = 0;
	gameField[x + 1][y] = gameField[x - 1][y] = gameField[x + 2][y] = gameField[x][y] = 1;
	move_11(window, x, y);
}

void figure_12(RenderWindow &window, int x, int y) {

	gameField[x - 1][y - 1] = gameField[x - 1][y] = 0;
	gameField[x - 1][y + 1] = gameField[x + 1][y] = gameField[x][y] = gameField[x][y + 1] = 1;
	move_12(window, x, y);
}

void figure_13(RenderWindow &window, int x, int y) {

	gameField[x - 1][y + 1] = gameField[x - 1][y] = 0;
	gameField[x - 1][y - 1] = gameField[x + 1][y] = gameField[x][y] = gameField[x][y - 1] = 1;
	move_13(window, x, y);
}

void figure_14(RenderWindow &window, int x, int y) {

	gameField[x][y - 1] = gameField[x][y + 1] = gameField[x + 1][y + 1] = 0;
	gameField[x + 1][y] = gameField[x + 1][y - 1] = gameField[x - 1][y] = gameField[x][y] = 1;
	move_14(window, x, y);
}

void figure_15(RenderWindow &window, int x, int y) {

	if (y == 1) {
		gameField[x + 1][y] = gameField[x - 1][y] = gameField[x - 1][y + 1] = 0;
		y++;
		gameField[x][y - 1] = gameField[x][y + 1] = gameField[x + 1][y + 1] = gameField[x][y] = 1;
	}
	else {
		gameField[x - 1][y] = gameField[x - 1][y + 1] = gameField[x + 1][y] = 0;
		gameField[x][y - 1] = gameField[x][y + 1] = gameField[x + 1][y + 1] = 1;
	}
	move_15(window, x, y);
}

void figure_16(RenderWindow &window, int x, int y) {

	gameField[x][y - 1] = gameField[x][y + 1] = gameField[x - 1][y - 1] = 0;
	gameField[x + 1][y] = gameField[x - 1][y] = gameField[x - 1][y + 1] = 1;
	move_16(window, x, y);
}

void figure_17(RenderWindow &window, int x, int y) {

	gameField[x][y - 1] = gameField[x][y + 1] = gameField[x - 1][y + 1] = 0;
	gameField[x + 1][y] = gameField[x - 1][y] = gameField[x + 1][y + 1] = gameField[x][y] = 1;
	move_17(window, x, y);
}

void figure_18(RenderWindow &window, int x, int y) {

	gameField[x + 1][y - 1] = gameField[x][y - 1] = gameField[x][y + 1] = 0;
	gameField[x - 1][y] = gameField[x - 1][y - 1] = gameField[x + 1][y] = 1;
	move_18(window, x, y);
}

void figure_19(RenderWindow &window, int x, int y) {

	if (y == 1) {
		gameField[x - 1][y] = gameField[x + 1][y] = gameField[x + 1][y + 1] = 0;
		y++;
		gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = gameField[x + 1][y - 1] = 1;
	}
	else {
		gameField[x + 1][y] = gameField[x - 1][y] = gameField[x + 1][y + 1] = 0;
		gameField[x][y + 1] = gameField[x][y - 1] = gameField[x + 1][y - 1] = 1;
	}
	move_19(window, x, y);
}