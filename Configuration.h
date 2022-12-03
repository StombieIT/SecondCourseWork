#pragma once
#include <map>
#include <string>

using namespace std;

class Configuration {
public:
	virtual map<string, string> getDependencies() = 0;
};