#include "XmlConfiguration.h"
#include "pugixml.hpp"

using namespace pugi;

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
		string url = node.child_value("url");
		string filename = node.child_value("filename");
		dependencies[url] = filename;
	}
	return dependencies;
}