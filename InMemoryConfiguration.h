#pragma once
#include "Configuration.h"

class InMemoryConfiguration : public Configuration {
private:
	map<string, string> dependencies;
	map<string, string> outputs;
public:
	void addDependency(string url, string filename);
	void addOutput(string filename, string format);
	map<string, string> getDependencies();
	map<string, string> getOutputs();
};