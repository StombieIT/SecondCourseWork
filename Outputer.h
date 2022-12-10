#pragma once
#include <ostream>
#include "Formatter.h"
#include <map>
#include "RssManager.h"

using std::ostream;

class Outputer : public RssManager {
private:
	ostream& consoleStream;
	map<string, Formatter*> outputs;
public:
	Outputer(Configuration& config, ostream& consoleStream);
	void migrate();
	void migrateByKeyword(string keyword);
	~Outputer();
};