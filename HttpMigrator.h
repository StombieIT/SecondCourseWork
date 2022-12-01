#pragma once
#include <string>
#include <map>

using namespace std;

class HttpMigrator {
public:
	HttpMigrator();
	void makeRequestAndSaveResponse(string url, string filename);
};