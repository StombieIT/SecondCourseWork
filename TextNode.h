#pragma once
#include <string>
#include <pugixml.hpp>

using namespace std;
using namespace pugi;

class TextNode {
protected:
	string textContent;
public:
	TextNode(string textContent);
	string getTextContent();
};
