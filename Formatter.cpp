#include "Formatter.h"
#include <algorithm>

using std::find_if;

string Formatter::normalize(string str) {
    str.erase(str.begin(), find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    str.erase(find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
    replace(str.begin(), str.end(), '"', '\'');
    return str;
}