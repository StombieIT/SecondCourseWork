#pragma once
#include "Formatter.h"

class CsvFormatter : public Formatter {
public:
	string format(unordered_set<Item, Item::Hasher> items);
};
