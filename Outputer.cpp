#include "Outputer.h"
#include "JsonFormatter.h"
#include "CsvFormatter.h"
#include "UserFormatter.h"
#include <fstream>

using std::pair;
using std::thread;
using std::ofstream;
using std::endl;

Outputer::Outputer(Configuration& config, ostream& consoleStream)
	: RssManager(config), consoleStream(consoleStream) {
	for (pair<string, string> filenameToFormat : config.getOutputs()) {
		Formatter* formatter;
		if (filenameToFormat.second == "json") {
			formatter = new JsonFormatter();
		}
		else if (filenameToFormat.second == "csv") {
			formatter = new CsvFormatter();
		}
		else if (filenameToFormat.second == "user") {
			formatter = new UserFormatter();
		}
		else {
			throw "Invalid format in configuration";
		}
		outputs.insert({ filenameToFormat.first, formatter });
	}
}

void Outputer::migrate() {
	refresh();
	vector<thread> threads;
	for (pair<string, Formatter*> output : outputs) {
		threads.push_back(thread([this, output] () {
			ofstream out(output.first);
			out << output.second->format(getItems()) << endl;
			out.close();
		}));
	}
	threads.push_back(thread([this] () {
		UserFormatter formatter;
		consoleStream << formatter.format(getItems()) << endl;
	}));
	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
}

void Outputer::migrateByKeyword(string keyword) {
	refresh();
	vector<thread> threads;
	for (pair<string, Formatter*> output : outputs) {
		threads.push_back(thread([this, output, keyword] () {
			ofstream out(output.first);
			out << output.second->format(getItemsByKeyword(keyword)) << endl;
			out.close();
		}));
	}
	threads.push_back(thread([this, keyword] () {	
		UserFormatter formatter;
		consoleStream << formatter.format(getItemsByKeyword(keyword)) << endl;
	}));
	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
}

Outputer::~Outputer() {
	for (pair<string, Formatter*> output : outputs) {
		delete output.second;
	}
}