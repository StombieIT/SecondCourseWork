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
	string word;
	while (true) {
		cout << "Enter keyword (or enter 'e' to exit program): " << endl;
		cin >> word;
		if (word == "e") {
			break;
		}
		outputer.migrateByKeyword(word);
	}
}