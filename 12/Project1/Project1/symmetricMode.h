

#pragma once

#include <iostream>
#include <Windows.h>
#include <thread>
#include <ctime>
#include "globals.h"

using namespace std;

void Logic2() {
	srand(time(NULL));

	if (snakeY[0] == HEIGHT - 1 || snakeY[0] == 0 || snakeX[0] == WIDTH - 1 || snakeX[0] == 0)
		GameOver = true;

	for (int i = 0; i <= SnakeLen; i++) {
		if (snakeX[0] == snake2X[i] && snakeY[0] == snake2Y[i]) {
			GameOver = true;
		}
	}

	for (int i = 1; i <= SnakeLen; i++) {
		if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
			GameOver = true;
		}
	}

	if ((snakeX[0] == FoodX && snakeY[0] == FoodY)||(snake2X[0]==FoodX&&snake2Y[0]==FoodY)) {
		SnakeLen++;
		for (int i = 0; i <= SnakeLen; i++) {
			if ((FoodX == snakeX[i] && FoodY == snakeY[i]) || (FoodX == snake2X[i] && FoodY == snake2Y[i])) {
				FoodY = rand() % (HEIGHT - 3) + 2;
				FoodX = rand() % (WIDTH - 3) + 2;
				Field[FoodY][FoodX] = Food;
				PrintField();
			}
			else
				break;
		}
	}

	score = (SnakeLen - 3) * 10;
}


void move2() {
	Dir = DOWN;
	snakeX[0] = 1;
	snakeY[0] = 1;

	snake2X[0] = (WIDTH - 2);
	snake2Y[0] = (HEIGHT - 2);

	FoodX = rand() % (WIDTH - 3) + 2;
	FoodY = rand() % (HEIGHT - 3) + 2;
	Field[FoodY][FoodX] = Food;

	while (!GameOver) {
		controls();

		for (int i = SnakeLen - 2; i >= 0; i--) {
			snakeX[i + 1] = snakeX[i];
			snakeY[i + 1] = snakeY[i];
		}
		for (int i = SnakeLen - 2; i >= 0; i--) {
			snake2X[i + 1] = snake2X[i];
			snake2Y[i + 1] = snake2Y[i];
		}

		if (Dir == UP)
			snakeY[0]--;
		if (Dir == DOWN)
			snakeY[0]++;
		if (Dir == LEFT)
			snakeX[0]--;
		if (Dir == RIGHT)
			snakeX[0]++;

		if (Dir == UP)
			snake2Y[0]++;
		if (Dir == DOWN)
			snake2Y[0]--;
		if (Dir == LEFT)
			snake2X[0]++;
		if (Dir == RIGHT)
			snake2X[0]--;

		for (int i = 1; i < SnakeLen; i++) {
			Field[snakeY[0]][snakeX[0]] = head;
			if (i % 2 == 1)
				Field[snakeY[i]][snakeX[i]] = tail;
			else
				Field[snakeY[i]][snakeX[i]] = tail2;
		}

		for (int i = 1; i < SnakeLen; i++) {
			Field[snake2Y[0]][snake2X[0]] = head;
			if (i % 2 == 1)
				Field[snake2Y[i]][snake2X[i]] = tail;
			else
				Field[snake2Y[i]][snake2X[i]] = tail2;
		}
		Logic2();
		PrintField();
		for (int i = 0; i < SnakeLen; i++) {
			Field[snakeY[i]][snakeX[i]] = ' ';
		}
		for (int i = 0; i < SnakeLen; i++) {
			Field[snake2Y[i]][snake2X[i]] = ' ';
		}
		this_thread::sleep_for(chrono::milliseconds(250));
	}

}

void symmetricMode() {
	CreateField();
	PrintField();
	move2();
}