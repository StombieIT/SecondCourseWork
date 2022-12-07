#include <iostream>
#include "pugixml.hpp"
#include <curl/curl.h>
#include "Title.h"
#include "RssManager.h"
#include "XmlConfiguration.h"
#include "JsonFormatter.h"
#include "Outputer.h"
#include <fstream>

using namespace std;
using namespace pugi;

int main()
{
	setlocale(LC_ALL, "ru");
	XmlConfiguration config("config.xml");
	Outputer outputer(config, cout);
	string inp;
	while (true) {
		cout << "Enter keyword: " << endl;
		cin >> inp;
		if (inp == "e") {
			break;
		}
		outputer.migrateByKeyword(inp);
	}
}