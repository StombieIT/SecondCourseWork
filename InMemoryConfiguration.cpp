#include "InMemoryConfiguration.h"

void InMemoryConfiguration::addDependency(string url, string filename) {
	dependencies[url] = filename;
}

map<string, string> InMemoryConfiguration::getDependencies() {
	return dependencies;
}