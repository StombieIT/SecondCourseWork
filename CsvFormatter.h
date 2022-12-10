#pragma once
#include "Formatter.h"

class CsvFormatter : public Formatter {
private:
	static string FIELD_SEPARATOR;
public:
	string format(unordered_set<Item, Item::Hasher> items);
};
