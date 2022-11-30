#pragma once
#include <unordered_set>
#include "Title.h"
#include "HttpMigrator.h"
#include "Item.h"

class RssManager : public HttpMigrator {
private:
	vector<Item> uniqueItems;
public:
	RssManager();
	void refresh();
	vector<Item> getItems();
	vector<Item> getActualItems();
};