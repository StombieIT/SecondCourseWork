#include "InMemoryConfiguration.h"

void InMemoryConfiguration::addDependency(string url, string filename) {
	dependencies[url] = filename;
}

map<string, string> InMemoryConfiguration::getDependencies() {
	return dependencies;
}

InMemoryConfigurationBuilder InMemoryConfigurationBuilder::addDependency(string url, string filename) {
	config.addDependency(url, filename);
	return *this;
}

InMemoryConfiguration InMemoryConfigurationBuilder::build() {
	return config;
}