#pragma once
#include "Configuration.h"

class FileConfiguration : public Configuration {
protected:
	string filepath;
public:
	FileConfiguration(string filepath);
	virtual map<string, string> getDependencies();
};