#pragma once

#include <SDL.h>

class System {
public:
	System(char *title, int widthScale, int heightScale);
	~System();
	void update();
	bool processInput(uint8_t *keypad);

private:
	SDL_Window* window{};
	SDL_Surface* surface{};
};