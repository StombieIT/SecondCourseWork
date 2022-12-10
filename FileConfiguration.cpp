#include "FileConfiguration.h"
#include <fstream>

using std::ifstream;
using std::exception;

FileConfiguration::FileConfiguration(string filepath) {
	this->filepath = filepath;
	ifstream in(filepath);
	if (in.fail()) {
		throw exception(("File '" + filepath + "' does not exist").c_str());
	}
}