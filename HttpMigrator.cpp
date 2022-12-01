#include "HttpMigrator.h"
#include <curl/curl.h>

HttpMigrator::HttpMigrator() {
}

void HttpMigrator::makeRequestAndSaveResponse(string url, string filename) {
    CURL* easyhandle = curl_easy_init();
    curl_easy_setopt(easyhandle, CURLOPT_URL, url.c_str());
    FILE* file;
    fopen_s(&file, filename.c_str(), "w");
    curl_easy_setopt(easyhandle, CURLOPT_WRITEDATA, file);
    curl_easy_perform(easyhandle);
    curl_easy_cleanup(easyhandle);
    fclose(file);
}