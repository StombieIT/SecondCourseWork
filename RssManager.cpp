#include "RssManager.h"
#include "Configuration.h"
#include <iostream>
#include <algorithm>

RssManager::RssManager(Configuration& config) {
	urlToFilename = config.getDependencies();
	refresh();
}

void RssManager::refresh() {
	map<string, string>::iterator it = urlToFilename.begin();
	while (it != urlToFilename.end()) {
		string url = it->first;
		string filename = it->second;
		makeRequestAndSaveResponse(url, filename);
		xml_document document;
		document.load_file(filename.c_str());
		for (xml_node child : document.child("rss").child("channel").children()) {
			if ("item" == string(child.name())) {
				items.insert(Item(child));
			}
		}
		it++;
	}
}

unordered_set<Item, Item::Hasher> RssManager::getItems()
{
	return items;
}

unordered_set<Item, Item::Hasher> RssManager::getActualItems()
{
	refresh();
	return items;
}

unordered_set<Item, Item::Hasher> RssManager::getItemsByKeyword(string tag)
{
	unordered_set<Item, Item::Hasher> itemsByKeyword;
	for (Item item : getActualItems()) {
		if (item.getTitle().includes(tag)) {
			itemsByKeyword.insert(item);
		}
	}
	return itemsByKeyword;
}

RssManager::~RssManager() {
	map<string, string>::iterator it = urlToFilename.begin();
	while (it != urlToFilename.end()) {
		remove(it->second.c_str());
		it++;
	}
}