

#include "chip8.h"
#include <iostream>
#include <fstream>

const unsigned int FONTSET_SIZE = 80;

uint8_t fontset[FONTSET_SIZE] =
{
	0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

void Chip8::initialize() {
	// program starts here
	pc = START_ADDRESS;

	for (int i = 0; i < FONTSET_SIZE; i++) {
		memory[i] = fontset[i];
	}
}

void Chip8::loadRom(char *fileName) {
	// opens file in binary mode, set initial psition to end of file
	std::ifstream file(fileName, std::ios::binary | std::ios::ate);

	if (file.is_open()) {
		// get size of file by getting position of final character
		std::streampos size = file.tellg();

		// create buffer to fit file
		char* buffer = new char[size];

		file.seekg(0, std::ios::beg);
		file.read(buffer, size);
		file.close();

		// load program contents into emulated memory
		for (int i = 0; i < size; i++) {
			memory[START_ADDRESS + i] = buffer[i];
			printf("%x\n", buffer[i]);
		}

		for (int i = 0; i < FONTSET_SIZE; i++) {
			memory[i] = fontset[i];
		}

		delete[] buffer;
	} else {
		std::cerr << "File " << fileName << " could not be opened\n";
		std::cerr << "Error code: " << strerror(errno) << "\n";
	}
}

void Chip8::emulateCycle() {

}
