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
	XmlConfiguration config("config.xml");
	RssManager manager(config);
	JsonFormatter formatter;
	string inp;
	while (true) {
		cout << "Enter keyword: " << endl;
		cin >> inp;
		if (inp == "e") {
			break;
		}
		auto items = manager.getItemsByKeyword(inp);
		ofstream out("result.json");
		out << formatter.format(items);
		for (Item item : items) {
			cout << "--------------------------------------" << endl;
			cout << "Title: " << item.getTitle().getTextContent() << endl;
			cout << "Description: " << item.getDescription().getTextContent() << endl;
			cout << "URL: " << item.getLink().getTextContent() << endl;
		}
		out.close();
	}
}