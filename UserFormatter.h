#pragma once
#include "Formatter.h"

class UserFormatter : public Formatter {
private:
	static int INDENTATION_LENGTH;
public:
	string format(unordered_set<Item, Item::Hasher> items);
};