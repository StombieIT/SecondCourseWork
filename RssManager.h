#pragma once
#include <unordered_set>
#include "Title.h"
#include "HttpMigrator.h"
#include "Item.h"

class RssManager : public HttpMigrator {
private:
	unordered_set<Item, Item::Hasher> uniqueItems;
public:
	RssManager();
	void refresh();
	unordered_set<Item, Item::Hasher> getItems();
	unordered_set<Item, Item::Hasher> getActualItems();
};