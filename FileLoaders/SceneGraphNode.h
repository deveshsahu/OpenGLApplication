#pragma once
#include <string>

namespace sg
{
	class Node
	{
	public:
		Node(const std::string& name) : mName(name) {}
		virtual ~Node() {}

	private:
		std::string mName;
	};
}