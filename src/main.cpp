
#include "chip8.h"
#include "SDL.h"
#include <stdio.h>

Chip8 chip8;

int main(int argc, char **argv) {
	
	//setupGraphics();
	//setupInput();

	printf("Hello\n");
	chip8.initialize();
	//chip8.loadGame();
	return 0;
}
