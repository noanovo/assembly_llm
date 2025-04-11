#include <unordered_map>
#include <vector>
#include "AssemblyFunction.h"

class FlowGraph
{
public:
	std::unordered_map<size_t, AssemblyFunction*> functions;
	std::unordered_map<size_t, std::vector<size_t>> edges;

	void addEdge(size_t from, size_t to);
	void addFunction(AssemblyFunction* func);
	std::vector<AssemblyFunction*> getConnectedFunctions(size_t address);
	class Iterator
	{
	private:
		typename std::unordered_map<size_t, AssemblyFunction*>::iterator it;
	public:
		Iterator(typename std::unordered_map<size_t, AssemblyFunction*>::iterator start);
		AssemblyFunction* operator*();
		Iterator& operator++();
		bool operator!=(const Iterator& other);
	};
	Iterator begin();
	Iterator end();
};


