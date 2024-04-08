

#pragma once

#include <iostream>
#include <Windows.h>
#include <thread>
#include <ctime>
#include "globals.h"

void Logic3() {
	srand(time(NULL));

	if (snakeY[0] == HEIGHT - 1 || snakeY[0] == 0 || snakeX[0] == WIDTH - 1 || snakeX[0] == 0)
		GameOver = true;

	for (int i = 1; i <= SnakeLen; i++) {
		if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
			SnakeLen--;
			Field[snakeY[SnakeLen]][snakeX[SnakeLen]] = ' ';
			snakeX[SnakeLen] = 0;
			snakeY[SnakeLen] = 0;
			score -= scoreRatio;
		}
	}

	if (snakeX[0] == FoodX && snakeY[0] == FoodY) {
		SnakeLen++;
		score += 10;
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

	if (score < 0) {
		GameOver = true;
	}
}

void move3() {
	score = 200;
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
		Logic3();
		PrintField();
		for (int i = 0; i < SnakeLen; i++) {
			Field[snakeY[i]][snakeX[i]] = ' ';
		}
		this_thread::sleep_for(chrono::milliseconds(250));
	}

}

void selfEater() {
	CreateField();
	PrintField();
	move3();
}