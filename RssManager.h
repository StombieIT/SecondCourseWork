#pragma once
#include <unordered_set>
#include "Title.h"
#include "HttpMigrator.h"
#include "Item.h"
#include "Configuration.h"

class RssManager : public HttpMigrator {
private:
	map<string, string> urlToFilename;
	unordered_set<Item, Item::Hasher> items;
public:
	RssManager(Configuration& config);
	void refresh();
	unordered_set<Item, Item::Hasher> getItems();
	unordered_set<Item, Item::Hasher> getActualItems();
	unordered_set<Item, Item::Hasher> getItemsByKeyword(string tag);
	~RssManager();
};