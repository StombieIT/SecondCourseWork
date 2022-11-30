#include <iostream>
#include "pugixml.hpp"
#include "HttpMigrator.h"
#include <curl/curl.h>
#include "Title.h"
#include "RssManager.h"

using namespace std;
using namespace pugi;

int main()
{
	setlocale(LC_ALL, "ru");
	RssManager manager;
	manager.addDependency("https://www.theguardian.com/uk/rss", "theguardian.xml");
	manager.addDependency("https://rss.nytimes.com/services/xml/rss/nyt/HomePage.xml", "times.xml");
	string inp;
	cin >> inp;
	auto items = manager.getItemsByKeyword(inp);
	for (Item item : items) {
		cout << item.getTitle().getTextContent() << endl;
	}
}