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
	//manager.addDependency("https://www.vedomosti.ru/rss/news", "vedomosti.xml");
	//manager.addDependency("http://news2.ru/rss.php", "news2.xml");
	//manager.addDependency("https://www.trend.az/rss/trend_all_ru.rss", "trend.xml");
	manager.addDependency("https://www.theguardian.com/uk/rss", "theguardian.xml");
	for (Item item : manager.getActualItems()) {
		cout << item.getTitle().getTextContent() << endl;
	}
}