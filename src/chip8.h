#pragma once

#include <cstdint>

const int MEMORY_SIZE = 4096;
const int SCREEN_WIDTH = 64;
const int SCREEN_HEIGHT = 32;
const int KEYPAD_SIZE = 16;
const int REGISTER_SIZE = 16;
const int STACK_DEPTH = 16;

/**
	Handles all CHIP-8 logic.


	Memory
	--------------------------------------------------------------------------------
	Chip-8 has 8-bit 4096 memory locations allocated as such:
		0x000 - 0x200 : CHIP-8 interpreter itself, font set in emu    (512 bytes)
		0x200 - 0xE9F : Program memory starts at 0x200
		0xEA0 - 0xEFF : Call stack, internal use, and other variables ( 96 bytes)
		0xF00 - 0xFFF : Display Refresh                               (256 bytes)

	We can utilize the lower 512 bytes as the interpreter will be running
	natively outside of memory space.

	Registers
	--------------------------------------------------------------------------------
	There are 16 8 bit registers, named V0 to VF. VF register is special
	as it doubles as a flag for some instructions (pixel collision) 
	and is also the carry flag for addition.

	Address register I is 12 bits and used for several op codes involving memory
	operations

	Stack
	--------------------------------------------------------------------------------
	original RCA 1802 version allocated 48 bytes for 12 levels of nesting.

	Timers
	--------------------------------------------------------------------------------
	Two timers exist counting down at 60 hertz until they hit zero.
		Delay Timer: timer used for timing events of games. Value can be set and
					 read
		Sound Timer: timer used for sound effects. When its value is non zero,
					 a beeping sound is made.
*/
class Chip8 {
public:
	void initialize();
	void loadRom(char *fileName);
	void emulateCycle();

	// keypad (HEX based 0x0 - 0xF)
	uint8_t keypad[KEYPAD_SIZE];

	// display  (2048 pixels)
	uint8_t screen[SCREEN_WIDTH * SCREEN_HEIGHT];

private:
	// starting address for loading program
	const unsigned int START_ADDRESS = 0x200;

	// memory (4k)
	uint8_t memory[MEMORY_SIZE];

	// Registers (15 and carry)
	uint8_t V[REGISTER_SIZE];

	// stack
	uint16_t stack[STACK_DEPTH];
	uint16_t stackPtr;

	// timers
	uint8_t delayTimer;
	uint8_t soundTimer;

	// Index register : stores memory address for operations
	uint16_t indexRegister;

	// program counter
	uint16_t pc;

	uint16_t opcode;

};
