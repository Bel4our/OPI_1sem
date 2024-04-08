
#include <SFML/Graphics.hpp>
#include "game_core.h"

using namespace sf;

int width = 30, height = 30;
int screen = 25;

int main() {
	RenderWindow* window = new RenderWindow(VideoMode(screen * width, screen * height), "Snake!");
	TGameCore WINDOW;
	WINDOW.open(window);
}