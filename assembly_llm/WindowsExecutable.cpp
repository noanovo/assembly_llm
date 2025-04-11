#include "WindowsExecutable.h"
#include <capstone/capstone.h>
#include <iostream>
#include <fstream>
#include <vector>

WindowsExecutable::WindowsExecutable(const std::string& exePath, const std::string& apiKey)
	: exePath(exePath), apiKey(apiKey), aeroblast(apiKey) {
}

bool WindowsExecutable::disassembleExecutable() {
	std::ifstream exeFile(exePath, std::ios::binary | std::ios::ate);
	if (!exeFile.is_open()) {
		std::cerr << "Failed to open EXE file." << std::endl;
		return false;
	}

	std::streamsize size = exeFile.tellg();
	exeFile.seekg(0, std::ios::beg);

	std::vector<char> buffer(size);
	if (!exeFile.read(buffer.data(), size)) {
		std::cerr << "Failed to read EXE file." << std::endl;
		return false;
	}

	csh handle;
	if (cs_open(CS_ARCH_X86, CS_MODE_32, &handle) != CS_ERR_OK) {
		std::cerr << "Capstone initialization failed." << std::endl;
		return false;
	}

	cs_insn* insn;
	size_t count = cs_disasm(handle, reinterpret_cast<uint8_t*>(buffer.data()), buffer.size(), 0, 0, &insn);
	if (count <= 0) {
		std::cerr << "Failed to disassemble." << std::endl;
		cs_close(&handle);
		return false;
	}

	for (size_t i = 0; i < count; i++) {
		if (std::string(insn[i].mnemonic).find("call") != std::string::npos) {
			functions.push_back("Function call at address 0x" + std::to_string(insn[i].address));
		}
	}

	cs_free(insn, count);
	cs_close(&handle);
	return true;
}

void WindowsExecutable::classifyFunctions() {
	for (const auto& function : functions) {
		std::string classification = aeroblast.classify(function);
		std::cout << "Function: " << function << "\nClassification: " << classification << std::endl;
	}
}

bool WindowsExecutable::analyzeExecutable() {
	if (!disassembleExecutable()) {
		std::cerr << "Failed to disassemble EXE." << std::endl;
		return false;
	}
	classifyFunctions();
	return true;
}

void WindowsExecutable::displayFunctionClassifications() {
	for (const auto& function : functions) {
		std::cout << "Function: " << function << std::endl;
	}
}
