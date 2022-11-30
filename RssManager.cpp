#include "RssManager.h"
#include <iostream>
#include <algorithm>

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
