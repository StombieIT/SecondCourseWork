#pragma once
#include <string>
#include <map>

using namespace std;

class HttpMigrator {
private:
	void makeRequestAndSaveResponse(const char* url, const char* file_name);
protected:
	map<string, string> urlToFilename;
	void migrate();
public:
	HttpMigrator();
	void addDependency(string url, string filename);
	~HttpMigrator();
};