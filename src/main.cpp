
#include "chip8.h"
#include "System.h"
#include "SDL.h"
#include <stdio.h>

Chip8 chip8;
bool quit = false;
char* TITLE = "Chip-8 Emulator";

System setupSystem(int widthScale, int heightScale) {
	// perform SDL setup here
	return System(TITLE, widthScale, heightScale);
}

int main(int argc, char **argv) {
	System system = setupSystem(5, 5);

	while (!quit) {
		quit = system.processInput(chip8.keypad);
	}

	chip8.initialize();
	chip8.loadRom("Roms/pong2.c8");
	return 0;
}
