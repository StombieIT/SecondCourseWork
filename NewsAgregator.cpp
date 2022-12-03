#include <iostream>
#include "pugixml.hpp"
#include "HttpMigrator.h"
#include <curl/curl.h>
#include "Title.h"
#include "RssManager.h"
#include "XmlConfiguration.h"
#include <fstream>

using namespace std;
using namespace pugi;

int main()
{
	setlocale(LC_ALL, "ru");
	XmlConfiguration config("config.xml");
	RssManager manager(config);
	ofstream out("result.bin");
	auto items = manager.getItemsByKeyword("Ukraine");
	for (Item item : items) {
		out << "--------------------------------------" << endl;
		out << "Title: " << item.getTitle().getTextContent() << endl;
		out << "Description: " << item.getDescription().getTextContent() << endl;
		out << "URL: " << item.getLink().getTextContent() << endl;
	}
	out.close();
}