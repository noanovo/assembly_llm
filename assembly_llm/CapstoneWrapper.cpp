#include "CapstoneWrapper.h"
#include <iostream>
#include <sstream>

CapstoneWrapper::CapstoneWrapper(cs_arch arch, cs_mode mode)
	: initialized(false) {
	// Initialize Capstone
	if (cs_open(arch, mode, &handle) != CS_ERR_OK) {
		throw std::runtime_error("Failed to initialize Capstone");
	}
	initialized = true;
}

CapstoneWrapper::~CapstoneWrapper() {
	if (initialized) {
		cs_close(&handle);
	}
}

std::vector<std::string> CapstoneWrapper::disassemble(const uint8_t* code, size_t size, uint64_t address) {
	std::vector<std::string> instructions;

	// Disassemble the code
	cs_insn* insn;
	size_t count = cs_disasm(handle, code, size, address, 0, &insn);
	if (count > 0) {
		// Loop through the instructions and store them as strings
		for (size_t i = 0; i < count; i++) {
			std::stringstream ss;
			ss << "0x" << std::hex << insn[i].address << ": "
				<< insn[i].mnemonic << " " << insn[i].op_str;
			instructions.push_back(ss.str());
		}
		cs_free(insn, count);
	}
	else {
		std::cerr << "Disassembly failed!" << std::endl;
	}

	return instructions;
}
