#pragma once
#include <unordered_set>
#include <mutex>
#include "Title.h"
#include "HttpRequester.h"
#include "Item.h"
#include "Configuration.h"

using std::mutex;
using std::unordered_set;

class RssManager : public HttpRequester {
private:
	mutex itemsLock;
	map<string, string> filenameToUrl;
	unordered_set<Item, Item::Hasher> items;
	void addItem(Item item);
public:
	RssManager(Configuration& config);
	void refresh();
	unordered_set<Item, Item::Hasher> getItems();
	unordered_set<Item, Item::Hasher> getActualItems();
	unordered_set<Item, Item::Hasher> getItemsByKeyword(string tag);
	unordered_set<Item, Item::Hasher> getActualItemsByKeyword(string tag);
	~RssManager();
};