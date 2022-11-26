#pragma once
#include <string>
#include <map>

using namespace std;

class HttpMigrator {
private:
	map<string, string> urlToFilename;
	void makeRequestAndSaveResponse(const char* url, const char* file_name);
public:
	HttpMigrator();
	void addDependency(string url, string filename);
	void migrate();
	~HttpMigrator();
};