

#pragma once
#include <windows.h>
#include <thread>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int COOPWIDTH = 70;
const int COOPHEIGHT = 25;

char CoopField[COOPHEIGHT][COOPWIDTH];

int Snake2Len = 3;

const int WIDTH = 20;
const int HEIGHT = 20;
const int MAX_LENTH = (WIDTH - 2) * (HEIGHT - 2);

char Field[HEIGHT][WIDTH];

char head = '@';
char tail = 'O';
char tail2 = 'o';
char wall = '#';
char Food = 'F';
char Bonus = 'B';

int Chance;

int snakeX[MAX_LENTH / 2];
int snakeY[MAX_LENTH / 2];
int snake2X[MAX_LENTH / 2];
int snake2Y[MAX_LENTH / 2];
int SnakeLen = 3;

int score;
int scoreRatio = 50;

int FoodX, FoodY;
int BonusX, BonusY;

bool GameOver = false;
bool programWork = true;

enum SnakeDir { UP, DOWN, LEFT, RIGHT };
SnakeDir Dir;

void gotoxy(short x, short y) {
	SetConsoleCursorPosition(hConsole, { x ,y });
}
void CursorVisible(bool show) {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hConsole, &structCursorInfo);
	structCursorInfo.bVisible = show;
	SetConsoleCursorInfo(hConsole, &structCursorInfo);
}

void CreateField() {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (y == HEIGHT - 1 || y == 0 || x == WIDTH - 1 || x == 0)
				Field[y][x] = wall;
			else
				Field[y][x] = ' ';
		}
	}
}

void PrintField() {
	gotoxy(0, 0);
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			cout << Field[y][x];
		}
		cout << endl;
	}
	if (GameOver) {
		gotoxy(5, HEIGHT / 2);
		cout << "GAME OVER";
	}
	if (Field[FoodY][FoodX] != Food) {
		Field[FoodY][FoodX] = Food;
	}
	gotoxy(0, HEIGHT);
	cout << "lenth: " << SnakeLen << endl;
	cout << "score: " << score;
	gotoxy(0, 0);
	cout << "#";
	gotoxy(0, HEIGHT + 1);
}

void controls() {
	if (GetKeyState('W') & 0x1000) {
		if (Dir != DOWN)
			Dir = UP;
	}
	if (GetKeyState('S') & 0x1000) {
		if (Dir != UP)
			Dir = DOWN;
	}
	if (GetKeyState('A') & 0x1000) {
		if (Dir != RIGHT)
			Dir = LEFT;
	}
	if (GetKeyState('D') & 0x1000) {
		if (Dir != LEFT)
			Dir = RIGHT;
	}
}
