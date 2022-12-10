#pragma once
#include <string>
#include <map>

using std::string;

class HttpRequester {
public:
	HttpRequester();
	void makeRequestAndSaveResponse(string url, string filename);
};