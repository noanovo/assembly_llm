#include <string>
#include <vector>

class AssemblyLine
{
public:
	std::string line;
	size_t address;
	std::vector<std::string> operators;
	std::vector<size_t> accessedAddresses;
	std::vector<std::string> accessedApi;

	AssemblyLine(std::string line, size_t address);
	void addOperator(const std::string& op);
	void addAccessedAddress(size_t addr);
	void addAccessedApi(const std::string& api);
};

