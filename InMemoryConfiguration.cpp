#include "InMemoryConfiguration.h"

void InMemoryConfiguration::addDependency(string url, string filename) {
	dependencies[url] = filename;
}

void InMemoryConfiguration::addOutput(string filename, string format) {
	outputs[filename] = format;
}

map<string, string> InMemoryConfiguration::getDependencies() {
	return dependencies;
}

map<string, string> InMemoryConfiguration::getOutputs() {
	return outputs;
}
