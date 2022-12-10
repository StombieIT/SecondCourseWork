#pragma once
#include <map>
#include <string>

using std::string;
using std::map;

class Configuration {
public:
	virtual map<string, string> getDependencies() = 0;
	virtual map<string, string> getOutputs() = 0;
};