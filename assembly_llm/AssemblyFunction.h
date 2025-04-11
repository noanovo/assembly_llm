#include <string>
#include <vector>
#include "AssemblyLine.h"

class AssemblyFunction
{
public:
	std::string name;
	size_t address;
	std::vector<std::string> actions;
	std::string description;
	std::vector<AssemblyLine> assemblyLines;

	AssemblyFunction(std::string name, size_t address);
	void addAction(const std::string& action);
	void setDescription(const std::string& desc);
	void addAssemblyLine(const AssemblyLine& line);
};

