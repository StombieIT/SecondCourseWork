#include <iostream>
#include "pugixml.hpp"
#include <curl/curl.h>
#include "Title.h"
#include "RssManager.h"
#include "XmlConfiguration.h"
#include "JsonFormatter.h"
#include <fstream>

using namespace std;
using namespace pugi;

int main()
{
	setlocale(LC_ALL, "ru");
	setlocale(LC_CTYPE, "rus");
	XmlConfiguration config("config.xml");
	RssManager manager(config);
	JsonFormatter formatter;
	ofstream out("result.bin");
	auto items = manager.getItems();
	out << formatter.format(items) << endl;
	for (Item item : items) {
		cout << "--------------------------------------" << endl;
		cout << "Title: " << item.getTitle().getTextContent() << endl;
		cout << "Description: " << item.getDescription().getTextContent() << endl;
		cout << "URL: " << item.getLink().getTextContent() << endl;
	}
	out.close();
}