#include "AssemblyLine.h"

AssemblyLine::AssemblyLine(std::string line, size_t address)
	: line(line), address(address)
{
}

void AssemblyLine::addOperator(const std::string& op)
{
	operators.push_back(op);
}

void AssemblyLine::addAccessedAddress(size_t addr)
{
	accessedAddresses.push_back(addr);
}

void AssemblyLine::addAccessedApi(const std::string& api)
{
	accessedApi.push_back(api);
}
