
/**
	Handles all CHIP-8 logic.


	Memory
	--------------------------------------------------------------------------------
	Chip-8 has 8-bit 4096 memory locations allocated as such:
		0x000 - 0x200 : CHIP-8 interpreter itself, font set in emu    (512 bytes)
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
public class Chip8 {
public:
	void initialize();
	void emulateCycle();

private:
	// memory and registers
	unsigned char memory[4096];
	unsigned char V[16];

	// display 
	unsigned char screen[64 * 32];

	// keypad (HEX based 0x0 - 0xF)
	unsigned char key[16];

	// stack
	unsigned short stack[16];
	unsigned short stack_ptr;

	// timers
	unsigned char delay_timer;
	unsigned char sound_timer;

	unsigned short I;
	unsigned short pc;
	unsigned short opcode;

};