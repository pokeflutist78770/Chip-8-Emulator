

#include "System.h"
#include <SDL.h>
#include <iostream>

int WINDOW_HEIGHT = 32;
int WINDOW_WIDTH = 64;

System::System(char *title, int widthScale, int heightScale) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	window = SDL_CreateWindow("Chip-8 Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH * widthScale, WINDOW_HEIGHT * heightScale , 0);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
		SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
}

System::~System() {
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void System::update() {

}

bool System::processInput(uint8_t *keypad) {
	SDL_Event e;
	bool quit = false;
	while (SDL_PollEvent(&e) != 0) {
		switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
					case SDLK_1:
						keypad[0] = 1;
						break;
					case SDLK_2:
						keypad[1] = 1;
						break;
					case SDLK_3:
						keypad[2] = 1;
						break;
					case SDLK_4:
						keypad[3] = 1;
						break;
					case SDLK_q:
						keypad[4] = 1;
						break;
					case SDLK_w:
						keypad[5] = 1;
						break;
					case SDLK_e:
						keypad[6] = 1;
						break;
					case SDLK_r:
						keypad[7] = 1;
						break;
					case SDLK_a:
						keypad[8] = 1;
						break;
					case SDLK_s:
						keypad[9] = 1;
						break;
					case SDLK_d:
						keypad[10] = 1;
						break;
					case SDLK_f:
						keypad[11] = 1;
						break;
					case SDLK_z:
						keypad[12] = 1;
						break;
					case SDLK_x:
						keypad[13] = 1;
						break;
					case SDLK_c:
						keypad[14] = 1;
						break;
					case SDLK_v:
						keypad[15] = 1;
						break;
				}
			// reset once key is not pressed no more
			case SDL_KEYUP:
				switch (e.key.keysym.sym) {
				case SDLK_1:
					keypad[0] = 0;
					break;
				case SDLK_2:
					keypad[1] = 0;
					break;
				case SDLK_3:
					keypad[2] = 0;
					break;
				case SDLK_4:
					keypad[3] = 0;
					break;
				case SDLK_q:
					keypad[4] = 0;
					break;
				case SDLK_w:
					keypad[5] = 0;
					break;
				case SDLK_e:
					keypad[6] = 0;
					break;
				case SDLK_r:
					keypad[7] = 0;
					break;
				case SDLK_a:
					keypad[8] = 0;
					break;
				case SDLK_s:
					keypad[9] = 0;
					break;
				case SDLK_d:
					keypad[10] = 0;
					break;
				case SDLK_f:
					keypad[11] = 0;
					break;
				case SDLK_z:
					keypad[12] = 0;
					break;
				case SDLK_x:
					keypad[13] = 0;
					break;
				case SDLK_c:
					keypad[14] = 0;
					break;
				case SDLK_v:
					keypad[15] = 0;
					break;
				}
				break;
		}
	}

	return quit;
}
