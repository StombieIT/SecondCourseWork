#include <iostream>
#include "pugixml.hpp"
#include "HttpMigrator.h"
#include <curl/curl.h>
#include "Title.h"
#include "RssManager.h"
#include "InMemoryConfiguration.h"

using namespace std;
using namespace pugi;

int main()
{
	setlocale(LC_ALL, "Russian");
	InMemoryConfiguration config = InMemoryConfigurationBuilder()
		.addDependency("https://www.theguardian.com/uk/rss", "theguardian.xml")
		.addDependency("https://rss.nytimes.com/services/xml/rss/nyt/HomePage.xml", "times.xml")
		.addDependency("https://lenta.ru/rss", "lenta.xml")
		.build();
	RssManager manager(config);
	string inp;
	cin >> inp;
	auto items = manager.getActualItems();
	for (Item item : items) {
		cout << "--------------------------------------" << endl;
		cout << "Title: " << item.getTitle().getTextContent() << endl;
		cout << "Description: " << item.getDescription().getTextContent() << endl;
		cout << "URL: " << item.getLink().getTextContent() << endl;
	}
}