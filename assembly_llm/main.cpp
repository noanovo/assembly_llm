#include <iostream>
#include "WindowsExecutable.h"
#include "Model.h"
#include <capstone/capstone.h>
#include <stdio.h>
#include <inttypes.h>
#include "CapstoneWrapper.h"
#include <vector>

int main()
{
	try {
		// Create a Capstone wrapper for x86 architecture in 64-bit mode
		CapstoneWrapper capstone(CS_ARCH_X86, CS_MODE_64);

		// Example machine code (just an example)
		uint8_t code[] = { 0x55, 0x48, 0x8b, 0x05, 0xb8, 0x13, 0x00, 0x00 };
		size_t size = sizeof(code);
		uint64_t address = 0x1000;  // Example address

		// Disassemble the code
		std::vector<std::string> instructions = capstone.disassemble(code, size, address);

		// Print the disassembled instructions
		for (const auto& instr : instructions) {
			std::cout << instr << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
