#pragma once
#include "Configuration.h"

class InMemoryConfiguration : public Configuration {
private:
	map<string, string> dependencies;
public:
	void addDependency(string url, string filename);
	map<string, string> getDependencies();
};

class InMemoryConfigurationBuilder {
private:
	InMemoryConfiguration config;
public:
	InMemoryConfigurationBuilder addDependency(string url, string filename);
	InMemoryConfiguration build();
};