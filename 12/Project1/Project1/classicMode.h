#pragma once

#include <iostream>
#include <Windows.h>
#include <thread>
#include <ctime>
#include "globals.h"

using namespace std;

void Logic1() {
	srand(time(NULL));

	if (snakeY[0] == HEIGHT - 1 || snakeY[0] == 0 || snakeX[0] == WIDTH - 1 || snakeX[0] == 0)
		GameOver = true;

	for (int i = 1; i <= SnakeLen; i++) {
		if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
			GameOver = true;
		}
	}

	if (snakeX[0] == FoodX && snakeY[0] == FoodY) {
		Chance = rand() % 21;
		if (Chance <= 2) {
			BonusX = rand() % (HEIGHT - 3) + 2;
			BonusY = rand() % (WIDTH - 3) + 2;
			Field[BonusY][BonusX] = Bonus;
		}
		SnakeLen++;
		for (int i = 0; i <= SnakeLen; i++) {
			if (FoodX == snakeX[i] && FoodY == snakeY[i]) {
				FoodY = rand() % (HEIGHT - 3) + 2;
				FoodX = rand() % (WIDTH - 3) + 2;
				Field[FoodY][FoodX] = Food;
				PrintField();
			}
			else
				break;
		}
	}
	if (snakeX[0] == BonusX && snakeY[0] == BonusY) {
		SnakeLen += 3;
	}

	score = (SnakeLen - 3) * 10;
}


void move() {
	Dir = DOWN;
	snakeX[0] = 10;
	snakeY[0] = 5;

	Chance = 10;
	FoodX = rand() % (WIDTH - 3) + 2;
	FoodY = rand() % (HEIGHT - 3) + 2;
	Field[FoodY][FoodX] = Food;

	while (!GameOver) {
		controls();

		for (int i = SnakeLen - 2; i >= 0; i--) {
			snakeX[i + 1] = snakeX[i];
			snakeY[i + 1] = snakeY[i];
		}

		if (Dir == UP)
			snakeY[0]--;
		if (Dir == DOWN)
			snakeY[0]++;
		if (Dir == LEFT)
			snakeX[0]--;
		if (Dir == RIGHT)
			snakeX[0]++;

		for (int i = 1; i < SnakeLen; i++) {
			Field[snakeY[0]][snakeX[0]] = head;
			if (i % 2 == 1)
				Field[snakeY[i]][snakeX[i]] = tail;
			else
				Field[snakeY[i]][snakeX[i]] = tail2;
		}
		Logic1();
		PrintField();
		for (int i = 0; i < SnakeLen; i++) {
			Field[snakeY[i]][snakeX[i]] = ' ';
		}
		this_thread::sleep_for(chrono::milliseconds(250));
	}

}

void ClassicMode() {
	CreateField();
	PrintField();
	move();
}