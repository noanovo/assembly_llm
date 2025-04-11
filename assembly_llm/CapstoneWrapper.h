#ifndef CAPSTONEWRAPPER_H
#define CAPSTONEWRAPPER_H

#include <capstone/capstone.h>
#include <vector>
#include <string>
#include <stdexcept>

class CapstoneWrapper {
public:
	// Constructor that initializes Capstone with the given architecture and mode.
	CapstoneWrapper(cs_arch arch, cs_mode mode);

	// Destructor to clean up the Capstone handle.
	~CapstoneWrapper();

	// Disassemble a block of raw machine code.
	// Returns a list of disassembled instructions.
	std::vector<std::string> disassemble(const uint8_t* code, size_t size, uint64_t address);

private:
	csh handle;  // Capstone handle
	bool initialized;  // Track whether Capstone was successfully initialized
};

#endif // CAPSTONEWRAPPER_H
