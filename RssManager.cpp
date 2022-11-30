#include "RssManager.h"
#include <iostream>

RssManager::RssManager() {
	refresh();
}

void RssManager::refresh() {
	migrate();
	map<string, string>::iterator it = urlToFilename.begin();
	while (it != urlToFilename.end()) {
		xml_document document;
		document.load_file(it->second.c_str());
		for (xml_node child : document.child("rss").child("channel").children()) {
			if ("item" == string(child.name())) {
				uniqueItems.insert(Item(child));
			}
		}
		it++;
	}
}

unordered_set<Item, Item::Hasher> RssManager::getItems()
{
	return uniqueItems;
}

unordered_set<Item, Item::Hasher> RssManager::getActualItems()
{
	refresh();
	return uniqueItems;
}