#include <SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<windows.h>
#include"figures.h"
#include"matrix.h"
#include"DrawTiles.h"
#include"bottom.h"
#include"move.h"
#include"QuickDrop.h"
#include"about.h"
#include"save.h"
#include"highscore.h"
#include"pause.h"
using namespace sf;

#define DELAY 800
#define SLEEP 150

extern int gameField[22][12];
extern int score;

void move_1(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
					window.close();
				}

				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x][y] = gameField[x][y - 1] = gameField[x][y + 1] = gameField[x - 1][y] = 0;
					save();
					window.close();
				}

				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}

				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <=625) {
					pause();
				}

			}

		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_1(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_1(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_9(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_1(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_1(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_1(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_1(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_1(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y] = gameField[x][y - 1] = gameField[x][y + 1] = 0;

			gameField[x + 1][y - 1] = gameField[x + 1][y] = gameField[x + 1][y + 1] = 1;

			x++;

			drawTiles(window);

				if (checkBottom_1(x, y)) {
					for (int i = 0; i<20; i++) {
						Sleep(10);
						if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_1(window, x, y)) { y--; Sleep(SLEEP); } }
						if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_1(window, x, y)) { y++; Sleep(SLEEP); } }
					}
					if(checkBottom_1(x, y)) return;
				}

				clock.restart();
		}

	}
}

