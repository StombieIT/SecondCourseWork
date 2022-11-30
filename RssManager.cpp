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
		for (xml_node item : document.child("rss").child("channel").children()) {
			if ("item" == string(item.name())) {
				uniqueItems.push_back(Item(item));
			}
		}
		it++;
	}
}

vector<Item> RssManager::getItems()
{
	return uniqueItems;
}

vector<Item> RssManager::getActualItems()
{
	refresh();
	return uniqueItems;
}