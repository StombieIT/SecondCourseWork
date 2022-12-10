#include <iostream>
#include "XmlConfiguration.h"
#include "Outputer.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, "ru");
	XmlConfiguration config("config.xml");
	Outputer outputer(config, cout);
	string inp;
	while (true) {
		cout << "Enter keyword (or enter 'e' to exit program): " << endl;
		cin >> inp;
		if (inp == "e") {
			break;
		}
		outputer.migrateByKeyword(inp);
	}
}