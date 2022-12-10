#include "InMemoryConfiguration.h"

void InMemoryConfiguration::addDependency(string filename, string url) {
	dependencies[filename] = url;
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
