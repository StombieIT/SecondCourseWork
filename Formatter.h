#pragma once
#include <string>
#include <unordered_set>
#include "Item.h"

using std::string;
using std::unordered_set;

class Formatter {
public:
	virtual string format(unordered_set<Item, Item::Hasher> items) = 0;
	string normalize(string str);
};