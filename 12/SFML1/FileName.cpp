#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;

int width = 30, height = 30;
int screen = 25;
int  tempX, tempY;

int snakeLength = 4;
int tickCounter = 0;
bool gameOver = false;
bool isDirectionChanged = false;
bool IsBotPlaying = false;

enum Tdirection { DOWN, LEFT, RIGHT, UP };
Tdirection direction = DOWN;

struct Snake {
	int x, y;
}sn[600];

struct Fruit
{
	int x, y;
}food;

void Tick() {
	for (int i = snakeLength; i > 0; i--){
		sn[i].x = sn[i - 1].x;
		sn[i].y = sn[i - 1].y;
	}

	(direction == UP) ? sn[0].y -= 1 : false;
	(direction == LEFT) ? sn[0].x -= 1 : false;
	(direction == DOWN) ? sn[0].y += 1 : false;
	(direction == RIGHT) ? sn[0].x += 1 : false;

	(sn[0].x >= width) ? sn[0].x = 0 : false;
	(sn[0].x < 0) ? sn[0].x = width-1 : false;
	(sn[0].y >= height) ? sn[0].y = 0 : false;
	(sn[0].y < 0) ? sn[0].y = height-1 : false;

	if ((sn[0].x == food.x) && (sn[0].y == food.y)) {
		snakeLength++; 
		for (int i = 0; i < snakeLength; i++)
			while (food.x == sn[i].x && food.y == sn[i].y) {
				food.x = rand() % width;
				food.y = rand() % height;
			}
	}

	for (int i = 1; i < snakeLength; i++){
		((sn[0].x == sn[i].x) && (sn[0].y == sn[i].y)) ? gameOver = true : false;
	}
}

void ai() {
	if (sn[0].x - 1 != sn[1].x) {
		(sn[0].x < food.x && !isDirectionChanged && direction != LEFT) ? direction = RIGHT, isDirectionChanged = true : false;
	}
	if (sn[0].x + 1 != sn[1].x) {
		(sn[0].x > food.x && !isDirectionChanged && direction != RIGHT) ? direction = LEFT, isDirectionChanged = true : false;
	}
	if (sn[0].y - 1 != sn[1].y) {
		(sn[0].y < food.y && !isDirectionChanged && direction != UP) ? direction = DOWN, isDirectionChanged = true : false;
	}
	if (sn[0].y + 1 != sn[1].y) {
		(sn[0].y > food.y && !isDirectionChanged && direction != DOWN) ? direction = UP, isDirectionChanged = true : false;
	}
}

int main() {
	srand(time(NULL));

	RenderWindow window(VideoMode(screen * width, screen * height), "Snake!");

	Texture tile;
	tile.loadFromFile("tiles.png");
	Sprite tiles(tile);

	Texture snake;
	snake.loadFromFile("snake.png");
	Sprite Snake(snake);

	Texture apple;
	apple .loadFromFile("apple.png");
	Sprite apples(apple);

	Texture gameOverText;
	gameOverText.loadFromFile("gameover.png");
	Sprite gameOverTextSprite(gameOverText);
	gameOverTextSprite.scale(0.4, 0.4);

	food.x = rand() % 15;
	food.y = rand() % 15;

	Clock clock;
	float timer = 0, delay = 0.1;

	while (window.isOpen()) {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed && !isDirectionChanged) {
				(event.key.code == Keyboard::Key::W && direction != DOWN) ? direction = UP, isDirectionChanged = true : false;
				(event.key.code == Keyboard::Key::A && direction != RIGHT) ? direction = LEFT, isDirectionChanged = true : false;
				(event.key.code == Keyboard::Key::S && direction != UP) ? direction = DOWN, isDirectionChanged = true : false;
				(event.key.code == Keyboard::Key::D && direction != LEFT) ? direction = RIGHT, isDirectionChanged = true : false;
				(event.key.code == Keyboard::Key::R && gameOver) ?  gameOver = false, snakeLength = 4, IsBotPlaying = false : false;
				(event.key.code == Keyboard::Key::I && !gameOver && !IsBotPlaying) ? IsBotPlaying = true, tickCounter = 0 : false;
				(event.key.code == Keyboard::Key::I && !gameOver && IsBotPlaying && tickCounter > 0) ? IsBotPlaying = false : false;
			}
		}
		if (timer > delay && !gameOver) {
			timer = 0;
			if(IsBotPlaying) {
				ai();
			}
			Tick();
			tickCounter++;
			isDirectionChanged = false;
		}

		window.clear(Color(50, 50, 50));

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				tiles.setPosition(i * screen, j * screen);
				window.draw(tiles);
			}
		}

		apples.setPosition(food.x * screen, food.y * screen);
		window.draw(apples);

		for (int i = 0; i < snakeLength; i++) {
			(i != 0) ? Snake.setTextureRect(IntRect(0, 0, screen, screen)) : Snake.setTextureRect(IntRect(direction * screen, screen, screen, screen));
			if (gameOver && i == 1) { 
				Snake.setTextureRect(IntRect(direction * screen, screen * 2, screen, screen)); 
			}
			Snake.setPosition(sn[i].x * screen, sn[i].y * screen);
			window.draw(Snake);
		}

		if (gameOver) { 
			gameOverTextSprite.setPosition(0, height / 2);
			window.draw(gameOverTextSprite); 
		}

		window.display();
	}

	return 0;
}