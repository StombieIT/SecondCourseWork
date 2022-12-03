#pragma once
#include "FileConfiguration.h"

class XmlConfiguration : public FileConfiguration {
public:
	XmlConfiguration(string filepath);
	map<string, string> getDependencies();
};