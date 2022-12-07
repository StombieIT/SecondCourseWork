#include "Outputer.h"
#include "JsonFormatter.h"
#include <fstream>

Outputer::Outputer(Configuration& config, ostream& consoleStream)
	: RssManager(config), consoleStream(consoleStream) {
	for (pair<string, string> filenameToFormat : config.getOutputs()) {
		if (filenameToFormat.second == "json") {
			Formatter* formatter = new JsonFormatter();
			outputs.insert({ filenameToFormat.first, formatter });
		}
	}
}

void Outputer::migrate() {
	refresh();
	for (pair<string, Formatter*> output : outputs) {
		ofstream out(output.first);
		out << output.second->format(getItems()) << endl;
		out.close();
	}
	JsonFormatter formatter;
	consoleStream << formatter.format(getItems()) << endl;
}

void Outputer::migrateByKeyword(string keyword) {
	refresh();
	for (pair<string, Formatter*> output : outputs) {
		ofstream out(output.first);
		out << output.second->format(getItemsByKeyword(keyword)) << endl;
		out.close();
	}
	JsonFormatter formatter;
	consoleStream << formatter.format(getItemsByKeyword(keyword)) << endl;
}

Outputer::~Outputer() {
	for (pair<string, Formatter*> output : outputs) {
		delete output.second;
	}
}