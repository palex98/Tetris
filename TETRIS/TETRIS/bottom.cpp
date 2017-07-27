#include <SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include"figures.h"
#include"matrix.h"
#include"DrawTiles.h"
#include"bottom.h"
using namespace sf;

extern int gameField[22][12];

bool checkBottom_1(int x, int y) {

	if (gameField[x + 1][y - 1] || gameField[x + 1][y] || gameField[x + 1][y + 1]) return true;
	else return false;

}

bool checkBottom_2(int x, int y) {

	if (gameField[x + 1][y - 1] || gameField[x + 1][y]) return true;
	else return false;
}

bool checkBottom_3(int x, int y) {

	if (gameField[x + 1][y + 2] || gameField[x + 1][y - 1] || gameField[x + 1][y] || gameField[x + 1][y + 1]) return true;
	else return false;
}

bool checkBottom_4(int x, int y) {

	if (gameField[x][y - 1] || gameField[x + 1][y] || gameField[x + 1][y + 1]) return true;
	else return false;
}

bool checkBottom_5(int x, int y) {

	if (gameField[x][y + 1] || gameField[x + 1][y] || gameField[x + 1][y - 1]) return true;
	else return false;
}

bool checkBottom_8(int x, int y) {

	if (gameField[x + 2][y] || gameField[x + 1][y + 1] || gameField[x + 1][y - 1]) return true;
	else return false;
}

bool checkBottom_9(int x, int y) {

	if (gameField[x + 2][y] || gameField[x + 1][y + 1]) return true;
	else return false;
}

bool checkBottom_10(int x, int y) {

	if (gameField[x + 2][y] || gameField[x + 1][y - 1]) return true;
	else return false;
}

bool checkBottom_11(int x, int y) {

	if (gameField[x + 3][y]) return true;
	else return false;
}

bool checkBottom_12(int x, int y) {

	if (gameField[x + 2][y] || gameField[x + 1][y + 1]) return true;
	else return false;
}

bool checkBottom_13(int x, int y) {

	if (gameField[x + 2][y] || gameField[x + 1][y - 1]) return true;
	else return false;
}

bool checkBottom_14(int x, int y) {

	if (gameField[x + 2][y - 1] || gameField[x + 2][y]) return true;
	else return false;
}

bool checkBottom_15(int x, int y) {

	if (gameField[x + 1][y - 1] || gameField[x + 1][y] || gameField[x + 2][y + 1]) return true;
	else return false;
}

bool checkBottom_16(int x, int y) {

	if (gameField[x + 2][y] || gameField[x][y + 1]) return true;
	else return false;
}

bool checkBottom_17(int x, int y) {

	if (gameField[x + 2][y] || gameField[x + 2][y + 1]) return true;
	else return false;
}

bool checkBottom_18(int x, int y) {

	if (gameField[x + 2][y] || gameField[x][y - 1]) return true;
	else return false;
}

bool checkBottom_19(int x, int y) {

	if (gameField[x + 2][y - 1] || gameField[x + 1][y] || gameField[x + 1][y + 1]) return true;
	else return false;
}