#pragma once
#include "Formatter.h"

class JsonFormatter : public Formatter {
public:
	string format(unordered_set<Item, Item::Hasher> items);
};