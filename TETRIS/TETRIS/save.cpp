#include"save.h"
#include<iostream>
#include<fstream>
using namespace std;

extern int gameField[22][12];
extern int score;

void save() {

	int m = 1;

	ofstream fout("marker.txt");
	fout << m << " ";
		fout.close();

	ofstream matr("save.txt");

	for (int i = 1; i < 21; i++)
		for (int j = 1; j < 11; j++)
			matr << gameField[i][j] << " ";
	matr.close();

	ofstream scor("score.txt");
	scor << score;
	scor.close();

}

void loadGame() {

	ifstream matr("save.txt");
	for (int i = 1; i < 21; i++)
		for (int j = 1; j < 11; j++)
			matr >> gameField[i][j];
	matr.close();

}