void move_2(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x][y - 1] = gameField[x][y] = gameField[x - 1][y - 1] = gameField[x - 1][y] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_2(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_2(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_2(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_2(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_2(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_2(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_2(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {
			

			gameField[x - 1][y - 1] = gameField[x - 1][y] = 0;

			gameField[x + 1][y - 1] = gameField[x + 1][y] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_2(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_2(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_2(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_2(x, y)) return;
			}

			clock.restart();
		}
	}
}

void move_3(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_11(window, x, y); return; }	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x][y + 2] = gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_3(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_3(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_11(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_3(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }
		
		if (checkBottom_3(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_3(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_3(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_3(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x][y + 2] = gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = 0;

			gameField[x + 1][y + 2] = gameField[x + 1][y - 1] = gameField[x + 1][y] = gameField[x + 1][y + 1] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_3(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_3(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_3(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_3(x, y)) return;
			}

			clock.restart();
		}
	}
}

void move_4(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x][y] = gameField[x][y + 1] = gameField[x - 1][y] = gameField[x - 1][y - 1] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_4(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_4(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_12(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_4(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_4(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_4(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_4(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_4(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y - 1] = gameField[x - 1][y] = gameField[x][y + 1] = 0;

			gameField[x + 1][y] = gameField[x + 1][y + 1] = gameField[x][y - 1] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_4(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_4(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_4(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_4(x, y)) return;
			}

			clock.restart();
		}
	}
}

void move_5(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x][y] = gameField[x][y - 1] = gameField[x - 1][y] = gameField[x - 1][y + 1] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_5(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_5(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_13(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_5(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_5(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_5(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_5(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_5(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y + 1] = gameField[x - 1][y] = gameField[x][y - 1] = 0;

			gameField[x + 1][y] = gameField[x + 1][y - 1] = gameField[x][y + 1] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_5(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_5(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_5(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_5(x, y)) return;
			}

			clock.restart();
		}
	}
}

void move_6(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x][y] = gameField[x][y - 1] = gameField[x][y + 1] = gameField[x - 1][y - 1] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_6(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_6(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_16(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_6(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_1(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_6(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_6(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_1(x, y)) return;
		}

		if (checkBottom_1(x, y)) {
			Sleep(300);
			return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y - 1] = gameField[x][y] = gameField[x][y + 1] = 0;

			gameField[x + 1][y - 1] = gameField[x + 1][y] = gameField[x + 1][y + 1] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_1(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_6(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_6(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_1(x, y)) return;
			}

			clock.restart();
		}

	}
}

void move_7(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x][y] = gameField[x][y - 1] = gameField[x][y + 1] = gameField[x - 1][y + 1] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_7(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_7(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_17(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_7(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_1(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_7(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_7(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_1(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y + 1] = gameField[x][y] = gameField[x][y - 1] = 0;

			gameField[x + 1][y - 1] = gameField[x + 1][y] = gameField[x + 1][y + 1] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_1(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_7(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_7(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_1(x, y)) return;
			}


			clock.restart();
		}

	}
}

void move_8(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = gameField[x + 1][y] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_8(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_8(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP); figure_10(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_8(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_8(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_8(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_8(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_8(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x][y - 1] = gameField[x][y + 1] = gameField[x][y] = 0;
			gameField[x + 1][y - 1] = gameField[x + 1][y + 1] = gameField[x + 2][y] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_8(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_8(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_8(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_8(x, y)) return;
			}

			clock.restart();
		}

	}
}

void move_9(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x + 1][y] = gameField[x][y] = gameField[x - 1][y] = gameField[x][y + 1] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_9(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_9(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP); figure_8(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_9(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_9(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_9(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_9(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_9(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y] = gameField[x][y + 1] = 0;

			gameField[x + 2][y] = gameField[x + 1][y + 1] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_9(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_9(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_9(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_9(x, y)) return;
			}
			clock.restart();
		}

	}
}

void move_10(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer; 

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x - 1][y] = gameField[x][y - 1] = gameField[x + 1][y] = gameField[x][y] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_10(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_10(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP); figure_1(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_10(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_10(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_10(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_10(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_10(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y] = gameField[x][y - 1] = 0;

			gameField[x + 2][y] = gameField[x + 1][y - 1] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_10(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_10(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_10(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_10(x, y)) return;
			}

			clock.restart();
		}

	}
}

void move_11(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x + 1][y] = gameField[x - 1][y] = gameField[x + 2][y] = gameField[x][y] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_11(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_11(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP); figure_3(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_11(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_11(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_11(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_11(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_11(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y] = 0;

			gameField[x + 3][y] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_11(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_11(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_11(window, x, y)) { y++; Sleep(SLEEP); } }

				}
				if (checkBottom_11(x, y)) return;
			}

			clock.restart();
		}

	}
}

void move_12(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x - 1][y + 1] = gameField[x + 1][y] = gameField[x][y] = gameField[x][y + 1] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_12(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_12(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_4(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_12(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_12(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_12(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_12(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_12(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y + 1] = gameField[x][y] = 0;

			gameField[x + 1][y + 1] = gameField[x + 2][y] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_12(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_12(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_12(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_12(x, y)) return;
			}

			clock.restart();
		}
	}
}

void move_13(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x - 1][y - 1] = gameField[x + 1][y] = gameField[x][y] = gameField[x][y - 1] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_13(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_13(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_5(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_13(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_13(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_13(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_13(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_13(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y - 1] = gameField[x][y] = 0;

			gameField[x + 1][y - 1] = gameField[x + 2][y] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_13(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_13(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_13(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_13(x, y)) return;
			}

			clock.restart();
		}
	}
}

void move_14(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x + 1][y] = gameField[x + 1][y - 1] = gameField[x - 1][y] = gameField[x][y] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_14(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_14(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_6(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_14(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_14(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_14(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_14(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_14(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x + 1][y - 1] = gameField[x - 1][y] = 0;

			gameField[x + 2][y - 1] = gameField[x + 2][y] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_14(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_14(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_14(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_14(x, y)) return;
			}

			clock.restart();
		}

	}
}

void move_15(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = gameField[x + 1][y + 1] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_15(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_15(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_14(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_15(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_15(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_15(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_15(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_15(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = 0;

			gameField[x + 1][y - 1] = gameField[x + 1][y] = gameField[x + 2][y + 1] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_15(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_15(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_15(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_15(x, y)) return;
			}

			clock.restart();
		}

	}
}

void move_16(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x + 1][y] = gameField[x - 1][y] = gameField[x - 1][y + 1] = gameField[x][y] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_16(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_16(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_15(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_16(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_16(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_16(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_16(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_16(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y] = gameField[x - 1][y + 1] = 0;

			gameField[x][y + 1] = gameField[x + 2][y] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_16(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_16(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_16(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_16(x, y)) return;
			}

			clock.restart();
		}

	}
}

void move_17(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x + 1][y] = gameField[x - 1][y] = gameField[x + 1][y + 1] = gameField[x][y] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_17(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_17(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_19(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_17(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_17(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_17(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_17(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_17(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x + 1][y + 1] = gameField[x - 1][y] = 0;

			gameField[x + 2][y + 1] = gameField[x + 2][y] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_17(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_17(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_17(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_17(x, y)) return;
			}

			clock.restart();
		}

	}
}

void move_18(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x - 1][y] = gameField[x - 1][y - 1] = gameField[x + 1][y] = gameField[x][y] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_18(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_18(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_7(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_18(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }

		if (checkBottom_18(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_18(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_18(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_18(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x - 1][y - 1] = gameField[x - 1][y] = 0;

			gameField[x][y - 1] = gameField[x + 2][y] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_18(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_18(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_18(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_18(x, y)) return;
			}

			clock.restart();
		}

	}
}

void move_19(RenderWindow &window, int x, int y) {

	drawTiles(window);

	Clock clock;
	Time timer;

	while (window.isOpen()) {
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
					Vector2i Mouse = Mouse::getPosition(window);
					Xm = Mouse.x;
					Ym = Mouse.y;
				}
				if (Xm <= 165 && Ym <= 33) {
					newGame();
					score = -10;
					return;
				}
				if (Xm >= 400 && Xm <= 500 && Ym <= 33) {
					about();
				}
				if (Xm >= 350 && Xm <= 505 && Ym >= 635 && Ym <= 670) {
					gameField[x][y + 1] = gameField[x][y - 1] = gameField[x + 1][y - 1] = gameField[x][y] = 0;
					save();
					window.close();
				}
				if (Xm >= 166 && Xm <= 399 && Ym <= 33) {
					highscore();
				}
				if (Xm >= 380 && Xm <= 470 && Ym >= 595 && Ym <= 625) {
					pause();
				}
			}
		}

		timer = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_19(window, x, y)) { y--; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_19(window, x, y)) { y++; Sleep(SLEEP); } }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { Sleep(SLEEP);  figure_18(window, x, y); return; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { x=quickDrop_19(window, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::P)) { pause(); }
		

		if (checkBottom_19(x, y)) {
			for (int i = 0; i<20; i++) {
				Sleep(10);
				if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_19(window, x, y)) { y--; Sleep(SLEEP); } }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_19(window, x, y)) { y++; Sleep(SLEEP); } }
			}
			if (checkBottom_19(x, y)) return;
		}

		if (timer.asMilliseconds() >= DELAY) {

			gameField[x][y - 1] = gameField[x][y] = gameField[x][y + 1] = 0;

			gameField[x + 2][y - 1] = gameField[x + 1][y] = gameField[x + 1][y + 1] = 1;

			x++;

			drawTiles(window);

			if (checkBottom_19(x, y)) {
				for (int i = 0; i<20; i++) {
					Sleep(10);
					if (Keyboard::isKeyPressed(Keyboard::Left)) { if (moveToLeft_19(window, x, y)) { y--; Sleep(SLEEP); } }
					if (Keyboard::isKeyPressed(Keyboard::Right)) { if (moveToRight_19(window, x, y)) { y++; Sleep(SLEEP); } }
				}
				if (checkBottom_19(x, y)) return;
			}

			clock.restart();
		}

	}
}

//********************************************************************************//


bool moveToLeft_1(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 2] && !gameField[x - 1][y - 1]) {
		gameField[x][y + 1] = gameField[x - 1][y] = 0;
		gameField[x][y - 2] = gameField[x - 1][y - 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_1(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 2] && !gameField[x - 1][y + 1]) {
		gameField[x][y - 1] = gameField[x - 1][y] = 0;
		gameField[x][y + 2] = gameField[x - 1][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_2(RenderWindow &window, int x, int y) {

	if (!gameField[x - 1][y - 2] && !gameField[x][x - 2]) {
		gameField[x][y] = gameField[x - 1][y] = 0;
		gameField[x][y - 2] = gameField[x - 1][y - 2] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_2(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 1] && !gameField[x - 1][y + 1]) {
		gameField[x][y - 1] = gameField[x - 1][y - 1] = 0;
		gameField[x][y + 1] = gameField[x - 1][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_3(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 2]) {
		gameField[x][y + 2] = 0;
		gameField[x][y - 2] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_3(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 3]) {
		gameField[x][y - 1] = 0;
		gameField[x][y + 3] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_4(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 1] && !gameField[x - 1][y - 2]) {
		gameField[x][y + 1] = gameField[x - 1][y] = 0;
		gameField[x][y - 1] = gameField[x - 1][y - 2] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_4(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 2] && !gameField[x - 1][y + 1]) {
		gameField[x][y] = gameField[x - 1][y - 1] = 0;
		gameField[x - 1][y + 1] = gameField[x][y + 2] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_5(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 2] && !gameField[x - 1][y - 1]) {
		gameField[x - 1][y + 1] = gameField[x][y] = 0;
		gameField[x][y - 2] = gameField[x - 1][y - 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_5(RenderWindow &window, int x, int y) {

	if (!gameField[x - 1][y + 2] && !gameField[x][y + 1]) {
		gameField[x][y - 1] = gameField[x - 1][y] = 0;
		gameField[x - 1][y + 2] = gameField[x][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_6(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 2] && !gameField[x - 1][y - 2]) {
		gameField[x - 1][y - 1] = gameField[x][y + 1] = 0;
		gameField[x][y - 2] = gameField[x - 1][y - 2] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_6(RenderWindow &window, int x, int y) {

	if (!gameField[x - 1][y] && !gameField[x][y + 2]) {
		gameField[x - 1][y - 1] = gameField[x][y - 1] = 0;
		gameField[x - 1][y] = gameField[x][y + 2] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_7(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 2] && !gameField[x - 1][y]) {
		gameField[x][y + 1] = gameField[x - 1][y + 1] = 0;
		gameField[x][y - 2] = gameField[x - 1][y] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_7(RenderWindow &window, int x, int y) {

	if (!gameField[x - 1][y + 2] && !gameField[x][y + 2]) {
		gameField[x][y - 1] = gameField[x - 1][y + 1] = 0;
		gameField[x - 1][y + 2] = gameField[x][y + 2] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_8(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 2] && !gameField[x + 1][y - 1]) {
		gameField[x][y + 1] = gameField[x + 1][y] = 0;
		gameField[x][y - 2] = gameField[x + 1][y - 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_8(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 2] && !gameField[x + 1][y + 1]) {
		gameField[x][y - 1] = gameField[x + 1][y] = 0;
		gameField[x][y + 2] = gameField[x + 1][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_9(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 1] && !gameField[x - 1][y - 1] && !gameField[x + 1][y - 1]) {
		gameField[x][y + 1] = gameField[x - 1][y] = gameField[x + 1][y] = 0;
		gameField[x][y - 1] = gameField[x - 1][y - 1] = gameField[x + 1][y - 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_9(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 2] && !gameField[x - 1][y + 1] && !gameField[x + 1][y + 1]) {
		gameField[x][y] = gameField[x - 1][y] = gameField[x + 1][y] = 0;
		gameField[x][y + 2] = gameField[x - 1][y + 1] = gameField[x + 1][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_10(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 2] && !gameField[x - 1][y - 1] && !gameField[x + 1][y - 1]) {
		gameField[x][y] = gameField[x - 1][y] = gameField[x + 1][y] = 0;
		gameField[x][y - 2] = gameField[x - 1][y - 1] = gameField[x + 1][y - 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_10(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 1] && !gameField[x - 1][y + 1] && !gameField[x + 1][y + 1]) {
		gameField[x][y - 1] = gameField[x - 1][y] = gameField[x + 1][y] = 0;
		gameField[x][y + 1] = gameField[x - 1][y + 1] = gameField[x + 1][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_11(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 1] && !gameField[x - 1][y - 1] && !gameField[x + 2][y - 1] && !gameField[x + 1][y - 1]) {
		gameField[x][y] = gameField[x - 1][y] = gameField[x + 2][y] = gameField[x + 1][y] = 0;
		gameField[x][y - 1] = gameField[x - 1][y - 1] = gameField[x + 2][y - 1] = gameField[x + 1][y - 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_11(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 1] && !gameField[x - 1][y + 1] && !gameField[x + 2][y + 1] && !gameField[x + 1][y + 1]) {
		gameField[x][y] = gameField[x - 1][y] = gameField[x + 2][y] = gameField[x + 1][y] = 0;
		gameField[x][y + 1] = gameField[x - 1][y + 1] = gameField[x + 2][y + 1] = gameField[x + 1][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_12(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 1] && !gameField[x + 1][y - 1] && !gameField[x - 1][y]) {
		gameField[x - 1][y + 1] = gameField[x][y + 1] = gameField[x + 1][y] = 0;
		gameField[x][y - 1] = gameField[x + 1][y - 1] = gameField[x - 1][y] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_12(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 2] && !gameField[x - 1][y + 2] && !gameField[x + 1][y + 1]) {
		gameField[x][y] = gameField[x + 1][y] = gameField[x - 1][y + 1] = 0;
		gameField[x][y + 2] = gameField[x - 1][y + 2] = gameField[x + 1][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_13(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 2] && !gameField[x - 1][y - 2] && !gameField[x + 1][y - 1]) {
		gameField[x - 1][y - 1] = gameField[x][y] = gameField[x + 1][y] = 0;
		gameField[x][y - 2] = gameField[x - 1][y - 2] = gameField[x + 1][y - 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_13(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 1] && !gameField[x + 1][y + 1] && !gameField[x - 1][y]) {
		gameField[x - 1][y - 1] = gameField[x][y - 1] = gameField[x + 1][y] = 0;
		gameField[x][y + 1] = gameField[x + 1][y + 1] = gameField[x - 1][y] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_14(RenderWindow &window, int x, int y) {

	if (!gameField[x + 1][y - 2] && !gameField[x][y - 1] && !gameField[x - 1][y - 1]) {
		gameField[x][y] = gameField[x + 1][y] = gameField[x - 1][y] = 0;
		gameField[x + 1][y - 2] = gameField[x][y - 1] = gameField[x - 1][y - 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_14(RenderWindow &window, int x, int y) {

	if (!gameField[x - 1][y + 1] && !gameField[x + 1][y + 1] && !gameField[x][y + 1]) {
		gameField[x + 1][y - 1] = gameField[x - 1][y] = gameField[x][y] = 0;
		gameField[x - 1][y + 1] = gameField[x + 1][y + 1] = gameField[x][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_15(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 2] && !gameField[x + 1][y]) {
		gameField[x][y + 1] = gameField[x + 1][y + 1] = 0;
		gameField[x][y - 2] = gameField[x + 1][y] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_15(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 2] && !gameField[x + 1][y + 2]) {
		gameField[x][y - 1] = gameField[x + 1][y + 1] = 0;
		gameField[x][y + 2] = gameField[x + 1][y + 2] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_16(RenderWindow &window, int x, int y) {

	if (!gameField[x - 1][y - 1] && !gameField[x][y - 1] && !gameField[x + 1][y - 1]) {
		gameField[x - 1][y + 1] = gameField[x][y] = gameField[x + 1][y] = 0;
		gameField[x - 1][y - 1] = gameField[x][y - 1] = gameField[x + 1][y - 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_16(RenderWindow &window, int x, int y) {

	if (!gameField[x - 1][y + 2] && !gameField[x][y + 1] && !gameField[x + 1][y + 1]) {
		gameField[x - 1][y] = gameField[x][y] = gameField[x + 1][y] = 0;
		gameField[x - 1][y + 2] = gameField[x][y + 1] = gameField[x + 1][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_17(RenderWindow &window, int x, int y) {

	if (!gameField[x - 1][y - 1] && !gameField[x][y - 1] && !gameField[x + 1][y - 1]) {
		gameField[x - 1][y] = gameField[x][y] = gameField[x + 1][y + 1] = 0;
		gameField[x - 1][y - 1] = gameField[x][y - 1] = gameField[x + 1][y - 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_17(RenderWindow &window, int x, int y) {

	if (!gameField[x + 1][y + 2] && !gameField[x][y + 1] && !gameField[x - 1][y + 1]) {
		gameField[x - 1][y] = gameField[x][y] = gameField[x + 1][y] = 0;
		gameField[x + 1][y + 2] = gameField[x][y + 1] = gameField[x - 1][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_18(RenderWindow &window, int x, int y) {

	if (!gameField[x - 1][y - 2] && !gameField[x][y - 1] && !gameField[x + 1][y - 1]) {
		gameField[x - 1][y] = gameField[x][y] = gameField[x + 1][y] = 0;
		gameField[x - 1][y - 2] = gameField[x][y - 1] = gameField[x + 1][y - 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_18(RenderWindow &window, int x, int y) {

	if (!gameField[x + 1][y + 1] && !gameField[x][y + 1] && !gameField[x - 1][y + 1]) {
		gameField[x - 1][y - 1] = gameField[x][y] = gameField[x + 1][y] = 0;
		gameField[x + 1][y + 1] = gameField[x][y + 1] = gameField[x - 1][y + 1] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToLeft_19(RenderWindow &window, int x, int y) {

	if (!gameField[x][y - 2] && !gameField[x + 1][y - 2]) {
		gameField[x][y + 1] = gameField[x + 1][y - 1] = 0;
		gameField[x][y - 2] = gameField[x + 1][y - 2] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}

bool moveToRight_19(RenderWindow &window, int x, int y) {

	if (!gameField[x][y + 2] && !gameField[x + 1][y]) {
		gameField[x][y - 1] = gameField[x + 1][y - 1] = 0;
		gameField[x][y + 2] = gameField[x + 1][y] = 1;
		drawTiles(window);
		return true;
	}
	else return false;
}