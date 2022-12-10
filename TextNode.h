#pragma once
#include <string>
#include <pugixml.hpp>

using std::string;

class TextNode {
protected:
	string textContent;
public:
	TextNode(string textContent);
	string getTextContent();
};
