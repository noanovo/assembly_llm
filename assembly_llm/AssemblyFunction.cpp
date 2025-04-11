#include "AssemblyFunction.h"

AssemblyFunction::AssemblyFunction(std::string name, size_t address)
	: name(name), address(address)
{
}

void AssemblyFunction::addAction(const std::string& action)
{
	actions.push_back(action);
}

void AssemblyFunction::setDescription(const std::string& desc)
{
	description = desc;
}

void AssemblyFunction::addAssemblyLine(const AssemblyLine& line)
{
	assemblyLines.push_back(line);
}
