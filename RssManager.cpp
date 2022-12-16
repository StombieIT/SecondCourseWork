#include "RssManager.h"
#include "Configuration.h"
#include <iostream>
#include <algorithm>

using std::thread;
using pugi::xml_document;

RssManager::RssManager(Configuration& config) {
	filenameToUrl = config.getDependencies();
	refresh();
}

void RssManager::refresh() {
	map<string, string>::iterator it = filenameToUrl.begin();
	vector<thread> threads;
	while (it != filenameToUrl.end()) {
		string filename = it->first;
		string url = it->second;
		threads.push_back(thread([this, url, filename]() {
			makeRequestAndSaveResponse(url, filename);
			xml_document document;
			document.load_file(filename.c_str());
			for (xml_node child : document.child("rss").child("channel").children()) {
				if ("item" == string(child.name())) {
					addItem(Item(child));
				}
			}
		}));
		it++;
	}
	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
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
	for (Item item : getItems()) {
		if (item.getTitle().includes(tag)) {
			itemsByKeyword.insert(item);
		}
	}
	return itemsByKeyword;
}

unordered_set<Item, Item::Hasher> RssManager::getActualItemsByKeyword(string tag)
{
	refresh();
	return getItemsByKeyword(tag);
}

RssManager::~RssManager() {
	map<string, string>::iterator it = filenameToUrl.begin();
	while (it != filenameToUrl.end()) {
		remove(it->first.c_str());
		it++;
	}
}

void RssManager::addItem(Item item) {
	itemsLock.lock();
	items.insert(item);
	itemsLock.unlock();
}