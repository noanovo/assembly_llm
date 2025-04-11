#include "FlowGraph.h"

void FlowGraph::addEdge(size_t from, size_t to)
{
	edges[from].push_back(to);
}

void FlowGraph::addFunction(AssemblyFunction* func)
{
	functions[func->address] = func;
}

std::vector<AssemblyFunction*> FlowGraph::getConnectedFunctions(size_t address)
{
	std::vector<AssemblyFunction*> connected;
	for (size_t next_address : edges[address]) {
		connected.push_back(functions[next_address]);
	}
	return connected;
}

FlowGraph::Iterator::Iterator(typename std::unordered_map<size_t, AssemblyFunction*>::iterator start) : it(start)
{
}
AssemblyFunction* FlowGraph::Iterator::operator*()
{
	return it->second;
}
FlowGraph::Iterator& FlowGraph::Iterator::operator++()
{
	++it;
	return *this;
}
bool FlowGraph::Iterator::operator!=(const Iterator& other)
{
	return it != other.it;
}
FlowGraph::Iterator FlowGraph::begin()
{
	return Iterator(functions.begin());
}
FlowGraph::Iterator FlowGraph::end()
{
	return Iterator(functions.end());
}
