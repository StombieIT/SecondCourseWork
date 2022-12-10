#pragma once
#include <string>
#include <vector>
#include "TextNode.h"

using std::string;
using std::vector;
using pugi::xml_node;

class Title : public TextNode {
private:
	static char KEYWORD_SEPARATOR;
	vector<string> keywords;
public:
	Title();
	Title(xml_node node);
	bool includes(string keyword);
	bool operator==(const Title& title) const;
};
