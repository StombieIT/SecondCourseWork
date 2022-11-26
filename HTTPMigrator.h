#pragma once
#include <string>
#include <map>

using namespace std;

class HTTPMigrator {
private:
	map<string, string> urlToFilename;
	void makeRequestAndSaveResponse(const char* url, const char* file_name);
public:
	HTTPMigrator();
	void addDependency(string url, string filename);
	void migrate();
	~HTTPMigrator();
};