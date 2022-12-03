#pragma once
#include <string>
#include <map>

using namespace std;

class HttpRequester {
public:
	HttpRequester();
	void makeRequestAndSaveResponse(string url, string filename);
};