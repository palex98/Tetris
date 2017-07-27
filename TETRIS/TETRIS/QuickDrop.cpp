#include"QuickDrop.h"
#include"bottom.h"
#include"DrawTiles.h"
#include <SFML/Graphics.hpp>
#include<Windows.h>
using namespace sf;

extern int gameField[22][12];

int quickDrop_1(RenderWindow &window, int x, int y) {

	while (!checkBottom_1(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y] = gameField[x][y - 1] = gameField[x][y + 1] = 0;
		gameField[x + 1][y - 1] = gameField[x + 1][y] = gameField[x + 1][y + 1] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_2(RenderWindow &window, int x, int y) {

	while (!checkBottom_2(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y - 1] = gameField[x - 1][y] = 0;
		gameField[x + 1][y - 1] = gameField[x + 1][y] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_3(RenderWindow &window, int x, int y) {

	while (!checkBottom_3(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x][y + 2] = gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = 0;
		gameField[x + 1][y + 2] = gameField[x + 1][y - 1] = gameField[x + 1][y] = gameField[x + 1][y + 1] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_4(RenderWindow &window, int x, int y) {

	while (!checkBottom_4(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y - 1] = gameField[x - 1][y] = gameField[x][y + 1] = 0;
		gameField[x + 1][y] = gameField[x + 1][y + 1] = gameField[x][y - 1] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_5(RenderWindow &window, int x, int y) {

	while (!checkBottom_5(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y + 1] = gameField[x - 1][y] = gameField[x][y - 1] = 0;
		gameField[x + 1][y] = gameField[x + 1][y - 1] = gameField[x][y + 1] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_6(RenderWindow &window, int x, int y) {

	while (!checkBottom_1(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y - 1] = gameField[x][y] = gameField[x][y + 1] = 0;
		gameField[x + 1][y - 1] = gameField[x + 1][y] = gameField[x + 1][y + 1] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_7(RenderWindow &window, int x, int y) {

	while (!checkBottom_1(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y + 1] = gameField[x][y] = gameField[x][y - 1] = 0;
		gameField[x + 1][y - 1] = gameField[x + 1][y] = gameField[x + 1][y + 1] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_8(RenderWindow &window, int x, int y) {

	while (!checkBottom_8(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x][y - 1] = gameField[x][y + 1] = gameField[x][y] = 0;
		gameField[x + 1][y - 1] = gameField[x + 1][y + 1] = gameField[x + 2][y] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_9(RenderWindow &window, int x, int y) {

	while (!checkBottom_9(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y] = gameField[x][y + 1] = 0;

		gameField[x + 2][y] = gameField[x + 1][y + 1] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_10(RenderWindow &window, int x, int y) {

	while (!checkBottom_10(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y] = gameField[x][y - 1] = 0;

		gameField[x + 2][y] = gameField[x + 1][y - 1] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_11(RenderWindow &window, int x, int y) {

	while (!checkBottom_11(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y] = 0;

		gameField[x + 3][y] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_12(RenderWindow &window, int x, int y) {

	while (!checkBottom_12(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y + 1] = gameField[x][y] = 0;

		gameField[x + 1][y + 1] = gameField[x + 2][y] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_13(RenderWindow &window, int x, int y) {

	while (!checkBottom_13(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y - 1] = gameField[x][y] = 0;

		gameField[x + 1][y - 1] = gameField[x + 2][y] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_14(RenderWindow &window, int x, int y) {

	while (!checkBottom_14(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x + 1][y - 1] = gameField[x - 1][y] = 0;

		gameField[x + 2][y - 1] = gameField[x + 2][y] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_15(RenderWindow &window, int x, int y) {

	while (!checkBottom_15(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = 0;

		gameField[x + 1][y - 1] = gameField[x + 1][y] = gameField[x + 2][y + 1] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_16(RenderWindow &window, int x, int y) {

	while (!checkBottom_16(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y] = gameField[x - 1][y + 1] = 0;

		gameField[x][y + 1] = gameField[x + 2][y] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_17(RenderWindow &window, int x, int y) {

	while (!checkBottom_17(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x + 1][y + 1] = gameField[x - 1][y] = 0;

		gameField[x + 2][y + 1] = gameField[x + 2][y] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_18(RenderWindow &window, int x, int y) {

	while (!checkBottom_18(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x - 1][y - 1] = gameField[x - 1][y] = 0;

		gameField[x][y - 1] = gameField[x + 2][y] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}

int quickDrop_19(RenderWindow &window, int x, int y) {

	while (!checkBottom_19(x, y) && Keyboard::isKeyPressed(Keyboard::Down)) {
		gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = 0;

		gameField[x + 2][y - 1] = gameField[x + 1][y] = gameField[x + 1][y + 1] = 1;

		x++;

		drawTiles(window);

		Sleep(10);
	}
	return x;
}