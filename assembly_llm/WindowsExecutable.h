#include <string>
#include <vector>
#include "Aeroblast.h"

class WindowsExecutable {
public:
	WindowsExecutable(const std::string& exePath, const std::string& apiKey);
	bool analyzeExecutable();
	void displayFunctionClassifications();

private:
	std::string exePath;
	std::string apiKey;
	Aeroblast aeroblast;
	std::vector<std::string> functions;

	bool disassembleExecutable();
	void classifyFunctions();
};
