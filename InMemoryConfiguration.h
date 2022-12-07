#pragma once
#include "Configuration.h"

class InMemoryConfiguration : public Configuration {
private:
	map<string, string> dependencies;
public:
	void addDependency(string url, string filename);
	map<string, string> getDependencies();
};