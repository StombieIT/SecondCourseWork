#include "FileConfiguration.h"
#include <fstream>

using std::ifstream;

FileConfiguration::FileConfiguration(string filepath) {
	this->filepath = filepath;
}

map<string, string> FileConfiguration::getDependencies() {
	ifstream file(filepath);
	map<string, string> dependencies;
	while (file) {
		string url;
		getline(file, url);
		string filename;
		getline(file, filename);
		dependencies[url] = filename;
	}
	file.close();
	return dependencies;
}