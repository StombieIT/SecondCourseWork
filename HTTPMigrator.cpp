#include "HTTPMigrator.h"
#include <curl/curl.h>

HTTPMigrator::HTTPMigrator() {
}

void HTTPMigrator::addDependency(string url, string filename) {
    urlToFilename[url] = filename;
}

void HTTPMigrator::migrate() {
    map<string, string>::iterator it = urlToFilename.begin();
    while (it != urlToFilename.end()) {
        makeRequestAndSaveResponse(it->first.c_str(), it->second.c_str());
        it++;
    }
}

void HTTPMigrator::makeRequestAndSaveResponse(const char* url, const char* file_name) {
    CURL* easyhandle = curl_easy_init();
    curl_easy_setopt(easyhandle, CURLOPT_URL, url);
    FILE* file;
    fopen_s(&file, file_name, "w");
    curl_easy_setopt(easyhandle, CURLOPT_WRITEDATA, file);
    curl_easy_perform(easyhandle);
    curl_easy_cleanup(easyhandle);
    fclose(file);
}

HTTPMigrator::~HTTPMigrator() {
    map<string, string>::iterator it = urlToFilename.begin();
    while (it != urlToFilename.end()) {
        std::remove(it->second.c_str());
        it++;
    }
}