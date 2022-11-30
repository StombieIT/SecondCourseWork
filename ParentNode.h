#pragma once
#include <vector>
#include <string>
#include "Node.h"

template<class T>
class ParentNode : public Node<vector<Node<T>>> {
	ParentNode();
};
