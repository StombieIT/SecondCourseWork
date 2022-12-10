#include "XmlConfiguration.h"
#include "pugixml.hpp"

using std::exception;
using pugi::xml_document;
using pugi::xml_node;

XmlConfiguration::XmlConfiguration(string filepath) : FileConfiguration(filepath) {
}

map<string, string> XmlConfiguration::getDependencies() {
	xml_document document;
	document.load_file(filepath.c_str());
	map<string, string> dependencies;
	for (xml_node node : document.child("configuration").child("dependencies").children()) {
		if ("dependency" != string(node.name())) {
			continue;
		}
		string filename = node.child_value("filename");
		string url = node.child_value("url");
		if (dependencies.find(filename) != dependencies.end()) {
			throw exception(("Filename '" + filename + "' already is using").c_str());
		}
		dependencies[filename] = url;
	}
	return dependencies;
}

map<string, string> XmlConfiguration::getOutputs() {
	xml_document document;
	document.load_file(filepath.c_str());
	map<string, string> outputs;
	for (xml_node node : document.child("configuration").child("outputs").children()) {
		if ("output" != string(node.name())) {
			continue;
		}
		string format = node.child_value("format");
		string filename = node.child_value("filename");
		outputs[filename] = format;
	}
	return outputs;
}